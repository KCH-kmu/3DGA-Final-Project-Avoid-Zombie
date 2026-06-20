// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieGameOverWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Border.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Styling/CoreStyle.h"
#include "Brushes/SlateColorBrush.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

// ─── 색상/치수 상수 ─────────────────────────────────────────────────────────
namespace
{
	// 짙은 회색 배경 (약 80% 불투명 — 뒤 게임 화면이 살짝 비침)
	const FLinearColor BgColor      = FLinearColor(0.06f, 0.06f, 0.06f, 0.8f);
	// 눈에 띄는 굵은 회색 보더
	const FLinearColor BorderColor  = FLinearColor(0.55f, 0.55f, 0.55f, 1.0f);
	const float        BorderWidth  = 5.f;     // 보더 두께(px)
	const float        InnerPadding = 36.f;    // 내부 여백(px)

	const FLinearColor TitleColor   = FLinearColor(0.92f, 0.18f, 0.18f, 1.0f); // GAME OVER 빨강
	const FLinearColor LineColor    = FLinearColor(0.92f, 0.92f, 0.92f, 1.0f); // 항목 텍스트
	const FLinearColor TotalColor   = FLinearColor(1.0f,  0.84f, 0.25f, 1.0f); // Total 금색
}

UTextBlock* UZombieGameOverWidget::MakeText(const FString& InText, int32 FontSize, bool bBold, const FLinearColor& Color)
{
	UTextBlock* T = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
	T->SetText(FText::FromString(InText));
	T->SetFont(FCoreStyle::GetDefaultFontStyle(bBold ? "Bold" : "Regular", FontSize));
	T->SetColorAndOpacity(FSlateColor(Color));
	T->SetJustification(ETextJustify::Center);
	return T;
}

TSharedRef<SWidget> UZombieGameOverWidget::RebuildWidget()
{
	// 순수 C++ 위젯이라 WidgetTree가 없을 수 있어 직접 생성
	if (!WidgetTree)
		WidgetTree = NewObject<UWidgetTree>(this, TEXT("WidgetTree"));

	if (!RootCanvas)
	{
		RootCanvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
		WidgetTree->RootWidget = RootCanvas;

		// ─── 바깥 보더(프레임=회색) : 화면 정중앙, 가로 2/3 · 세로 3/4 ───
		UBorder* OuterBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
		OuterBorder->SetBrushColor(BorderColor);
		OuterBorder->SetPadding(FMargin(BorderWidth)); // 이 여백이 그대로 보더 두께가 됨

		UCanvasPanelSlot* OuterSlot = RootCanvas->AddChildToCanvas(OuterBorder);
		// 앵커를 중앙 2/3 × 3/4 영역으로: min(1/6, 1/8) ~ max(5/6, 7/8)
		OuterSlot->SetAnchors(FAnchors(1.f / 6.f, 1.f / 8.f, 5.f / 6.f, 7.f / 8.f));
		OuterSlot->SetOffsets(FMargin(0.f)); // 앵커 영역을 꽉 채움

		// ─── 안쪽 보더(배경=짙은 회색 80%) ───
		UBorder* InnerBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
		InnerBorder->SetBrushColor(BgColor);
		InnerBorder->SetPadding(FMargin(InnerPadding));
		OuterBorder->SetContent(InnerBorder);

		// ─── 세로 박스(내용) ───
		UVerticalBox* VBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
		InnerBorder->SetContent(VBox);

		auto AddLine = [&](UWidget* W, float TopPad, EVerticalAlignment VA = VAlign_Top)
		{
			UVerticalBoxSlot* S = VBox->AddChildToVerticalBox(W);
			S->SetHorizontalAlignment(HAlign_Center);
			S->SetVerticalAlignment(VA);
			S->SetPadding(FMargin(0.f, TopPad, 0.f, 0.f));
			return S;
		};

		// 1) 상단 'GAME OVER'
		AddLine(MakeText(TEXT("GAME OVER"), 56, true, TitleColor), 0.f);

		// 2) 항목별 점수 (RebuildWidget 직후 ApplyStats가 실제 값 주입)
		KillText      = MakeText(TEXT("Kill : 10 * 0 = 0"),       26, false, LineColor);
		WaveText      = MakeText(TEXT("Wave Clear : 100 * 0 = 0"),26, false, LineColor);
		MilestoneText = MakeText(TEXT("Milestone : 300 * 0 = 0"), 26, false, LineColor);
		HealText      = MakeText(TEXT("Heal Bonus : +0"),         26, false, LineColor);
		AddLine(KillText,      40.f);
		AddLine(WaveText,      14.f);
		AddLine(MilestoneText, 14.f);
		AddLine(HealText,      14.f);

		// 3) Total Score
		TotalText = MakeText(TEXT("Total Score : 0"), 38, true, TotalColor);
		AddLine(TotalText, 40.f);

		// 4) Try Again 버튼 (흰색 배경, 가운데)
		TryAgainButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		{
			FButtonStyle Style;
			Style.SetNormal (FSlateColorBrush(FLinearColor::White));
			Style.SetHovered(FSlateColorBrush(FLinearColor(0.85f, 0.85f, 0.85f, 1.f)));
			Style.SetPressed(FSlateColorBrush(FLinearColor(0.70f, 0.70f, 0.70f, 1.f)));
			Style.NormalPadding  = FMargin(48.f, 14.f);
			Style.PressedPadding = FMargin(48.f, 14.f);
			TryAgainButton->SetStyle(Style);
		}
		TryAgainButton->SetContent(MakeText(TEXT("Try Again"), 28, true, FLinearColor(0.05f, 0.05f, 0.05f, 1.f)));
		TryAgainButton->OnClicked.AddDynamic(this, &UZombieGameOverWidget::OnTryAgainClicked);
		AddLine(TryAgainButton, 44.f);

		ApplyStats();
	}

	return Super::RebuildWidget();
}

void UZombieGameOverWidget::SetGameOverStats(int32 InKills, int32 InKillScore,
	int32 InWavesCleared, int32 InWaveClearScore,
	int32 InMilestoneCount, int32 InMilestoneScore,
	int32 InHealBonusScore, int32 InTotalScore)
{
	Stat_Kills          = InKills;
	Stat_KillScore      = InKillScore;
	Stat_WavesCleared   = InWavesCleared;
	Stat_WaveClearScore = InWaveClearScore;
	Stat_MilestoneCount = InMilestoneCount;
	Stat_MilestoneScore = InMilestoneScore;
	Stat_HealBonusScore = InHealBonusScore;
	Stat_TotalScore     = InTotalScore;
	ApplyStats();
}

void UZombieGameOverWidget::ApplyStats()
{
	if (KillText)
		KillText->SetText(FText::FromString(FString::Printf(TEXT("Kill : 10 * %d = %d"), Stat_Kills, Stat_KillScore)));
	if (WaveText)
		WaveText->SetText(FText::FromString(FString::Printf(TEXT("Wave Clear : 100 * %d = %d"), Stat_WavesCleared, Stat_WaveClearScore)));
	if (MilestoneText)
		MilestoneText->SetText(FText::FromString(FString::Printf(TEXT("Milestone : 300 * %d = %d"), Stat_MilestoneCount, Stat_MilestoneScore)));
	if (HealText)
		HealText->SetText(FText::FromString(FString::Printf(TEXT("Heal Bonus : +%d"), Stat_HealBonusScore)));
	if (TotalText)
		TotalText->SetText(FText::FromString(FString::Printf(TEXT("Total Score : %d"), Stat_TotalScore)));
}

void UZombieGameOverWidget::OnTryAgainClicked()
{
	if (APlayerController* PC = GetOwningPlayer())
	{
		PC->bShowMouseCursor = false;
		PC->SetInputMode(FInputModeGameOnly());
	}

	// 현재 레벨 재시작
	const FString LevelName = UGameplayStatics::GetCurrentLevelName(this, true);
	UGameplayStatics::OpenLevel(this, FName(*LevelName));
}
