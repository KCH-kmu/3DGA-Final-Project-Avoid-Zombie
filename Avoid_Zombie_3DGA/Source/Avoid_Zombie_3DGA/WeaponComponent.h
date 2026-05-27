// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

/** 아이템 종류 열거형 */
UENUM(BlueprintType)
enum class EItemType : uint8
{
	None         UMETA(DisplayName = "없음"),
	StunAll      UMETA(DisplayName = "전체 스턴 (3초)"),
	FireRateUp   UMETA(DisplayName = "발사속도 증가 (5초)"),
	HealSelf     UMETA(DisplayName = "체력 2 회복")
};

/**
 * 무기 컴포넌트 (AR)
 *
 * 스펙:
 * - 탄창 30발, 탄약 무한
 * - RPS 10발/초 (발사 딜레이 0.1초)
 * - 발당 데미지 2
 * - 재장전 시간 2초 (R키 또는 0발 시 자동)
 * - 재장전 중 원형 타이머 진행률(0~1) 제공
 *
 * 아이템 버프 (FireRateUp):
 * - RPS 15 / 재장전 1초 / 5초간 지속
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AVOID_ZOMBIE_3DGA_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UWeaponComponent();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ─── 탄약 ───────────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	int32 CurrentAmmo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	int32 MaxAmmo = 30;

	// ─── 재장전 상태 (UI 원형 타이머용) ────────────────────────────
	/** 현재 재장전 중인지 여부 */
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	bool bIsReloading = false;

	/** 재장전 진행률 0.0 ~ 1.0 (크로스헤어 원형 타이머에 사용) */
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	float ReloadProgress = 0.f;

	// ─── 인벤토리 아이템 ────────────────────────────────────────────
	/** 현재 보유 중인 아이템 */
	UPROPERTY(BlueprintReadOnly, Category = "Item")
	EItemType HeldItem = EItemType::None;

	// ─── 공개 함수 ──────────────────────────────────────────────────
	/** 사격 시작 (마우스 좌클릭 Down) */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void StartFire();

	/** 사격 중지 (마우스 좌클릭 Up) */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void StopFire();

	/** 재장전 시작 (R키 또는 자동 호출) */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void StartReload();

	/** 아이템 수령 (ItemBox에서 호출) */
	UFUNCTION(BlueprintCallable, Category = "Item")
	void ReceiveItem(EItemType ItemType);

	/** 아이템 사용 (우클릭에서 호출) */
	UFUNCTION(BlueprintCallable, Category = "Item")
	void UseHeldItem();

	/** 현재 발사 속도 (RPS) 반환 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetCurrentRPS() const;

	/** 현재 재장전 시간 반환 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetCurrentReloadTime() const;

protected:
	// ─── 기본 무기 스펙 ─────────────────────────────────────────────
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BaseDamagePerBullet = 2.f;

	/** 기본 RPS (Rounds Per Second) */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BaseRPS = 10.f;

	/** 기본 재장전 시간 (초) */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BaseReloadTime = 2.f;

	// ─── 아이템 버프 스펙 ───────────────────────────────────────────
	/** 버프 적용 시 RPS */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Buff")
	float BuffRPS = 15.f;

	/** 버프 적용 시 재장전 시간 */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Buff")
	float BuffReloadTime = 1.f;

	/** 버프 지속 시간 (초) */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Buff")
	float BuffDuration = 5.f;

private:
	// ─── 내부 상태 ──────────────────────────────────────────────────
	bool bIsFiring = false;
	bool bIsFireRateBuff = false;

	float FireTimer    = 0.f;  // 다음 발사까지 남은 시간
	float ReloadTimer  = 0.f;  // 재장전 남은 시간
	float BuffTimer    = 0.f;  // 버프 남은 시간

	// ─── 내부 함수 ──────────────────────────────────────────────────
	/** 실제 발사 1회 처리 */
	void FireOnce();

	/** 재장전 완료 처리 */
	void FinishReload();

	/** 버프 종료 처리 */
	void EndFireRateBuff();

	/** LineTrace로 좀비 타격 처리 */
	void PerformLineTrace();
};
