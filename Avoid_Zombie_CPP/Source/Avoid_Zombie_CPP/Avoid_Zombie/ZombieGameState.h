// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ZombieGameState.generated.h"

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

	// ─── 웨이브 ─────────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	int32 CurrentWave = 0;

	// ─── 점수 / 킬 ──────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Score")
	int32 TotalScore = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Score")
	int32 TotalKills = 0;

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

	/** 웨이브 클리어 점수 추가 (웨이브 * 100) */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddWaveClearScore(int32 WaveNumber);

	/** 보너스 점수 직접 추가 */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddBonusScore(int32 Bonus);

	/** 게임 오버 처리 */
	UFUNCTION(BlueprintCallable, Category = "Game")
	void TriggerGameOver();

	/** GameMode의 Tick에서 호출 — 경과 시간 갱신 */
	void UpdateElapsedTime(float DeltaTime);
};
