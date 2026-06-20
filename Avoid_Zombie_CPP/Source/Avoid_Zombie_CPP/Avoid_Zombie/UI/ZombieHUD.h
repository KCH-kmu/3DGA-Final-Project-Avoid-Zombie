// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ZombieHUD.generated.h"

class UZombieHUDWidget;
class UTexture2D;
enum class EItemType : uint8;

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

	// ─── 아이템 아이콘 (생성자에서 자동 로드, BP에서 덮어쓰기 가능) ──
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	TObjectPtr<UTexture2D> Icon_HealSelf;

	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	TObjectPtr<UTexture2D> Icon_FireRateUp;

	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	TObjectPtr<UTexture2D> Icon_StunAll;

	// ─── 보유 아이템 슬롯 (탄약 '/' 위, 크게) ──────────────────────
	/** 슬롯 한 변 길이(px) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	float ItemSlotSize = 220.f;

	/** 화면 오른쪽 끝에서 슬롯 '가로 중심'까지 거리(px) — 탄약 '/'에 맞춤 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	float ItemSlotCenterFromRight = 105.f;

	/** 화면 아래 끝에서 슬롯 아래까지 거리(px) — 탄약 위로 올리려면 키움 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	float ItemSlotMarginBottom = 100.f;

	/** 외곽 테두리 두께(px) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	float ItemSlotBorderThickness = 2.f;

	/** 아이콘 안쪽 여백(px) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	float ItemSlotPadding = 12.f;

	/** 배경색 (검정, 뒤가 비치도록 투명하게) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	FLinearColor ItemSlotBgColor = FLinearColor(0.f, 0.f, 0.f, 0.35f);

	/** 외곽 테두리 색 (회색) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|Item")
	FLinearColor ItemSlotBorderColor = FLinearColor(0.5f, 0.5f, 0.5f, 1.f);

	// ─── 발동 중 지속시간 아이템 슬롯 (탄약 왼쪽, 64px) ────────────
	/** 발동 슬롯 한 변 길이(px) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ItemActive")
	float ActiveSlotSize = 64.f;

	/** 화면 오른쪽 끝에서 발동 슬롯 오른쪽까지 거리(px) — 탄약 왼쪽에 오도록 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ItemActive")
	float ActiveSlotMarginRight = 185.f;

	/** 화면 아래 끝에서 발동 슬롯 아래까지 거리(px) — 탄약 높이에 맞춤 */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ItemActive")
	float ActiveSlotMarginBottom = 30.f;

	/** 발동 슬롯 아이콘 여백(px) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ItemActive")
	float ActiveSlotPadding = 6.f;

	/** 카운트다운 어두워지는 색 (검정 반투명) */
	UPROPERTY(EditDefaultsOnly, Category = "HUD|ItemActive")
	FLinearColor CountdownDarkColor = FLinearColor(0.f, 0.f, 0.f, 0.6f);

	/** 아이템 종류 → 아이콘 텍스처 */
	UTexture2D* GetIconForItem(EItemType Item) const;

	/** 정사각형 위에 '12시부터 시계방향'으로 어두워지는 카운트다운 부채꼴.
	 *  Elapsed: 0=안 어두움 → 1=전체 어두움 */
	void DrawSquareCountdown(float CenterX, float CenterY, float HalfSize, float Elapsed, const FLinearColor& DarkColor);

private:
	UPROPERTY()
	TObjectPtr<UZombieHUDWidget> HUDWidget;
};
