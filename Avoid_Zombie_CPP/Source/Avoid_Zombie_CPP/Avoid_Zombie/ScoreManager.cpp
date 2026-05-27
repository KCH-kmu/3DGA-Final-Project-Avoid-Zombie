// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ScoreManager.h"
#include "ZombieGameState.h"

UScoreManager::UScoreManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UScoreManager::BeginPlay()
{
	Super::BeginPlay();
}

void UScoreManager::OnKill()
{
	if (AZombieGameState* GS = GetWorld()->GetGameState<AZombieGameState>())
		CheckMilestone(GS->TotalKills);
}

void UScoreManager::CheckMilestone(int32 Kills)
{
	AZombieGameState* GS = GetWorld()->GetGameState<AZombieGameState>();
	if (!GS) return;

	for (int32 i = 0; i < MilestoneThresholds.Num(); i++)
	{
		int32 T = MilestoneThresholds[i];
		if (Kills >= T && !GrantedMilestones.Contains(T))
		{
			GrantedMilestones.Add(T);
			int32 Bonus = MilestoneBonuses.IsValidIndex(i) ? MilestoneBonuses[i] : 0;
			GS->AddBonusScore(Bonus);
			UE_LOG(LogTemp, Warning, TEXT("[Score] 마일스톤 킬 %d → +%d점"), T, Bonus);
		}
	}
}

void UScoreManager::OnWaveClear(int32 WaveNumber, bool bFullHp)
{
	AZombieGameState* GS = GetWorld()->GetGameState<AZombieGameState>();
	if (!GS) return;

	// 웨이브 클리어 점수는 GameState가 처리 (WaveManager → GameState)
	// 풀피 클리어 보너스 (밸런싱 예정: 웨이브 * 50)
	if (bFullHp)
	{
		GS->AddBonusScore(WaveNumber * 50);
		UE_LOG(LogTemp, Log, TEXT("[Score] 풀피 클리어 보너스: +%d"), WaveNumber * 50);
	}
}

FGameOverData UScoreManager::BuildGameOverData() const
{
	FGameOverData Data;
	if (AZombieGameState* GS = GetWorld()->GetGameState<AZombieGameState>())
	{
		Data.SurvivedTime = GS->ElapsedTime;
		Data.ReachedWave  = GS->CurrentWave;
		Data.TotalKills   = GS->TotalKills;
		Data.FinalScore   = GS->TotalScore;
	}
	UE_LOG(LogTemp, Warning, TEXT("[Score] 최종 | 시간:%.1f 웨이브:%d 킬:%d 점수:%d"),
		Data.SurvivedTime, Data.ReachedWave, Data.TotalKills, Data.FinalScore);
	return Data;
}
