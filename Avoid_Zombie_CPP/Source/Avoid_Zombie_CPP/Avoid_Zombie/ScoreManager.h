// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreManager.generated.h"

/** 게임오버 화면 표시 데이터 */
USTRUCT(BlueprintType)
struct FGameOverData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly) float SurvivedTime = 0.f;
	UPROPERTY(BlueprintReadOnly) int32 ReachedWave  = 0;
	UPROPERTY(BlueprintReadOnly) int32 TotalKills   = 0;
	UPROPERTY(BlueprintReadOnly) int32 FinalScore   = 0;
};

/**
 * 스코어 매니저 컴포넌트
 *
 * - 마일스톤 킬 수마다 보너스 점수
 * - 게임오버 데이터 (버틴 시간 / 웨이브 / 킬 / 점수) 수집
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AVOID_ZOMBIE_CPP_API UScoreManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UScoreManager();
	virtual void BeginPlay() override;

	/** 마일스톤 킬 기준 */
	UPROPERTY(EditDefaultsOnly, Category = "Score")
	TArray<int32> MilestoneThresholds = { 50, 100, 200, 500 };

	/** 마일스톤 보너스 점수 */
	UPROPERTY(EditDefaultsOnly, Category = "Score")
	TArray<int32> MilestoneBonuses = { 500, 1500, 5000, 20000 };

	/** 킬 발생 시 호출 — 마일스톤 체크 포함 */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void OnKill();

	/** 웨이브 클리어 시 호출 */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void OnWaveClear(int32 WaveNumber, bool bFullHp);

	/** 게임오버 데이터 반환 */
	UFUNCTION(BlueprintCallable, Category = "Score")
	FGameOverData BuildGameOverData() const;

private:
	TSet<int32> GrantedMilestones;
	void CheckMilestone(int32 Kills);
};
