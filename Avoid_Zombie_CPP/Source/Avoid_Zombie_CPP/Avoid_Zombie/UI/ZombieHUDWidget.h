// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZombieHUDWidget.generated.h"

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
};
