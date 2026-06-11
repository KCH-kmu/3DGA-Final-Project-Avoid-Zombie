// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "WaveManager.h"
#include "ZombieCharacter.h"
#include "ZombieGameState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AWaveManager::AWaveManager()
{
	PrimaryActorTick.bCanEverTick = false;
	PortalOnCooldown.Init(false, 8);
	PortalCooldownTimers.SetNum(8);
}

void AWaveManager::BeginPlay()
{
	Super::BeginPlay();

	int32 N = FMath::Max(Portals.Num(), 8);
	PortalOnCooldown.SetNum(N);
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

	// GameState 웨이브 갱신 + HUD broadcast
	if (AZombieGameState* GS = GetWorld()->GetGameState<AZombieGameState>())
		GS->SetCurrentWave(CurrentWave);

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
	}
}

int32 AWaveManager::GetAvailablePortalIndex() const
{
	TArray<int32> Available;
	for (int32 i = 0; i < Portals.Num(); i++)
		if (!PortalOnCooldown[i] && Portals[i])
			Available.Add(i);

	if (Available.IsEmpty()) return -1;
	return Available[FMath::RandRange(0, Available.Num() - 1)];
}

void AWaveManager::ClearPortalCooldown(int32 Idx)
{
	if (PortalOnCooldown.IsValidIndex(Idx))
		PortalOnCooldown[Idx] = false;
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

	if (AZombieGameState* GS = GetWorld()->GetGameState<AZombieGameState>())
		GS->AddWaveClearScore(CurrentWave);

	UE_LOG(LogTemp, Warning, TEXT("[Wave] %d웨이브 클리어!"), CurrentWave);
}

void AWaveManager::StopWave()
{
	bWaveActive = false;
	GetWorld()->GetTimerManager().ClearTimer(WaveTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(SpawnQueueTimerHandle);
}
