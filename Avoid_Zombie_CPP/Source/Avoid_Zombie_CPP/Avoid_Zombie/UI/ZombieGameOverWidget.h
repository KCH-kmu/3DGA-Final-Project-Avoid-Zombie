// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZombieGameOverWidget.generated.h"

class UCanvasPanel;
class UVerticalBox;
class UGridPanel;
class UTextBlock;
class UButton;

/**
 * 게임 오버 화면 (C++로 위젯 트리 직접 생성 — 별도 UMG 에셋 불필요)
 *
 * 레이아웃:
 * - 가로 2/3 · 세로 3/4 크기, 화면 정중앙
 * - 짙은 회색 배경(약 80% 불투명) + 눈에 띄는 굵은 회색 보더
 * - 상단 'GAME OVER'
 * - 항목별 점수 (Kill / Wave Clear / Milestone / Heal Bonus)
 * - 하단 Total Score
 * - 그 아래 가운데 'Try Again' 버튼 (흰색 배경)
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API UZombieGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** 게임오버 항목별 점수 주입 (HUD가 호출). 트리가 아직 안 만들어졌으면 값만 저장 후 RebuildWidget에서 반영 */
	void SetGameOverStats(int32 InKills, int32 InKillScore,
	                      int32 InWavesCleared, int32 InWaveClearScore,
	                      int32 InMilestoneCount, int32 InMilestoneScore,
	                      int32 InHealUnits, int32 InHealPerUnit, int32 InHealBonusScore,
	                      int32 InTotalScore);

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

	UFUNCTION()
	void OnTryAgainClicked();

private:
	// ─── 동적으로 채우는 텍스트/버튼 ───────────────────────────────
	UPROPERTY() TObjectPtr<UTextBlock> KillText;
	UPROPERTY() TObjectPtr<UTextBlock> WaveText;
	UPROPERTY() TObjectPtr<UTextBlock> MilestoneText;
	UPROPERTY() TObjectPtr<UTextBlock> HealText;
	UPROPERTY() TObjectPtr<UTextBlock> TotalText;
	UPROPERTY() TObjectPtr<UButton>    TryAgainButton;
	UPROPERTY() TObjectPtr<UCanvasPanel> RootCanvas;

	// ─── 저장된 통계값 ──────────────────────────────────────────────
	int32 Stat_Kills          = 0;
	int32 Stat_KillScore      = 0;
	int32 Stat_WavesCleared   = 0;
	int32 Stat_WaveClearScore = 0;
	int32 Stat_MilestoneCount = 0;
	int32 Stat_MilestoneScore = 0;
	int32 Stat_HealUnits      = 0;
	int32 Stat_HealPerUnit    = 0;
	int32 Stat_HealBonusScore = 0;
	int32 Stat_TotalScore     = 0;

	/** 텍스트 블록 생성 헬퍼 */
	UTextBlock* MakeText(const FString& InText, int32 FontSize, bool bBold, const FLinearColor& Color);

	/** 저장된 통계값을 텍스트에 반영 (트리가 만들어진 뒤에만 동작) */
	void ApplyStats();
};
