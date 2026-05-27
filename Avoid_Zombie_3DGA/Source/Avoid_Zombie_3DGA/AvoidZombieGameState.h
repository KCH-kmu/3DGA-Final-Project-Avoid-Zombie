// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AvoidZombieGameState.generated.h"

/**
 * 게임 전역 상태 클래스
 * 웨이브, 킬 수, 점수, 플레이 시간 등을 보관한다.
 * ScoreManager, WaveManager가 이 클래스를 통해 데이터를 공유한다.
 */
UCLASS()
class AVOID_ZOMBIE_3DGA_API AAvoidZombieGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AAvoidZombieGameState();

	// ─── 웨이브 정보 ───────────────────────────────────────────────
	/** 현재 웨이브 번호 (1-based) */
	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	int32 CurrentWave = 0;

	// ─── 스코어 / 킬 ───────────────────────────────────────────────
	/** 누적 총 점수 */
	UPROPERTY(BlueprintReadOnly, Category = "Score")
	int32 TotalScore = 0;

	/** 누적 킬 수 */
	UPROPERTY(BlueprintReadOnly, Category = "Score")
	int32 TotalKills = 0;

	// ─── 플레이 시간 ───────────────────────────────────────────────
	/** 게임 시작 후 경과 초 (게임오버 화면 표시용) */
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	float ElapsedTime = 0.f;

	// ─── 게임 오버 여부 ────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Game")
	bool bIsGameOver = false;

	// ─── 점수 추가 함수 ────────────────────────────────────────────
	/** 킬 점수 추가 (킬 * 10) */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddKillScore();

	/** 웨이브 클리어 점수 추가 (웨이브 * 100) */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddWaveClearScore(int32 WaveNumber);

	/** 임의 점수 추가 (마일스톤 등) */
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddBonusScore(int32 Bonus);

	// ─── 게임 오버 처리 ────────────────────────────────────────────
	UFUNCTION(BlueprintCallable, Category = "Game")
	void TriggerGameOver();

	// ─── 시간 갱신 (GameMode가 매 Tick에 호출) ────────────────────
	void UpdateElapsedTime(float DeltaTime);

protected:
	virtual void BeginPlay() override;
};
