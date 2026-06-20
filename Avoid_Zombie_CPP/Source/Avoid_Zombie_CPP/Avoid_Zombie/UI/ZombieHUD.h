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

	// ─── 발동 아이템 원형 타이머 (재장전 링 스타일, 발동 슬롯 위에 겹침) ──
	/** ActiveSlot 위젯 위치에 링을 자동 정렬 (켜면 아래 Center 값 무시하고 슬롯을 따라감) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ActiveRing")
	bool bAutoAlignRingToSlot = true;

	/** 자동 정렬 OFF일 때: 화면 오른쪽 끝에서 링 '중심'까지 거리(px) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ActiveRing")
	float ActiveRingCenterFromRight = 210.f;

	/** 화면 아래 끝에서 링 '중심'까지 거리(px) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ActiveRing")
	float ActiveRingCenterFromBottom = 62.f;

	/** 링 반지름(px) — 슬롯을 감싸도록 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ActiveRing")
	float ActiveRingRadius = 42.f;

	/** 남은 시간 게이지 두께 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ActiveRing")
	float ActiveRingThickness = 4.f;

	/** 배경 링 두께 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ActiveRing")
	float ActiveRingBackThickness = 6.f;

	/** 게이지 색 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ActiveRing")
	FLinearColor ActiveRingColor = FLinearColor::White;

	/** 배경 링 색 (어두운 반투명) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ActiveRing")
	FLinearColor ActiveRingBackColor = FLinearColor(0.f, 0.f, 0.f, 0.5f);

private:
	UPROPERTY()
	TObjectPtr<UZombieHUDWidget> HUDWidget;
};
