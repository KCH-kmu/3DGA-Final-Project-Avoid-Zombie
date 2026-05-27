// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaveManager.generated.h"

class AZombieCharacter;

/**
 * 웨이브 매니저
 *
 * 규칙:
 * - 20초마다 웨이브 증가
 * - 포탈 8개 중 랜덤 선택, 하나의 포탈당 1초 내부 쿨다운 (겹침 방지)
 * - 1웨이브: 좀비 6마리, 이후 매 웨이브 +1마리 (최대 40웨이브)
 * - 매 2웨이브마다 좀비 이동속도 +0.2m/s (20cm/s)
 * - 매 5웨이브마다 좀비 체력 +1
 * - 현재 웨이브 좀비가 전멸하면 웨이브 클리어 처리
 */
UCLASS()
class AVOID_ZOMBIE_3DGA_API AWaveManager : public AActor
{
	GENERATED_BODY()

public:
	AWaveManager();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// ─── 포탈 위치 배열 (에디터에서 8개 지정) ──────────────────────
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Wave|Portals")
	TArray<TObjectPtr<AActor>> Portals;

	// ─── 좀비 블루프린트 클래스 (에디터에서 지정) ──────────────────
	UPROPERTY(EditDefaultsOnly, Category = "Wave|Spawn")
	TSubclassOf<AZombieCharacter> ZombieClass;

	// ─── 현재 상태 ──────────────────────────────────────────────────
	/** 현재 웨이브 번호 */
	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	int32 CurrentWave = 0;

	/** 이번 웨이브에서 아직 살아있는 좀비 수 */
	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	int32 AliveZombieCount = 0;

	/** 웨이브 진행 중인지 여부 */
	UPROPERTY(BlueprintReadOnly, Category = "Wave")
	bool bWaveActive = false;

	// ─── 공개 함수 ──────────────────────────────────────────────────
	/** 게임 오버 시 웨이브 중단 (GameMode에서 호출) */
	UFUNCTION(BlueprintCallable, Category = "Wave")
	void StopWave();

	/** 좀비 사망 시 호출 (ZombieCharacter Die()에서 자동 호출됨) */
	UFUNCTION(BlueprintCallable, Category = "Wave")
	void OnZombieDead();

protected:
	// ─── 타이머 핸들 ────────────────────────────────────────────────
	/** 웨이브 주기 타이머 (20초) */
	FTimerHandle WaveTimerHandle;

	/** 스폰 큐 처리 타이머 */
	FTimerHandle SpawnQueueTimerHandle;

	/** 포탈별 스폰 쿨다운 타이머 (인덱스 = 포탈 인덱스) */
	TArray<FTimerHandle> PortalCooldownTimers;

	/** 포탈별 쿨다운 상태 */
	TArray<bool> PortalOnCooldown;

	// ─── 스폰 큐 ────────────────────────────────────────────────────
	/** 스폰 대기 중인 좀비 수 */
	int32 SpawnQueueCount = 0;

	/** 스폰 큐 처리 간격 (초) */
	float SpawnQueueInterval = 0.3f;

	// ─── 스탯 누적 ──────────────────────────────────────────────────
	/** 현재 좀비 이동속도 (cm/s) */
	float CurrentZombieMoveSpeed = 100.f;

	/** 현재 좀비 최대 체력 */
	float CurrentZombieMaxHealth = 6.f;

	// ─── 내부 함수 ──────────────────────────────────────────────────
	/** 다음 웨이브 시작 */
	void StartNextWave();

	/** 웨이브 클리어 처리 */
	void OnWaveClear();

	/** 이번 웨이브에 스폰할 좀비 수 계산 */
	int32 GetZombieCountForWave(int32 Wave) const;

	/** 스폰 큐에서 좀비 1마리 스폰 */
	void SpawnOneFromQueue();

	/** 사용 가능한 포탈 인덱스 반환 (없으면 -1) */
	int32 GetAvailablePortalIndex() const;

	/** 포탈 쿨다운 해제 */
	void ClearPortalCooldown(int32 PortalIndex);
};
