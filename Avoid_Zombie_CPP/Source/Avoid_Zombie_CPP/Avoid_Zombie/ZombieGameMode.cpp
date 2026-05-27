// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieGameMode.h"
#include "ZombieGameState.h"
#include "WaveManager.h"

AZombieGameMode::AZombieGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	GameStateClass = AZombieGameState::StaticClass();
}

void AZombieGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (!WaveManagerClass)
		WaveManagerClass = AWaveManager::StaticClass();
	WaveManager = GetWorld()->SpawnActor<AWaveManager>(WaveManagerClass, FVector::ZeroVector, FRotator::ZeroRotator);
}

void AZombieGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AZombieGameState* GS = GetGameState<AZombieGameState>())
		GS->UpdateElapsedTime(DeltaTime);
}

void AZombieGameMode::OnPlayerDead()
{
	if (AZombieGameState* GS = GetGameState<AZombieGameState>())
		GS->TriggerGameOver();

	if (WaveManager)
		WaveManager->StopWave();
}
