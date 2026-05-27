// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "AvoidZombieGameMode.h"
#include "AvoidZombieGameState.h"
#include "WaveManager.h"
#include "Kismet/GameplayStatics.h"

AAvoidZombieGameMode::AAvoidZombieGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	// 기본 GameState 클래스 설정
	GameStateClass = AAvoidZombieGameState::StaticClass();
}

void AAvoidZombieGameMode::BeginPlay()
{
	Super::BeginPlay();

	// WaveManager 스폰
	if (WaveManagerClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		WaveManager = GetWorld()->SpawnActor<AWaveManager>(WaveManagerClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	}
	else
	{
		// 클래스가 지정되지 않은 경우 기본 C++ 클래스로 스폰
		WaveManager = GetWorld()->SpawnActor<AWaveManager>(AWaveManager::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
	}
}

void AAvoidZombieGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// GameState 플레이 시간 갱신
	if (AAvoidZombieGameState* GS = GetGameState<AAvoidZombieGameState>())
	{
		GS->UpdateElapsedTime(DeltaTime);
	}
}

void AAvoidZombieGameMode::OnPlayerDead()
{
	if (AAvoidZombieGameState* GS = GetGameState<AAvoidZombieGameState>())
	{
		GS->TriggerGameOver();
	}

	// WaveManager 중단
	if (WaveManager)
	{
		WaveManager->StopWave();
	}

	UE_LOG(LogTemp, Warning, TEXT("[GameMode] 플레이어 사망 → 게임 오버"));
}
