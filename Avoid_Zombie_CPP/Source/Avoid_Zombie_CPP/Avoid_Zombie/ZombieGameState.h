// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ZombieGameState.generated.h"

/** 점수 변경 델리게이트 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int32, NewScore);

/** 시간 갱신 델리게이트 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeUpdated, float, NewTime);

/** 웨이브 변경 델리게이트 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWaveChanged, int32, NewWave);

/** 킬 카운트 변경 델리게이트 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKillsChanged, int32, NewKills);

/** 게임 오버 발생 델리게이트 (게임오버 화면 표시용) */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameOver);

/**
 * 게임 전역 상태
 * 웨이브 번호, 킬 수, 점수, 경과 시간을 보관한다.
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API AZombieGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AZombieGameState();

	// ─── 델리게이트 ─────────────────────────────────────────────────
	UPROPERTY(BlueprintAssignable, Category = "Score")
	FOnScoreChanged OnScoreChanged;

	UPROPERTY(BlueprintAssignable, Category = "Time")
	FOnTimeUpdated OnTimeUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Wave")
	FOnWaveChanged OnWaveChanged;

	UPROPERTY(BlueprintAssignable, Category = "Score")
	FOnKillsChanged OnKillsChanged;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnGameOver OnGameOver;

	// ─── 웨이브 ─────────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	int32 CurrentWave = 0;

	// ─── 점수 / 킬 ──────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Score")
	int32 TotalScore = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Score")
	int32 TotalKills = 0;

	// ─── 항목별 점수 누적 (게임오버 화면 세부 표기용) ────────────────
	/** 킬 점수 누적 (= TotalKills * 10) */
	UPROPERTY(BlueprintReadOnly, Category = "Score|Breakdown")
	int32 KillScore = 0;

	/** 웨이브 클리어 점수 누적 (클리어당 +100) */
	UPROPERTY(BlueprintReadOnly, Category = "Score|Breakdown")
	int32 WaveClearScore = 0;

	/** 마일스톤 점수 누적 (MilestoneKillStep 킬마다 +MilestoneBonus) */
	UPROPERTY(BlueprintReadOnly, Category = "Score|Breakdown")
	int32 MilestoneScore = 0;

	/** 풀피/회복 보너스 점수 누적 (웨이브 클리어 회복 초과분 환산) */
	UPROPERTY(BlueprintReadOnly, Category = "Score|Breakdown")
	int32 HealBonusScore = 0;

	/** 회복 보너스 누적 HP 수 (게임오버 "{HP}HP × 단가" 표기용) */
	UPROPERTY(BlueprintReadOnly, Category = "Score|Breakdown")
	int32 HealBonusUnits = 0;

	/** 회복 보너스 HP당 점수 (표기용, WaveManager가 전달; 기본 50 = OverflowHealScore 기본값) */
	UPROPERTY(BlueprintReadOnly, Category = "Score|Breakdown")
	int32 HealBonusPerUnit = 50;

	// ─── 마일스톤 설정 ──────────────────────────────────────────────
	/** 이 킬 수마다 마일스톤 보너스 지급 (기본 50킬) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Score")
	int32 MilestoneKillStep = 50;

	/** 마일스톤 1회 보너스 점수 (기본 300점) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Score")
	int32 MilestoneBonus = 300;

	// ─── 플레이 시간 ────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	float ElapsedTime = 0.f;

	// ─── 게임 오버 ──────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Game")
	bool bIsGameOver = false;

	// ─── 점수 추가 함수 ─────────────────────────────────────────────
	/** 킬 1회 추가 + 킬*10 점수 */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddKillScore();

	/** 웨이브 클리어 점수 추가 (+100 고정) */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddWaveClearScore(int32 WaveNumber);

	/** 보너스 점수 직접 추가 */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddBonusScore(int32 Bonus);

	/** 회복 보너스 추가 (OverflowUnits HP × PerUnitScore 점). 게임오버 표기용 카운트/단가도 기록 */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddHealBonus(int32 OverflowUnits, int32 PerUnitScore);

	/** 게임 오버 처리 */
	UFUNCTION(BlueprintCallable, Category = "Game")
	void TriggerGameOver();

	/** GameMode의 Tick에서 호출 — 경과 시간 갱신 */
	void UpdateElapsedTime(float DeltaTime);

	/** WaveManager에서 호출 — 웨이브 번호 갱신 + broadcast */
	void SetCurrentWave(int32 NewWave);
};
