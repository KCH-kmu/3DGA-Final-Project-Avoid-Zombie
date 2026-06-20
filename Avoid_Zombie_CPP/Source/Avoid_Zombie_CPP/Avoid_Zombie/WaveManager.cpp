// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "WaveManager.h"
#include "ZombieCharacter.h"
#include "ZombiePlayerCharacter.h"
#include "ZombieGameState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AWaveManager::AWaveManager()
{
	PrimaryActorTick.bCanEverTick = false;
	PortalOnCooldown.Init(false, 8);
	PortalUsedThisWave.Init(false, 8);
	PortalCooldownTimers.SetNum(8);
}

void AWaveManager::BeginPlay()
{
	Super::BeginPlay();

	int32 N = FMath::Max(Portals.Num(), 8);
	PortalOnCooldown.SetNum(N);
	PortalUsedThisWave.SetNum(N);
	PortalCooldownTimers.SetNum(N);

	// 첫 웨이브 즉시 시작, 이후 20초마다 반복
	StartNextWave();
	GetWorld()->GetTimerManager().SetTimer(
		WaveTimerHandle, this, &AWaveManager::StartNextWave, 20.f, true);
}

void AWaveManager::StartNextWave()
{
	CurrentWave++;

	// ─── 스탯 증가 ────────────────────────────────────────────────
	// 매 2웨이브마다 이동속도 +20cm/s
	if (CurrentWave > 1 && (CurrentWave - 1) % 2 == 0)
		CurrentZombieMoveSpeed += 20.f;

	// 매 5웨이브마다 체력 +1
	if (CurrentWave > 1 && (CurrentWave - 1) % 5 == 0)
		CurrentZombieMaxHealth += 1.f;

	if (AZombieGameState* GS = GetWorld()->GetGameState<AZombieGameState>())
	{
		// 2웨이브부터 이전 웨이브 클리어(생존) 처리: 점수 +100 + 체력 회복
		if (CurrentWave > 1)
		{
			GS->AddWaveClearScore(CurrentWave - 1);
			ApplyWaveClearHeal();
		}

		// GameState 웨이브 번호 갱신 + HUD broadcast
		GS->SetCurrentWave(CurrentWave);
	}

	// 새 웨이브 — 포탈 사용 기록 초기화 (8개 포탈에 골고루 분배)
	for (int32 i = 0; i < PortalUsedThisWave.Num(); i++)
		PortalUsedThisWave[i] = false;

	SpawnQueueCount  = GetZombieCountForWave(CurrentWave);
	AliveZombieCount = 0;
	bWaveActive      = true;

	UE_LOG(LogTemp, Warning, TEXT("[Wave] %d웨이브 시작 | 좀비:%d | 속도:%.0f | 체력:%.0f"),
		CurrentWave, SpawnQueueCount, CurrentZombieMoveSpeed, CurrentZombieMaxHealth);

	GetWorld()->GetTimerManager().SetTimer(
		SpawnQueueTimerHandle, this, &AWaveManager::SpawnOneFromQueue, SpawnQueueInterval, true);
}

int32 AWaveManager::GetZombieCountForWave(int32 Wave) const
{
	// 1웨이브 = 6마리, 매 웨이브 +1, 40웨이브 상한
	return 5 + FMath::Min(Wave, 40);
}

void AWaveManager::SpawnOneFromQueue()
{
	if (SpawnQueueCount <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnQueueTimerHandle);
		return;
	}

	int32 PortalIdx = GetAvailablePortalIndex();
	if (PortalIdx == -1) return; // 모든 포탈 쿨다운 중 → 재시도 대기

	if (!ZombieClass || !Portals.IsValidIndex(PortalIdx) || !Portals[PortalIdx]) return;

	FVector SpawnLoc = Portals[PortalIdx]->GetActorLocation();
	SpawnLoc.Z += 90.f;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AZombieCharacter* Zombie = GetWorld()->SpawnActor<AZombieCharacter>(
		ZombieClass, SpawnLoc, FRotator::ZeroRotator, Params);

	if (Zombie)
	{
		Zombie->MoveSpeed  = CurrentZombieMoveSpeed;
		Zombie->MaxHealth  = CurrentZombieMaxHealth;
		if (Zombie->GetCharacterMovement())
			Zombie->GetCharacterMovement()->MaxWalkSpeed = CurrentZombieMoveSpeed;

		AliveZombieCount++;
		SpawnQueueCount--;

		// 포탈 1초 쿨다운
		PortalOnCooldown[PortalIdx] = true;
		FTimerDelegate D = FTimerDelegate::CreateUObject(
			this, &AWaveManager::ClearPortalCooldown, PortalIdx);
		GetWorld()->GetTimerManager().SetTimer(PortalCooldownTimers[PortalIdx], D, 1.f, false);

		// 이번 웨이브에서 이 포탈 사용됨으로 표시 (안 쓴 포탈 우선 분배용)
		if (PortalUsedThisWave.IsValidIndex(PortalIdx))
			PortalUsedThisWave[PortalIdx] = true;

		// 유효 포탈을 모두 한 번씩 다 썼으면 사이클 리셋 → 긴 웨이브도 계속 골고루 분배
		bool bAllUsed = true;
		for (int32 i = 0; i < Portals.Num(); i++)
			if (Portals[i] && !PortalUsedThisWave[i]) { bAllUsed = false; break; }
		if (bAllUsed)
			for (int32 i = 0; i < PortalUsedThisWave.Num(); i++)
				PortalUsedThisWave[i] = false;
	}
}

int32 AWaveManager::GetAvailablePortalIndex() const
{
	TArray<int32> UnusedAvailable; // 쿨다운 X + 이번 웨이브 미사용
	TArray<int32> AnyAvailable;    // 쿨다운 X (폴백)
	for (int32 i = 0; i < Portals.Num(); i++)
	{
		if (PortalOnCooldown[i] || !Portals[i]) continue;
		AnyAvailable.Add(i);
		if (!PortalUsedThisWave[i])
			UnusedAvailable.Add(i);
	}

	// '생성되지 않은 포탈 먼저', 그 안에서 랜덤. 모두 썼으면 가용 포탈 중 랜덤.
	const TArray<int32>& Pool = (UnusedAvailable.Num() > 0) ? UnusedAvailable : AnyAvailable;
	if (Pool.IsEmpty()) return -1;
	return Pool[FMath::RandRange(0, Pool.Num() - 1)];
}

void AWaveManager::ClearPortalCooldown(int32 Idx)
{
	if (PortalOnCooldown.IsValidIndex(Idx))
		PortalOnCooldown[Idx] = false;
}

void AWaveManager::ApplyWaveClearHeal()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	AZombiePlayerCharacter* Player = Cast<AZombiePlayerCharacter>(PlayerPawn);
	if (!Player || Player->IsDead()) return;

	// 체력 2 회복. 최대치를 넘겨 버려진 양은 1당 OverflowHealScore 점으로 환산.
	const float Overflow = Player->HealHealthOverflow(WaveClearHeal);
	if (Overflow > 0.f)
	{
		const int32 Bonus = FMath::RoundToInt(Overflow) * OverflowHealScore;
		if (AZombieGameState* GS = GetWorld()->GetGameState<AZombieGameState>())
			GS->AddBonusScore(Bonus);
		UE_LOG(LogTemp, Log, TEXT("[Wave] 클리어 회복 초과 %.0f → +%d점"), Overflow, Bonus);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[Wave] 클리어 체력 회복 +%.0f"), WaveClearHeal);
	}
}

void AWaveManager::OnZombieDead()
{
	AliveZombieCount = FMath::Max(0, AliveZombieCount - 1);

	if (SpawnQueueCount <= 0 && AliveZombieCount <= 0 && bWaveActive)
		OnWaveClear();
}

void AWaveManager::OnWaveClear()
{
	bWaveActive = false;
	UE_LOG(LogTemp, Warning, TEXT("[Wave] %d웨이브 좀비 전멸!"), CurrentWave);
}

void AWaveManager::StopWave()
{
	bWaveActive = false;
	GetWorld()->GetTimerManager().ClearTimer(WaveTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(SpawnQueueTimerHandle);
}
