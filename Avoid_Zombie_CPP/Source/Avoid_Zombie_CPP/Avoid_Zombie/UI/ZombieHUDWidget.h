// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZombieHUDWidget.generated.h"

class UTexture2D;
class UWeaponComponent;
enum class EItemType : uint8;

/**
 * Avoid Zombie 메인 HUD 위젯
 *
 * WBP_ZombieHUD에서 이 클래스를 부모로 설정 후
 * - 탄약  : CurrentAmmo / MaxAmmo 텍스트 바인딩          (우하단)
 * - 체력  : GetHealthPercent / GetHealthBarColor 바인딩  (좌하단)
 * - 시간  : GetTimeText 바인딩                           (우상단)
 * - 점수  : TotalScore 텍스트 바인딩                     (우상단)
 */
UCLASS(Abstract)
class AVOID_ZOMBIE_CPP_API UZombieHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UZombieHUDWidget(const FObjectInitializer& ObjectInitializer);

	// ─── 탄약 ───────────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "HUD|Ammo")
	int32 CurrentAmmo = 30;

	UPROPERTY(BlueprintReadOnly, Category = "HUD|Ammo")
	int32 MaxAmmo = 30;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HUD|Ammo")
	void SetAmmo(int32 Current, int32 Max);
	virtual void SetAmmo_Implementation(int32 Current, int32 Max);

	// ─── 체력 ───────────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "HUD|Health")
	float CurrentHealth = 10.f;

	UPROPERTY(BlueprintReadOnly, Category = "HUD|Health")
	float MaxHealth = 10.f;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HUD|Health")
	void SetHealth(float Current, float Max);
	virtual void SetHealth_Implementation(float Current, float Max);

	/** Progress Bar Percent 바인딩용 (0.0 ~ 1.0) */
	UFUNCTION(BlueprintPure, Category = "HUD|Health")
	float GetHealthPercent() const;

	/** Progress Bar 색상 바인딩용 (초록/노랑/빨강) */
	UFUNCTION(BlueprintPure, Category = "HUD|Health")
	FLinearColor GetHealthBarColor() const;

	// ─── 시간 ───────────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "HUD|Time")
	float DisplayTime = 0.f;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HUD|Time")
	void SetTime(float NewTime);
	virtual void SetTime_Implementation(float NewTime);

	/** "PlayTime : MM:SS" 포맷 텍스트 바인딩용 */
	UFUNCTION(BlueprintPure, Category = "HUD|Time")
	FText GetTimeText() const;

	// ─── 점수 ───────────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "HUD|Score")
	int32 TotalScore = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HUD|Score")
	void SetScore(int32 NewScore);
	virtual void SetScore_Implementation(int32 NewScore);

	// ─── 킬 카운트 ──────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "HUD|Score")
	int32 TotalKills = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HUD|Score")
	void SetKills(int32 NewKills);
	virtual void SetKills_Implementation(int32 NewKills);

	/** "Kill : 0" 포맷 텍스트 바인딩용 */
	UFUNCTION(BlueprintPure, Category = "HUD|Score")
	FText GetKillsText() const;

	/** "Score : 0" 포맷 텍스트 바인딩용 */
	UFUNCTION(BlueprintPure, Category = "HUD|Score")
	FText GetScoreText() const;

	// ─── 웨이브 ─────────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "HUD|Wave")
	int32 CurrentWave = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HUD|Wave")
	void SetWave(int32 NewWave);
	virtual void SetWave_Implementation(int32 NewWave);

	// ─── 아이템 (보유 / 발동 중) — UMG 바인딩용 ────────────────────
	/** 아이템 아이콘 (생성자에서 자동 로드, WBP에서 덮어쓰기 가능) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	TObjectPtr<UTexture2D> Icon_HealSelf;

	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	TObjectPtr<UTexture2D> Icon_FireRateUp;

	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	TObjectPtr<UTexture2D> Icon_StunAll;

	/** 들고 있는 아이템이 있는지 — 보유 슬롯 Visibility 바인딩 */
	UFUNCTION(BlueprintPure, Category = "HUD|Item")
	bool HasHeldItem() const;

	/** 들고 있는 아이템 아이콘 — 보유 슬롯 Image Brush 바인딩 */
	UFUNCTION(BlueprintPure, Category = "HUD|Item")
	UTexture2D* GetHeldItemIcon() const;

	/** 발동 중 지속시간 아이템이 있는지 — 발동 슬롯 Visibility 바인딩 */
	UFUNCTION(BlueprintPure, Category = "HUD|Item")
	bool HasActiveBuff() const;

	/** 발동 중 아이템 아이콘 — 발동 슬롯 Image Brush 바인딩 */
	UFUNCTION(BlueprintPure, Category = "HUD|Item")
	UTexture2D* GetActiveBuffIcon() const;

	/** 발동 중 진행률 (1=방금 발동 → 0=종료) */
	UFUNCTION(BlueprintPure, Category = "HUD|Item")
	float GetActiveBuffProgress() const;

	/** 경과율 (0=방금 → 1=종료) = 1 - Progress. */
	UFUNCTION(BlueprintPure, Category = "HUD|Item")
	float GetActiveBuffElapsed() const;

	/** 발동 중 아이콘 색조 — 시간 갈수록 어두워짐(흰색→어두운 회색). ActiveIcon의 ColorAndOpacity에 사용 */
	UFUNCTION(BlueprintPure, Category = "HUD|Item")
	FLinearColor GetActiveBuffTint() const;

protected:
	/** 소유 플레이어의 무기 컴포넌트 */
	UWeaponComponent* GetWeapon() const;

	/** 아이템 종류 → 아이콘 텍스처 */
	UTexture2D* GetIconForItem(EItemType Item) const;
};
