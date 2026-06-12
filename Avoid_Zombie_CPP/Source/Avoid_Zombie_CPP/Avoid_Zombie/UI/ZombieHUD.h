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
	float CrosshairSize = 8.f;

	/** 중심에서 선까지 간격 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	float CrosshairGap = 6.f;

	/** 선 두께 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	float CrosshairThickness = 2.f;

	/** 기본 색상 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	FLinearColor CrosshairColor = FLinearColor::White;

	/** 달리기 중(공격 불가) 크로스헤어 투명도 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Crosshair")
	float SprintCrosshairAlpha = 0.25f;

private:
	UPROPERTY()
	TObjectPtr<UZombieHUDWidget> HUDWidget;
};
