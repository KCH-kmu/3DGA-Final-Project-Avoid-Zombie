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

	// 기본 킬 점수: 킬 * 10
	KillScore  += 10;
	TotalScore += 10;

	// 마일스톤: MilestoneKillStep 킬마다 MilestoneBonus 지급 (예: 50킬당 +300)
	if (MilestoneKillStep > 0 && (TotalKills % MilestoneKillStep) == 0)
	{
		MilestoneScore += MilestoneBonus;
		TotalScore     += MilestoneBonus;
		UE_LOG(LogTemp, Warning, TEXT("[Score] 마일스톤 %d킬 → +%d점"), TotalKills, MilestoneBonus);
	}

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
	// 웨이브 클리어당 +100
	WaveClearScore += 100;
	TotalScore     += 100;
	OnScoreChanged.Broadcast(TotalScore);
}

void AZombieGameState::AddBonusScore(int32 Bonus)
{
	// 현재 유일한 호출처는 WaveManager의 클리어 회복 초과분 환산 → 회복 보너스로 집계
	HealBonusScore += Bonus;
	TotalScore     += Bonus;
	OnScoreChanged.Broadcast(TotalScore);
}

void AZombieGameState::TriggerGameOver()
{
	if (bIsGameOver) return;
	bIsGameOver = true;
	UE_LOG(LogTemp, Warning, TEXT("[GameState] 게임 오버 | 웨이브:%d 킬:%d 점수:%d 시간:%.1f초"),
		CurrentWave, TotalKills, TotalScore, ElapsedTime);

	// 게임오버 화면 표시 (HUD가 바인딩)
	OnGameOver.Broadcast();
}
