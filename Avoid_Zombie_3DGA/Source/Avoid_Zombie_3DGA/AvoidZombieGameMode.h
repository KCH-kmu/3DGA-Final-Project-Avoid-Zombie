// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AvoidZombieGameMode.generated.h"

class AWaveManager;

/**
 * Avoid Zombie 게임 모드
 * - 게임 시작/종료 흐름 관리
 * - WaveManager 스폰
 * - 매 Tick마다 GameState 시간 갱신
 */
UCLASS()
class AVOID_ZOMBIE_3DGA_API AAvoidZombieGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAvoidZombieGameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// ─── 게임 오버 진입점 ──────────────────────────────────────────
	/** 플레이어가 사망했을 때 호출 */
	UFUNCTION(BlueprintCallable, Category = "Game")
	void OnPlayerDead();

	// ─── WaveManager 참조 ──────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	TObjectPtr<AWaveManager> WaveManager;

protected:
	/** WaveManager 블루프린트 클래스 (에디터에서 지정) */
	UPROPERTY(EditDefaultsOnly, Category = "Wave")
	TSubclassOf<AWaveManager> WaveManagerClass;
};
