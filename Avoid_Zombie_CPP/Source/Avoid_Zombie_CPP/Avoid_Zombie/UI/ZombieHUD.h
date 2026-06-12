// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ZombieHUD.generated.h"

class UZombieHUDWidget;

UCLASS()
class AVOID_ZOMBIE_CPP_API AZombieHUD : public AHUD
{
	GENERATED_BODY()

public:
	AZombieHUD();

	virtual void BeginPlay() override;

	/** 화면 중심 크로스헤어 드로잉 */
	virtual void DrawHUD() override;

	/** 탄약 갱신 */
	UFUNCTION() void OnAmmoChanged(int32 Current, int32 Max);

	/** 체력 갱신 */
	UFUNCTION() void OnHealthChanged(float Current, float Max);

	/** 시간 갱신 */
	UFUNCTION() void OnTimeUpdated(float NewTime);

	/** 점수 갱신 */
	UFUNCTION() void OnScoreChanged(int32 NewScore);

	/** 킬 카운트 갱신 */
	UFUNCTION() void OnKillsChanged(int32 NewKills);

	/** 웨이브 갱신 */
	UFUNCTION() void OnWaveChanged(int32 NewWave);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	TSubclassOf<UZombieHUDWidget> HUDWidgetClass;

	// ─── 크로스헤어 설정 ────────────────────────────────────────────
	/** 선 길이 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	float CrosshairSize = 11.f;

	/** 중심에서 선까지 간격 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	float CrosshairGap = 7.f;

	/** 선 두께 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	float CrosshairThickness = 3.5f;

	/** 외곽선 색상 (밝은 배경에서도 잘 보이도록) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	FLinearColor CrosshairOutlineColor = FLinearColor(0.f, 0.f, 0.f, 0.6f);

	/** 기본 색상 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	FLinearColor CrosshairColor = FLinearColor::White;

	/** 공격 불가 상태(달리기/복귀 회전/재장전) 색상 — 붉은 반투명 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	FLinearColor DisabledCrosshairColor = FLinearColor(1.f, 0.25f, 0.25f, 0.45f);

	// ─── 재장전 원형 타이머 ─────────────────────────────────────────
	/** 원형 타이머 반지름 (크로스헤어보다 넉넉하게) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Reload")
	float ReloadRingRadius = 28.f;

	/** 진행 게이지 선 두께 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Reload")
	float ReloadRingThickness = 4.f;

	/** 배경 링 선 두께 (게이지보다 약간 두껍게) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Reload")
	float ReloadRingBackThickness = 6.f;

	/** 진행 게이지 색상 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Reload")
	FLinearColor ReloadRingColor = FLinearColor::White;

	/** 배경 링 색상 (어두운 반투명 — 게이지와 대비) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Reload")
	FLinearColor ReloadRingBackColor = FLinearColor(0.f, 0.f, 0.f, 0.5f);

private:
	UPROPERTY()
	TObjectPtr<UZombieHUDWidget> HUDWidget;
};
