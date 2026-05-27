// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "AvoidZombieGameState.h"
#include "Kismet/GameplayStatics.h"

AAvoidZombieGameState::AAvoidZombieGameState()
{
}

void AAvoidZombieGameState::BeginPlay()
{
	Super::BeginPlay();
}

void AAvoidZombieGameState::UpdateElapsedTime(float DeltaTime)
{
	if (!bIsGameOver)
	{
		ElapsedTime += DeltaTime;
	}
}

void AAvoidZombieGameState::AddKillScore()
{
	TotalKills++;
	// 기본 킬 점수: 킬 * 10
	TotalScore += 10;
}

void AAvoidZombieGameState::AddWaveClearScore(int32 WaveNumber)
{
	// 웨이브 클리어 점수: 웨이브 번호 * 100
	TotalScore += WaveNumber * 100;
}

void AAvoidZombieGameState::AddBonusScore(int32 Bonus)
{
	TotalScore += Bonus;
}

void AAvoidZombieGameState::TriggerGameOver()
{
	if (bIsGameOver) return;

	bIsGameOver = true;
	UE_LOG(LogTemp, Warning, TEXT("[GameState] 게임 오버 - 웨이브: %d | 킬: %d | 점수: %d | 시간: %.1f초"),
		CurrentWave, TotalKills, TotalScore, ElapsedTime);
}
