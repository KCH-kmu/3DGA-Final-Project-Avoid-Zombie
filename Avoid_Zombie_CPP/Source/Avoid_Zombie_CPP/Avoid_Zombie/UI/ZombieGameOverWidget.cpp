// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieGameOverWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Border.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/GridPanel.h"
#include "Components/GridSlot.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Styling/CoreStyle.h"
#include "Brushes/SlateColorBrush.h"
#include "Brushes/SlateRoundedBoxBrush.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

// ─── 색상/치수 상수 ─────────────────────────────────────────────────────────
namespace
{
	// 짙은 회색 채움 (약 65% 불투명 — 뒤 게임 화면이 살짝 비침)
	const FLinearColor BgColor      = FLinearColor(0.04f, 0.04f, 0.04f, 0.65f);
	// 눈에 띄는 회색 외곽선
	const FLinearColor BorderColor  = FLinearColor(0.60f, 0.60f, 0.60f, 1.0f);
	const float        BorderWidth  = 4.f;     // 외곽선 두께(px)
	const float        PanelRadius  = 12.f;    // 모서리 둥글기(px)
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

		// ─── 패널: 단일 보더 + 둥근박스 브러시(반투명 채움 + 외곽선) ───
		// 중첩 보더를 쓰면 바깥 보더가 불투명하게 전체를 덮어 뒤가 안 비침.
		// 둥근박스 브러시 하나로 '반투명 채움 + 외곽선'을 동시에 그려 실제로 비치게 함.
		UBorder* Panel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
		Panel->SetBrush(FSlateRoundedBoxBrush(BgColor, PanelRadius, BorderColor, BorderWidth));
		Panel->SetPadding(FMargin(InnerPadding));

		UCanvasPanelSlot* PanelSlot = RootCanvas->AddChildToCanvas(Panel);
		// 가로 2/3에서 20% 축소(≈0.533), 세로 3/4에서 10% 축소(≈0.675), 화면 정중앙
		PanelSlot->SetAnchors(FAnchors(0.233333f, 0.1625f, 0.766667f, 0.8375f));
		PanelSlot->SetOffsets(FMargin(0.f));

		// ─── 세로 박스(내용) ───
		UVerticalBox* VBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
		Panel->SetContent(VBox);

		auto AddCentered = [&](UWidget* W, float TopPad)
		{
			UVerticalBoxSlot* S = VBox->AddChildToVerticalBox(W);
			S->SetHorizontalAlignment(HAlign_Center);
			S->SetVerticalAlignment(VAlign_Top);
			S->SetPadding(FMargin(0.f, TopPad, 0.f, 0.f));
		};

		// 1) 상단 'GAME OVER'
		AddCentered(MakeText(TEXT("GAME OVER"), 56, true, TitleColor), 0.f);

		// 2) 항목별 점수 — 콜론(:) 기준 2열 정렬 그리드
		//    col0: 라벨(우측 정렬) / col1: ": (카운트 단위) \u00D7(점수) = (합계)" (좌측 정렬)
		UGridPanel* Grid = WidgetTree->ConstructWidget<UGridPanel>(UGridPanel::StaticClass());
		{
			UVerticalBoxSlot* GS = VBox->AddChildToVerticalBox(Grid);
			// 오른쪽 여백 40 → 가운데에서 약 20px 왼쪽으로 이동
			GS->SetHorizontalAlignment(HAlign_Center);
			GS->SetVerticalAlignment(VAlign_Top);
			GS->SetPadding(FMargin(0.f, 40.f, 40.f, 0.f));
		}

		auto AddStatRow = [&](int32 Row, const FString& Label) -> UTextBlock*
		{
			// col0: 라벨 (우측 정렬, 콜론 앞 간격 12px)
			UTextBlock* L = MakeText(Label, 26, false, LineColor);
			L->SetJustification(ETextJustify::Right);
			UGridSlot* LS = Grid->AddChildToGrid(L, Row, 0);
			LS->SetHorizontalAlignment(HAlign_Right);
			LS->SetVerticalAlignment(VAlign_Center);
			LS->SetPadding(FMargin(0.f, 6.f, 12.f, 6.f));

			// col1: 값 (좌측 정렬) — ApplyStats가 실제 문자열 주입
			UTextBlock* V = MakeText(TEXT(":"), 26, false, LineColor);
			V->SetJustification(ETextJustify::Left);
			UGridSlot* VS = Grid->AddChildToGrid(V, Row, 1);
			VS->SetHorizontalAlignment(HAlign_Left);
			VS->SetVerticalAlignment(VAlign_Center);
			VS->SetPadding(FMargin(0.f, 6.f, 0.f, 6.f));
			return V;
		};

		KillText      = AddStatRow(0, TEXT("Kill"));
		WaveText      = AddStatRow(1, TEXT("Survive Bonus"));
		MilestoneText = AddStatRow(2, TEXT("Kill Streak Bonus"));
		HealText      = AddStatRow(3, TEXT("Heal Bonus"));

		// 3) Total Score
		TotalText = MakeText(TEXT("Total Score : 0"), 38, true, TotalColor);
		AddCentered(TotalText, 40.f);

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
		AddCentered(TryAgainButton, 44.f);

		ApplyStats();
	}

	return Super::RebuildWidget();
}

void UZombieGameOverWidget::SetGameOverStats(int32 InKills, int32 InKillScore,
	int32 InWavesCleared, int32 InWaveClearScore,
	int32 InMilestoneCount, int32 InMilestoneScore,
	int32 InHealUnits, int32 InHealPerUnit, int32 InHealBonusScore,
	int32 InTotalScore)
{
	Stat_Kills          = InKills;
	Stat_KillScore      = InKillScore;
	Stat_WavesCleared   = InWavesCleared;
	Stat_WaveClearScore = InWaveClearScore;
	Stat_MilestoneCount = InMilestoneCount;
	Stat_MilestoneScore = InMilestoneScore;
	Stat_HealUnits      = InHealUnits;
	Stat_HealPerUnit    = InHealPerUnit;
	Stat_HealBonusScore = InHealBonusScore;
	Stat_TotalScore     = InTotalScore;
	ApplyStats();
}

void UZombieGameOverWidget::ApplyStats()
{
	// 형식: ": (카운트 단위) \u00D7 (단가) = (합계)"  (\u00D7 = 수학 곱셈기호, 인코딩 안전)
	if (KillText)
		KillText->SetText(FText::FromString(FString::Printf(TEXT(": %d Kills \u00D7 10 = %d"), Stat_Kills, Stat_KillScore)));
	if (WaveText)
		WaveText->SetText(FText::FromString(FString::Printf(TEXT(": %d Waves \u00D7 100 = %d"), Stat_WavesCleared, Stat_WaveClearScore)));
	if (MilestoneText)
		MilestoneText->SetText(FText::FromString(FString::Printf(TEXT(": %d Streaks \u00D7 300 = %d"), Stat_MilestoneCount, Stat_MilestoneScore)));
	if (HealText)
		HealText->SetText(FText::FromString(FString::Printf(TEXT(": %d HP \u00D7 %d = %d"), Stat_HealUnits, Stat_HealPerUnit, Stat_HealBonusScore)));
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
