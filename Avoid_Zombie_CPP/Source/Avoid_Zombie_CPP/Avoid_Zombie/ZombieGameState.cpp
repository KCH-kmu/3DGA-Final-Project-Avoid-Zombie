// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieGameState.h"

AZombieGameState::AZombieGameState() {}

void AZombieGameState::UpdateElapsedTime(float DeltaTime)
{
	if (!bIsGameOver)
		ElapsedTime += DeltaTime;
}

void AZombieGameState::AddKillScore()
{
	TotalKills++;
	TotalScore += 10; // 킬 * 10
}

void AZombieGameState::AddWaveClearScore(int32 WaveNumber)
{
	TotalScore += WaveNumber * 100; // 웨이브 * 100
}

void AZombieGameState::AddBonusScore(int32 Bonus)
{
	TotalScore += Bonus;
}

void AZombieGameState::TriggerGameOver()
{
	if (bIsGameOver) return;
	bIsGameOver = true;
	UE_LOG(LogTemp, Warning, TEXT("[GameState] 게임 오버 | 웨이브:%d 킬:%d 점수:%d 시간:%.1f초"),
		CurrentWave, TotalKills, TotalScore, ElapsedTime);
}
