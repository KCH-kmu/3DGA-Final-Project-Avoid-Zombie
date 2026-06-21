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

		// 2) 항목별 점수 — 8열 표: [라벨][:][숫자][단위][곱셈][단가][=][합계]
		//    기호( : 곱셈 = )는 각자 독립 열이라 세로로 정렬됨(앵커).
		//    기호 사이 항목은 양쪽으로 붙임(숫자=왼쪽 기호 쪽, 단위=오른쪽 기호 쪽), 합계는 좌측정렬.
		const FString TimesSym = FString::Chr(0x00D7); // 곱셈기호(런타임 생성 — 소스 인코딩 무관)

		UGridPanel* Grid = WidgetTree->ConstructWidget<UGridPanel>(UGridPanel::StaticClass());
		{
			UVerticalBoxSlot* GS = VBox->AddChildToVerticalBox(Grid);
			GS->SetHorizontalAlignment(HAlign_Center);
			GS->SetVerticalAlignment(VAlign_Top);
			GS->SetPadding(FMargin(0.f, 40.f, 0.f, 0.f));
		}

		const FMargin SymPad(8.f, 6.f, 8.f, 6.f);    // 기호 열: 좌우 간격 넉넉히
		const FMargin CellPad(2.f, 6.f, 2.f, 6.f);   // 일반 셀
		const FMargin NumPad(2.f, 6.f, 22.f, 6.f);   // 숫자 셀: 뒤에 ~20px 간격(긴 단위 'Streaks'와도 안 붙게)

		// 한 셀 추가 헬퍼
		auto AddCell = [&](int32 Row, int32 Col, const FString& Text,
		                   EHorizontalAlignment HA, const FMargin& Pad) -> UTextBlock*
		{
			UTextBlock* T = MakeText(Text, 26, false, LineColor);
			T->SetJustification(HA == HAlign_Right ? ETextJustify::Right
			                  : HA == HAlign_Left  ? ETextJustify::Left
			                                       : ETextJustify::Center);
			UGridSlot* S = Grid->AddChildToGrid(T, Row, Col);
			S->SetHorizontalAlignment(HA);
			S->SetVerticalAlignment(VAlign_Center);
			S->SetPadding(Pad);
			return T;
		};

		// 한 행 추가: 라벨/단위는 고정, 숫자·단가·합계 셀은 배열에 저장(ApplyStats가 채움)
		auto AddRow = [&](int32 Row, const FString& Label, const FString& Unit)
		{
			AddCell(Row, 0, Label,     HAlign_Right,  CellPad);                  // 라벨(→ : 쪽)
			AddCell(Row, 1, TEXT(":"), HAlign_Center, SymPad);                   // :
			NumCells.Add(  AddCell(Row, 2, TEXT("0"), HAlign_Left,   NumPad) );  // 숫자(: 쪽, 뒤 간격 확보)
			AddCell(Row, 3, Unit,      HAlign_Right,  CellPad);                  // 단위(곱셈 쪽)
			AddCell(Row, 4, TimesSym,  HAlign_Center, SymPad);                   // 곱셈
			PerCells.Add(  AddCell(Row, 5, TEXT("0"), HAlign_Center, CellPad) ); // 단가
			AddCell(Row, 6, TEXT("="), HAlign_Center, SymPad);                   // =
			TotalCells.Add(AddCell(Row, 7, TEXT("0"), HAlign_Left,   CellPad) ); // 합계(= 쪽, 좌측정렬)
		};

		AddRow(0, TEXT("Kill"),              TEXT("Kills"));
		AddRow(1, TEXT("Survive Bonus"),     TEXT("Waves"));
		AddRow(2, TEXT("Kill Streak Bonus"), TEXT("Streaks"));
		AddRow(3, TEXT("Overheal Bonus"),    TEXT("HP"));

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
	auto SetCell = [](const TArray<TObjectPtr<UTextBlock>>& Cells, int32 i, int32 Val)
	{
		if (Cells.IsValidIndex(i) && Cells[i])
			Cells[i]->SetText(FText::FromString(FString::FromInt(Val)));
	};

	// 숫자(카운트)
	SetCell(NumCells, 0, Stat_Kills);
	SetCell(NumCells, 1, Stat_WavesCleared);
	SetCell(NumCells, 2, Stat_MilestoneCount);
	SetCell(NumCells, 3, Stat_HealUnits);

	// 단가 (Kill/Survive/Streak는 고정값, Heal은 데이터로 받은 HP당 점수)
	SetCell(PerCells, 0, 10);
	SetCell(PerCells, 1, 100);
	SetCell(PerCells, 2, 300);
	SetCell(PerCells, 3, Stat_HealPerUnit);

	// 항목 합계
	SetCell(TotalCells, 0, Stat_KillScore);
	SetCell(TotalCells, 1, Stat_WaveClearScore);
	SetCell(TotalCells, 2, Stat_MilestoneScore);
	SetCell(TotalCells, 3, Stat_HealBonusScore);

	// 하단 총점
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
