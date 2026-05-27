// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "WaveManager.h"
#include "ZombieCharacter.h"
#include "AvoidZombieGameState.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

AWaveManager::AWaveManager()
{
	PrimaryActorTick.bCanEverTick = true;

	// 포탈 8개에 대한 쿨다운 배열 초기화
	PortalOnCooldown.Init(false, 8);
	PortalCooldownTimers.SetNum(8);
}

void AWaveManager::BeginPlay()
{
	Super::BeginPlay();

	// 실제 포탈 수에 맞게 배열 크기 조정
	int32 PortalCount = FMath::Max(Portals.Num(), 8);
	PortalOnCooldown.SetNum(PortalCount);
	PortalCooldownTimers.SetNum(PortalCount);

	// 20초마다 웨이브 시작 타이머 (첫 웨이브는 즉시 시작)
	StartNextWave();
	GetWorld()->GetTimerManager().SetTimer(
		WaveTimerHandle,
		this,
		&AWaveManager::StartNextWave,
		20.f,
		true // 반복
	);
}

void AWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ─── 다음 웨이브 시작 ─────────────────────────────────────────────────────
void AWaveManager::StartNextWave()
{
	CurrentWave++;

	// ─── 웨이브별 스탯 증가 ───────────────────────────────────────
	// 매 2웨이브마다 이동속도 +0.2m/s (20cm/s)
	if (CurrentWave > 1 && (CurrentWave - 1) % 2 == 0)
	{
		CurrentZombieMoveSpeed += 20.f;
	}

	// 매 5웨이브마다 체력 +1
	if (CurrentWave > 1 && (CurrentWave - 1) % 5 == 0)
	{
		CurrentZombieMaxHealth += 1.f;
	}

	// GameState 웨이브 번호 갱신
	if (AAvoidZombieGameState* GS = GetWorld()->GetGameState<AAvoidZombieGameState>())
	{
		GS->CurrentWave = CurrentWave;
	}

	// ─── 스폰 큐 설정 ─────────────────────────────────────────────
	SpawnQueueCount  = GetZombieCountForWave(CurrentWave);
	AliveZombieCount = 0;
	bWaveActive      = true;

	UE_LOG(LogTemp, Warning, TEXT("[Wave] %d웨이브 시작 | 좀비: %d마리 | 속도: %.0fcm/s | 체력: %.0f"),
		CurrentWave, SpawnQueueCount, CurrentZombieMoveSpeed, CurrentZombieMaxHealth);

	// 스폰 큐 처리 타이머 시작
	GetWorld()->GetTimerManager().SetTimer(
		SpawnQueueTimerHandle,
		this,
		&AWaveManager::SpawnOneFromQueue,
		SpawnQueueInterval,
		true // 반복 (큐가 빌 때까지)
	);
}

// ─── 이번 웨이브 스폰 수 계산 ────────────────────────────────────────────
int32 AWaveManager::GetZombieCountForWave(int32 Wave) const
{
	// 1웨이브: 6마리, 이후 매 웨이브 +1 (40웨이브 상한 적용 후 고정)
	const int32 ClampedWave = FMath::Min(Wave, 40);
	return 5 + ClampedWave; // 1웨이브 = 5+1 = 6, 2웨이브 = 7, ...
}

// ─── 스폰 큐에서 1마리 스폰 ──────────────────────────────────────────────
void AWaveManager::SpawnOneFromQueue()
{
	if (SpawnQueueCount <= 0)
	{
		// 큐 소진 → 스폰 타이머 중단
		GetWorld()->GetTimerManager().ClearTimer(SpawnQueueTimerHandle);
		return;
	}

	// 사용 가능한 포탈 찾기
	int32 PortalIdx = GetAvailablePortalIndex();
	if (PortalIdx == -1)
	{
		// 모든 포탈이 쿨다운 중 → 잠시 후 재시도 (타이머 유지)
		return;
	}

	// 포탈 위치에 좀비 스폰
	if (!ZombieClass) return;
	if (!Portals.IsValidIndex(PortalIdx) || !Portals[PortalIdx]) return;

	FVector SpawnLocation = Portals[PortalIdx]->GetActorLocation();
	SpawnLocation.Z += 90.f; // 바닥 위에 위치

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AZombieCharacter* Zombie = GetWorld()->SpawnActor<AZombieCharacter>(
		ZombieClass, SpawnLocation, FRotator::ZeroRotator, Params);

	if (Zombie)
	{
		// 웨이브에 맞는 스탯 설정
		Zombie->MoveSpeed  = CurrentZombieMoveSpeed;
		Zombie->MaxHealth  = CurrentZombieMaxHealth;

		// BeginPlay 이후 이므로 직접 속도도 적용
		if (Zombie->GetCharacterMovement())
		{
			Zombie->GetCharacterMovement()->MaxWalkSpeed = CurrentZombieMoveSpeed;
		}

		// WaveManager 참조 등록 (사망 시 콜백용)
		// ZombieCharacter는 Die()에서 GameState.AddKillScore()를 직접 호출하므로
		// 여기서는 AliveZombieCount만 관리
		AliveZombieCount++;
		SpawnQueueCount--;

		// 포탈 1초 쿨다운 설정
		PortalOnCooldown[PortalIdx] = true;
		FTimerDelegate CooldownDelegate = FTimerDelegate::CreateUObject(
			this, &AWaveManager::ClearPortalCooldown, PortalIdx);
		GetWorld()->GetTimerManager().SetTimer(
			PortalCooldownTimers[PortalIdx], CooldownDelegate, 1.f, false);

		UE_LOG(LogTemp, Log, TEXT("[Wave] 좀비 스폰 (포탈 %d) | 잔여 큐: %d"), PortalIdx, SpawnQueueCount);
	}
}

// ─── 사용 가능한 포탈 인덱스 반환 ────────────────────────────────────────
int32 AWaveManager::GetAvailablePortalIndex() const
{
	// 쿨다운 중이지 않은 포탈만 수집
	TArray<int32> Available;
	for (int32 i = 0; i < Portals.Num(); i++)
	{
		if (!PortalOnCooldown[i] && Portals[i])
		{
			Available.Add(i);
		}
	}

	if (Available.IsEmpty()) return -1;

	// 랜덤 선택
	return Available[FMath::RandRange(0, Available.Num() - 1)];
}

void AWaveManager::ClearPortalCooldown(int32 PortalIndex)
{
	if (PortalOnCooldown.IsValidIndex(PortalIndex))
	{
		PortalOnCooldown[PortalIndex] = false;
	}
}

// ─── 좀비 사망 콜백 ───────────────────────────────────────────────────────
void AWaveManager::OnZombieDead()
{
	AliveZombieCount = FMath::Max(0, AliveZombieCount - 1);

	// 스폰 큐도 비었고 살아있는 좀비도 없으면 웨이브 클리어
	if (SpawnQueueCount <= 0 && AliveZombieCount <= 0 && bWaveActive)
	{
		OnWaveClear();
	}
}

// ─── 웨이브 클리어 ────────────────────────────────────────────────────────
void AWaveManager::OnWaveClear()
{
	bWaveActive = false;

	if (AAvoidZombieGameState* GS = GetWorld()->GetGameState<AAvoidZombieGameState>())
	{
		GS->AddWaveClearScore(CurrentWave);
	}

	UE_LOG(LogTemp, Warning, TEXT("[Wave] %d웨이브 클리어!"), CurrentWave);
}

// ─── 웨이브 중단 (게임 오버 시) ──────────────────────────────────────────
void AWaveManager::StopWave()
{
	bWaveActive = false;
	GetWorld()->GetTimerManager().ClearTimer(WaveTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(SpawnQueueTimerHandle);

	UE_LOG(LogTemp, Warning, TEXT("[Wave] 웨이브 중단 (게임 오버)"));
}
