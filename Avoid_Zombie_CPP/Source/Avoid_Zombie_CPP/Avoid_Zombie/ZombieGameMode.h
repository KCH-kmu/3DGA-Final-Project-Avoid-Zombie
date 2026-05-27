// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ZombieGameMode.generated.h"

class AWaveManager;

/**
 * Avoid Zombie 게임 모드
 * - BeginPlay 시 WaveManager 스폰
 * - Tick에서 GameState 시간 갱신
 * - 플레이어 사망 시 게임 오버 처리
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API AZombieGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AZombieGameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void OnPlayerDead();

	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	TObjectPtr<AWaveManager> WaveManager;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Wave")
	TSubclassOf<AWaveManager> WaveManagerClass;
};
