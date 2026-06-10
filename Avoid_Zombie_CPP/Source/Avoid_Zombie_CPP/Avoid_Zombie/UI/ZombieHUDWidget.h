// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZombieHUDWidget.generated.h"

/**
 * Avoid Zombie 메인 HUD 위젯
 *
 * WBP_ZombieHUD에서 이 클래스를 부모로 설정 후
 * - 탄약: CurrentAmmo / MaxAmmo 변수에 텍스트 바인딩
 * - 체력: CurrentHealth / MaxHealth 변수에 Progress Bar·텍스트 바인딩
 *         GetHealthPercent() → Progress Bar Percent 바인딩
 *         GetHealthBarColor() → Progress Bar FillColorAndOpacity 바인딩
 */
UCLASS(Abstract)
class AVOID_ZOMBIE_CPP_API UZombieHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
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

	/**
	 * Progress Bar FillColorAndOpacity 바인딩용
	 * 7~10 → 초록 / 4~6 → 노랑 / 1~3 → 빨강
	 */
	UFUNCTION(BlueprintPure, Category = "HUD|Health")
	FLinearColor GetHealthBarColor() const;
};
