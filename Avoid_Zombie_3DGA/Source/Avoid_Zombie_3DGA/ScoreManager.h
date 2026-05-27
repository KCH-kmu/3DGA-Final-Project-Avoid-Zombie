// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreManager.generated.h"

/**
 * 게임오버 화면에 표시할 최종 데이터 구조체
 */
USTRUCT(BlueprintType)
struct FGameOverData
{
	GENERATED_BODY()

	/** 버틴 시간 (초) */
	UPROPERTY(BlueprintReadOnly)
	float SurvivedTime = 0.f;

	/** 도달한 웨이브 수 */
	UPROPERTY(BlueprintReadOnly)
	int32 ReachedWave = 0;

	/** 총 킬 수 */
	UPROPERTY(BlueprintReadOnly)
	int32 TotalKills = 0;

	/** 종합 점수 */
	UPROPERTY(BlueprintReadOnly)
	int32 FinalScore = 0;
};

/**
 * 스코어 매니저 컴포넌트
 *
 * 점수 계산 규칙:
 * - 기본 킬 점수: 킬 * 10
 * - 웨이브 클리어: 웨이브 번호 * 100
 * - 마일스톤: 킬 50마다 +500점, 킬 100마다 +1500점
 * - 게임오버 화면: 버틴 시간 / 웨이브 수 / 킬 수 / 종합 점수
 *
 * 사용법:
 * GameMode 또는 PlayerController에 컴포넌트로 추가
 * (실제 점수 저장은 AvoidZombieGameState가 담당,
 *  이 클래스는 마일스톤 체크 및 GameOverData 빌드 담당)
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AVOID_ZOMBIE_3DGA_API UScoreManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UScoreManager();

	virtual void BeginPlay() override;

	// ─── 마일스톤 킬 기준 ───────────────────────────────────────────
	UPROPERTY(EditDefaultsOnly, Category = "Score|Milestone")
	TArray<int32> MilestoneKillThresholds = { 50, 100, 200, 500 };

	UPROPERTY(EditDefaultsOnly, Category = "Score|Milestone")
	TArray<int32> MilestoneBonusScores    = { 500, 1500, 5000, 20000 };

	// ─── 공개 함수 ──────────────────────────────────────────────────
	/** 킬 발생 시 호출 (마일스톤 체크 포함) */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void OnKill();

	/** 웨이브 클리어 시 호출 */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void OnWaveClear(int32 WaveNumber, bool bFullHp);

	/** 게임오버 데이터 수집 및 반환 */
	UFUNCTION(BlueprintCallable, Category = "Score")
	FGameOverData BuildGameOverData() const;

	/** 현재 총 점수 반환 */
	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetTotalScore() const;

private:
	/** 마일스톤 중복 방지용 - 이미 지급된 마일스톤 킬 수 */
	TSet<int32> GrantedMilestones;

	/** 마일스톤 체크 */
	void CheckMilestone(int32 CurrentKills);
};
