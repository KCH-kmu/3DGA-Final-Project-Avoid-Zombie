// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

class UNiagaraSystem;
class USoundBase;
struct FHitResult;

/** 아이템 종류 */
UENUM(BlueprintType)
enum class EItemType : uint8
{
	None        UMETA(DisplayName = "없음"),
	StunAll     UMETA(DisplayName = "전체 스턴 3초"),
	FireRateUp  UMETA(DisplayName = "발사속도 증가 5초"),
	HealSelf    UMETA(DisplayName = "체력 2 회복")
};

/** 탄약 변경 델리게이트 (현재 탄약, 최대 탄약) */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoChanged, int32, CurrentAmmo, int32, MaxAmmo);

/** 발사 1회 발생 델리게이트 (캐릭터 발사 몽타주 재생용) */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWeaponFired);

/** 재장전 시작 델리게이트 (ReloadTime = 이번 재장전 소요 시간, 초) */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReloadStarted, float, ReloadTime);

/**
 * 무기 컴포넌트 (AR)
 *
 * 스펙:
 * - 탄창 30발 / 탄약 무한
 * - RPS 10발/초, 발당 데미지 2
 * - 재장전 2초 (R 또는 0발 시 자동)
 * - 재장전 진행률(0~1) → 크로스헤어 원형 타이머에 사용
 *
 * 아이템 FireRateUp 발동 시:
 * - RPS 15 / 재장전 1초 / 5초간 유지
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AVOID_ZOMBIE_CPP_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UWeaponComponent();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ─── 델리게이트 ─────────────────────────────────────────────────
	/** 탄약 수 변경 시 broadcast (HUD 갱신용) */
	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnAmmoChanged OnAmmoChanged;

	/** 발사 1회 발생 시 broadcast (발사 몽타주용) */
	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnWeaponFired OnWeaponFired;

	/** 재장전 시작 시 broadcast (재장전 몽타주용) */
	UPROPERTY(BlueprintAssignable, Category = "Weapon")
	FOnReloadStarted OnReloadStarted;

	// ─── 탄약 상태 ──────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	int32 CurrentAmmo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	int32 MaxAmmo = 30;

	// ─── 재장전 상태 (UI용) ─────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	bool bIsReloading = false;

	/** 재장전 진행률 0.0~1.0 (크로스헤어 원형 타이머) */
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	float ReloadProgress = 0.f;

	// ─── 아이템 인벤토리 ────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Item")
	EItemType HeldItem = EItemType::None;

	// ─── 발동 중 지속시간 아이템 (HUD 카운트다운용) ────────────────
	/** 현재 발동 중인 지속시간 아이템 (없으면 None) */
	UPROPERTY(BlueprintReadOnly, Category = "Item")
	EItemType ActiveTimedItem = EItemType::None;

	/** 발동 중 아이템 남은 시간(초) */
	UPROPERTY(BlueprintReadOnly, Category = "Item")
	float ActiveTimedRemaining = 0.f;

	/** 발동 중 아이템 총 지속시간(초) */
	UPROPERTY(BlueprintReadOnly, Category = "Item")
	float ActiveTimedDuration = 0.f;

	/** 발동 중 아이템 진행률 (1=방금 발동 → 0=종료) — HUD 카운트다운용 */
	UFUNCTION(BlueprintPure, Category = "Item")
	float GetActiveTimedProgress() const
	{
		return ActiveTimedDuration > 0.f ? FMath::Clamp(ActiveTimedRemaining / ActiveTimedDuration, 0.f, 1.f) : 0.f;
	}

	// ─── 공개 함수 ──────────────────────────────────────────────────
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void StartFire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void StopFire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void StartReload();

	UFUNCTION(BlueprintCallable, Category = "Item")
	void ReceiveItem(EItemType ItemType);

	UFUNCTION(BlueprintCallable, Category = "Item")
	void UseHeldItem();

	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetCurrentRPS() const;

	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetCurrentReloadTime() const;

protected:
	// ─── 기본 무기 스펙 ─────────────────────────────────────────────
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BaseDamagePerBullet = 2.f;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BaseRPS = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BaseReloadTime = 2.f;

	// ─── 버프 스펙 ──────────────────────────────────────────────────
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Buff")
	float BuffRPS = 15.f;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Buff")
	float BuffReloadTime = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Buff")
	float BuffDuration = 5.f;

	/** 전체 스턴 지속시간(초) — 좀비 스턴 + HUD 카운트다운 공통 */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Buff")
	float StunDuration = 3.f;

	// ─── 피탄 이펙트 ────────────────────────────────────────────────
	/** 일반 오브젝트(벽·바닥 등) 피탄 이펙트 — 기본값 NS_Damage(흰색) */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|FX")
	TObjectPtr<UNiagaraSystem> WorldImpactEffect;

	/** 좀비 피탄 이펙트 — 기본값 NS_Damage(붉게 틴트). 따로 만든 NS로 교체 가능 */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|FX")
	TObjectPtr<UNiagaraSystem> ZombieImpactEffect;

	/** Niagara 색상 User 파라미터 이름. 시스템에 이 파라미터가 노출돼 있을 때만 색 적용됨 */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|FX")
	FName ImpactColorParam = TEXT("User.Color");

	/** 일반 오브젝트 피탄 색 */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|FX")
	FLinearColor WorldImpactColor = FLinearColor::White;

	/** 좀비 피탄 색 (붉은 계열) */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|FX")
	FLinearColor ZombieImpactColor = FLinearColor(1.f, 0.05f, 0.05f, 1.f);

	// ─── 사운드 (에디터에서 .wav/Cue 할당) ─────────────────────────
	/** 발사음 — 발사 1발마다 재생 */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Sound")
	TObjectPtr<USoundBase> FireSound;

	/** 재장전음 — 재장전 시작 시 재생 */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Sound")
	TObjectPtr<USoundBase> ReloadSound;

	/** 피탄음 — 명중 지점에서 재생 (선택) */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Sound")
	TObjectPtr<USoundBase> ImpactSound;

private:
	bool  bIsFiring             = false;
	bool  bIsFireRateBuff       = false;
	float FireTimer             = 0.f;
	float ReloadTimer           = 0.f;
	/** 재장전 시작 시점에 고정한 총 소요 시간 (진행률 분모 — 도중 버프 만료 시 desync 방지) */
	float CurrentReloadDuration = 0.f;
	float BuffTimer             = 0.f;

	void FireOnce();
	void FinishReload();
	void EndFireRateBuff();
	void PerformLineTrace();

	/** 피탄 지점에 Niagara 이펙트 스폰 (좀비면 붉게, 그 외면 흰색) */
	void SpawnImpactEffect(const FHitResult& Hit, bool bIsZombie);
};
