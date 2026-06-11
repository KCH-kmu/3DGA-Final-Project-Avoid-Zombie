// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieGameMode.h"
#include "ZombieGameState.h"
#include "WaveManager.h"
#include "Kismet/GameplayStatics.h"

AZombieGameMode::AZombieGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	GameStateClass = AZombieGameState::StaticClass();
}

void AZombieGameMode::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("[GameMode] BeginPlay 시작"));
	Super::BeginPlay();

	// 레벨에 있는 WaveManager 전부 수집
	TArray<AActor*> Existing;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaveManager::StaticClass(), Existing);

	UE_LOG(LogTemp, Warning, TEXT("[GameMode] WaveManager 발견 수: %d"), Existing.Num());

	if (Existing.Num() > 0)
	{
		// 첫 번째만 사용, 나머지는 즉시 제거 (중복 방지)
		WaveManager = Cast<AWaveManager>(Existing[0]);
		for (int32 i = 1; i < Existing.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("[GameMode] 중복 WaveManager 제거: %s"), *Existing[i]->GetName());
			Existing[i]->Destroy();
		}
		UE_LOG(LogTemp, Warning, TEXT("[GameMode] WaveManager 재사용: %s"), *WaveManager->GetName());
		return;
	}

	// 하나도 없으면 스폰
	if (!WaveManagerClass)
		WaveManagerClass = AWaveManager::StaticClass();
	WaveManager = GetWorld()->SpawnActor<AWaveManager>(WaveManagerClass, FVector::ZeroVector, FRotator::ZeroRotator);
	UE_LOG(LogTemp, Warning, TEXT("[GameMode] WaveManager 스폰 완료"));
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
