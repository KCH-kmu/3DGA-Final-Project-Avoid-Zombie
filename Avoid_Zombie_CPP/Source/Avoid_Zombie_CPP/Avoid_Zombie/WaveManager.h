// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaveManager.generated.h"

class AZombieCharacter;

/**
 * 웨이브 매니저
 *
 * - 20초마다 웨이브 증가
 * - 포탈 8개 중 랜덤 선택, 포탈당 1초 내부 쿨다운 (겹침 방지)
 * - 1웨이브 6마리, 매 웨이브 +1마리 (최대 40웨이브)
 * - 매 2웨이브마다 이동속도 +0.2m/s (20cm/s)
 * - 매 5웨이브마다 체력 +1
 * - 현재 웨이브 좀비 전멸 시 웨이브 클리어
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API AWaveManager : public AActor
{
	GENERATED_BODY()

public:
	AWaveManager();

	virtual void BeginPlay() override;

	/** 레벨에 배치된 포탈 Actor 8개 (에디터에서 지정) */
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Wave")
	TArray<TObjectPtr<AActor>> Portals;

	/** 좀비 블루프린트 클래스 (에디터에서 지정) */
	UPROPERTY(EditDefaultsOnly, Category = "Wave")
	TSubclassOf<AZombieCharacter> ZombieClass;

	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	int32 CurrentWave = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	int32 AliveZombieCount = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	bool bWaveActive = false;

	/** 게임 오버 시 웨이브 중단 */
	UFUNCTION(BlueprintCallable, Category = "Wave")
	void StopWave();

	/** ZombieCharacter::Die()에서 호출 */
	UFUNCTION(BlueprintCallable, Category = "Wave")
	void OnZombieDead();

protected:
	FTimerHandle WaveTimerHandle;
	FTimerHandle SpawnQueueTimerHandle;
	TArray<FTimerHandle> PortalCooldownTimers;
	TArray<bool>         PortalOnCooldown;

	int32 SpawnQueueCount    = 0;
	float SpawnQueueInterval = 0.3f;

	float CurrentZombieMoveSpeed  = 100.f;
	float CurrentZombieMaxHealth  = 6.f;

	void StartNextWave();
	void OnWaveClear();
	int32 GetZombieCountForWave(int32 Wave) const;
	void SpawnOneFromQueue();
	int32 GetAvailablePortalIndex() const;
	void ClearPortalCooldown(int32 Idx);
};
