// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "ScoreManager.h"
#include "AvoidZombieGameState.h"
#include "AvoidZombieCharacter.h"
#include "Kismet/GameplayStatics.h"

UScoreManager::UScoreManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UScoreManager::BeginPlay()
{
	Super::BeginPlay();
}

// ─── 킬 처리 + 마일스톤 체크 ─────────────────────────────────────────────
void UScoreManager::OnKill()
{
	// GameState가 킬 수와 기본 점수(킬×10)를 직접 관리
	// 여기서는 마일스톤만 추가 체크
	if (AAvoidZombieGameState* GS = GetWorld()->GetGameState<AAvoidZombieGameState>())
	{
		CheckMilestone(GS->TotalKills);
	}
}

void UScoreManager::CheckMilestone(int32 CurrentKills)
{
	AAvoidZombieGameState* GS = GetWorld()->GetGameState<AAvoidZombieGameState>();
	if (!GS) return;

	for (int32 i = 0; i < MilestoneKillThresholds.Num(); i++)
	{
		const int32 Threshold = MilestoneKillThresholds[i];
		if (CurrentKills >= Threshold && !GrantedMilestones.Contains(Threshold))
		{
			// 마일스톤 달성 → 보너스 점수 지급
			GrantedMilestones.Add(Threshold);
			const int32 Bonus = MilestoneBonusScores.IsValidIndex(i) ? MilestoneBonusScores[i] : 0;
			GS->AddBonusScore(Bonus);

			UE_LOG(LogTemp, Warning, TEXT("[Score] 마일스톤 달성! 킬 %d → +%d점"), Threshold, Bonus);
		}
	}
}

// ─── 웨이브 클리어 ────────────────────────────────────────────────────────
void UScoreManager::OnWaveClear(int32 WaveNumber, bool bFullHp)
{
	AAvoidZombieGameState* GS = GetWorld()->GetGameState<AAvoidZombieGameState>();
	if (!GS) return;

	// 웨이브 클리어 점수: 웨이브 * 100 (GameState에서 처리)
	GS->AddWaveClearScore(WaveNumber);

	// 웨이브 클리어 시 풀피 보너스 (밸런싱 예정 - 현재 웨이브*50)
	if (bFullHp)
	{
		const int32 FullHpBonus = WaveNumber * 50;
		GS->AddBonusScore(FullHpBonus);
		UE_LOG(LogTemp, Log, TEXT("[Score] 풀피 클리어 보너스: +%d점"), FullHpBonus);
	}
}

// ─── 게임오버 데이터 빌드 ─────────────────────────────────────────────────
FGameOverData UScoreManager::BuildGameOverData() const
{
	FGameOverData Data;

	if (AAvoidZombieGameState* GS = GetWorld()->GetGameState<AAvoidZombieGameState>())
	{
		Data.SurvivedTime = GS->ElapsedTime;
		Data.ReachedWave  = GS->CurrentWave;
		Data.TotalKills   = GS->TotalKills;
		Data.FinalScore   = GS->TotalScore;
	}

	UE_LOG(LogTemp, Warning,
		TEXT("[Score] 게임오버 최종 데이터 | 시간: %.1f초 | 웨이브: %d | 킬: %d | 점수: %d"),
		Data.SurvivedTime, Data.ReachedWave, Data.TotalKills, Data.FinalScore);

	return Data;
}

int32 UScoreManager::GetTotalScore() const
{
	if (AAvoidZombieGameState* GS = GetWorld()->GetGameState<AAvoidZombieGameState>())
	{
		return GS->TotalScore;
	}
	return 0;
}
