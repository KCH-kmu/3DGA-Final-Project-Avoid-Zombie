// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieGameState.h"

AZombieGameState::AZombieGameState() {}

void AZombieGameState::UpdateElapsedTime(float DeltaTime)
{
	if (!bIsGameOver)
	{
		ElapsedTime += DeltaTime;
		OnTimeUpdated.Broadcast(ElapsedTime);
	}
}

void AZombieGameState::AddKillScore()
{
	TotalKills++;
	TotalScore += 10;
	OnScoreChanged.Broadcast(TotalScore);
	OnKillsChanged.Broadcast(TotalKills);
}

void AZombieGameState::SetCurrentWave(int32 NewWave)
{
	CurrentWave = NewWave;
	OnWaveChanged.Broadcast(CurrentWave);
}

void AZombieGameState::AddWaveClearScore(int32 WaveNumber)
{
	TotalScore += WaveNumber * 100;
	OnScoreChanged.Broadcast(TotalScore);
}

void AZombieGameState::AddBonusScore(int32 Bonus)
{
	TotalScore += Bonus;
	OnScoreChanged.Broadcast(TotalScore);
}

void AZombieGameState::TriggerGameOver()
{
	if (bIsGameOver) return;
	bIsGameOver = true;
	UE_LOG(LogTemp, Warning, TEXT("[GameState] 게임 오버 | 웨이브:%d 킬:%d 점수:%d 시간:%.1f초"),
		CurrentWave, TotalKills, TotalScore, ElapsedTime);
}
