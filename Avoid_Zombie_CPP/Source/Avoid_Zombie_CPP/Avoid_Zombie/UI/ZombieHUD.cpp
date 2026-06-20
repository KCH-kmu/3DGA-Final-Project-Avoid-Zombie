// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieHUD.h"
#include "ZombieHUDWidget.h"
#include "ZombieGameOverWidget.h"
#include "Engine/Canvas.h"
#include "Blueprint/UserWidget.h"
#include "../WeaponComponent.h"
#include "../ZombiePlayerCharacter.h"
#include "../ZombieGameState.h"

AZombieHUD::AZombieHUD() {}

void AZombieHUD::BeginPlay()
{
	Super::BeginPlay();

	// ─── 위젯 생성 ────────────────────────────────────────────────
	if (HUDWidgetClass)
	{
		HUDWidget = CreateWidget<UZombieHUDWidget>(GetOwningPlayerController(), HUDWidgetClass);
		if (HUDWidget) HUDWidget->AddToViewport();
	}

	APlayerController* PC   = GetOwningPlayerController();
	APawn*             Pawn = PC ? PC->GetPawn() : nullptr;

	// ─── 탄약 델리게이트 ─────────────────────────────────────────
	if (UWeaponComponent* Weapon = Pawn ? Pawn->FindComponentByClass<UWeaponComponent>() : nullptr)
	{
		Weapon->OnAmmoChanged.AddDynamic(this, &AZombieHUD::OnAmmoChanged);
		OnAmmoChanged(Weapon->CurrentAmmo, Weapon->MaxAmmo);
	}

	// ─── 체력 델리게이트 ─────────────────────────────────────────
	if (AZombiePlayerCharacter* Player = Cast<AZombiePlayerCharacter>(Pawn))
	{
		Player->OnHealthChanged.AddDynamic(this, &AZombieHUD::OnHealthChanged);
		OnHealthChanged(Player->CurrentHealth, Player->MaxHealth);
	}

	// ─── 시간·점수·웨이브·킬 델리게이트 ─────────────────────────
	if (AZombieGameState* GS = GetWorld() ? GetWorld()->GetGameState<AZombieGameState>() : nullptr)
	{
		GS->OnTimeUpdated.AddDynamic(this, &AZombieHUD::OnTimeUpdated);
		GS->OnScoreChanged.AddDynamic(this, &AZombieHUD::OnScoreChanged);
		GS->OnKillsChanged.AddDynamic(this, &AZombieHUD::OnKillsChanged);
		GS->OnWaveChanged.AddDynamic(this, &AZombieHUD::OnWaveChanged);
		GS->OnGameOver.AddDynamic(this, &AZombieHUD::OnGameOver);
		// 초기값
		OnTimeUpdated(GS->ElapsedTime);
		OnScoreChanged(GS->TotalScore);
		OnKillsChanged(GS->TotalKills);
		OnWaveChanged(GS->CurrentWave);
	}
}

// ─── 크로스헤어 ───────────────────────────────────────────────────────────
void AZombieHUD::DrawHUD()
{
	Super::DrawHUD();
	if (!Canvas) return;

	AZombiePlayerCharacter* Player = Cast<AZombiePlayerCharacter>(GetOwningPawn());

	// 사망(게임오버) 시 크로스헤어 숨김
	if (Player && Player->IsDead()) return;

	UWeaponComponent* Weapon = Player ? Player->WeaponComp.Get() : nullptr;
	const bool bReloading = (Weapon && Weapon->bIsReloading);

	// 공격 불가 상태(달리기 / 복귀 회전 / 재장전)면 색상 변경
	const bool bCanAttack = (!Player || Player->CanFire()) && !bReloading;
	const FLinearColor Color = bCanAttack ? CrosshairColor : DisabledCrosshairColor;

	const float CX = Canvas->ClipX * 0.5f;
	const float CY = Canvas->ClipY * 0.5f;

	// 상 / 하 / 좌 / 우 4선 (외곽선 먼저 두껍게 → 본선 덮어 그리기)
	auto DrawCrossLines = [&](const FLinearColor& C, float Thickness)
	{
		DrawLine(CX, CY - CrosshairGap, CX, CY - CrosshairGap - CrosshairSize, C, Thickness);
		DrawLine(CX, CY + CrosshairGap, CX, CY + CrosshairGap + CrosshairSize, C, Thickness);
		DrawLine(CX - CrosshairGap, CY, CX - CrosshairGap - CrosshairSize, CY, C, Thickness);
		DrawLine(CX + CrosshairGap, CY, CX + CrosshairGap + CrosshairSize, CY, C, Thickness);
	};
	DrawCrossLines(CrosshairOutlineColor, CrosshairThickness + 2.f);
	DrawCrossLines(Color, CrosshairThickness);

	// 중심점 (외곽선 포함)
	DrawRect(CrosshairOutlineColor, CX - 2.5f, CY - 2.5f, 5.f, 5.f);
	DrawRect(Color, CX - 1.5f, CY - 1.5f, 3.f, 3.f);

	// ─── 재장전 원형 타이머 (12시 방향부터 시계방향으로 채움) ───────
	if (bReloading)
	{
		const float Progress   = FMath::Clamp(Weapon->ReloadProgress, 0.f, 1.f);
		const int32 NumSegments = 48;
		const float StartAngle  = -0.5f * PI; // 12시 방향
		const float FullCircle  = 2.f * PI;

		auto DrawArcSegment = [&](float A0, float A1, const FLinearColor& ArcColor, float Thickness)
		{
			DrawLine(CX + ReloadRingRadius * FMath::Cos(A0), CY + ReloadRingRadius * FMath::Sin(A0),
			         CX + ReloadRingRadius * FMath::Cos(A1), CY + ReloadRingRadius * FMath::Sin(A1),
			         ArcColor, Thickness);
		};

		// 배경 링 (전체, 어두운 반투명)
		for (int32 i = 0; i < NumSegments; ++i)
		{
			const float A0 = StartAngle + FullCircle * (i / (float)NumSegments);
			const float A1 = StartAngle + FullCircle * ((i + 1) / (float)NumSegments);
			DrawArcSegment(A0, A1, ReloadRingBackColor, ReloadRingBackThickness);
		}

		// 진행 게이지 (밝은 색, 배경 위에 덮어 그림)
		const float ProgressAngle = FullCircle * Progress;
		const int32 Segs = FMath::Max(1, FMath::CeilToInt(NumSegments * Progress));
		for (int32 i = 0; i < Segs; ++i)
		{
			const float A0 = StartAngle + ProgressAngle * (i / (float)Segs);
			const float A1 = StartAngle + ProgressAngle * ((i + 1) / (float)Segs);
			DrawArcSegment(A0, A1, ReloadRingColor, ReloadRingThickness);
		}
	}

	// ─── 발동 중 아이템 원형 타이머 (재장전 링과 동일 스타일, 발동 슬롯 위) ───
	// 남은 시간(GetActiveTimedProgress 1→0)만큼 12시부터 시계방향 게이지가 줄어듦
	if (Weapon && Weapon->ActiveTimedItem != EItemType::None)
	{
		const float Remaining = FMath::Clamp(Weapon->GetActiveTimedProgress(), 0.f, 1.f);

		// 링 중심: 기본은 마진 값, 자동 정렬 ON이면 ActiveSlot 위젯 위치를 따라감
		float RX = Canvas->ClipX - ActiveRingCenterFromRight;
		float RY = Canvas->ClipY - ActiveRingCenterFromBottom;
		if (bAutoAlignRingToSlot && HUDWidget)
		{
			FVector2D SlotCenter;
			if (HUDWidget->GetActiveSlotViewportCenter(SlotCenter))
			{
				RX = SlotCenter.X;
				RY = SlotCenter.Y;
			}
		}

		const int32 NumSeg = 48;
		const float Start  = -0.5f * PI; // 12시 방향
		const float Full   = 2.f * PI;

		auto DrawActiveArc = [&](float A0, float A1, const FLinearColor& C, float Th)
		{
			DrawLine(RX + ActiveRingRadius * FMath::Cos(A0), RY + ActiveRingRadius * FMath::Sin(A0),
			         RX + ActiveRingRadius * FMath::Cos(A1), RY + ActiveRingRadius * FMath::Sin(A1), C, Th);
		};

		// 배경 링 (전체, 어두운 반투명)
		for (int32 i = 0; i < NumSeg; ++i)
		{
			const float A0 = Start + Full * (i / (float)NumSeg);
			const float A1 = Start + Full * ((i + 1) / (float)NumSeg);
			DrawActiveArc(A0, A1, ActiveRingBackColor, ActiveRingBackThickness);
		}

		// 남은 시간 게이지 (12시부터 시계방향, 남은 비율만큼)
		const float Ang  = Full * Remaining;
		const int32 Segs = FMath::Max(1, FMath::CeilToInt(NumSeg * Remaining));
		for (int32 i = 0; i < Segs; ++i)
		{
			const float A0 = Start + Ang * (i / (float)Segs);
			const float A1 = Start + Ang * ((i + 1) / (float)Segs);
			DrawActiveArc(A0, A1, ActiveRingColor, ActiveRingThickness);
		}
	}
}

void AZombieHUD::OnAmmoChanged(int32 Current, int32 Max)
{
	if (HUDWidget) HUDWidget->SetAmmo(Current, Max);
}

void AZombieHUD::OnHealthChanged(float Current, float Max)
{
	if (HUDWidget) HUDWidget->SetHealth(Current, Max);
}

void AZombieHUD::OnTimeUpdated(float NewTime)
{
	if (HUDWidget) HUDWidget->SetTime(NewTime);
}

void AZombieHUD::OnScoreChanged(int32 NewScore)
{
	if (HUDWidget) HUDWidget->SetScore(NewScore);
}

void AZombieHUD::OnKillsChanged(int32 NewKills)
{
	if (HUDWidget) HUDWidget->SetKills(NewKills);
}

void AZombieHUD::OnWaveChanged(int32 NewWave)
{
	if (HUDWidget) HUDWidget->SetWave(NewWave);
}

void AZombieHUD::OnGameOver()
{
	if (GameOverWidget) return; // 중복 방지

	APlayerController* PC = GetOwningPlayerController();

	// 게임오버 위젯 생성 (BP 미지정 시 C++ 기본 클래스 사용)
	TSubclassOf<UZombieGameOverWidget> Cls = GameOverWidgetClass;
	if (!Cls) Cls = UZombieGameOverWidget::StaticClass();
	GameOverWidget = CreateWidget<UZombieGameOverWidget>(PC, Cls);

	if (GameOverWidget)
	{
		// 항목별 점수 주입
		if (AZombieGameState* GS = GetWorld() ? GetWorld()->GetGameState<AZombieGameState>() : nullptr)
		{
			const int32 WavesCleared   = FMath::Max(0, GS->CurrentWave - 1);
			const int32 MilestoneCount = (GS->MilestoneBonus > 0) ? (GS->MilestoneScore / GS->MilestoneBonus) : 0;
			GameOverWidget->SetGameOverStats(
				GS->TotalKills, GS->KillScore,
				WavesCleared,   GS->WaveClearScore,
				MilestoneCount, GS->MilestoneScore,
				GS->HealBonusScore, GS->TotalScore);
		}
		GameOverWidget->AddToViewport(100); // HUD 위에

		// 마우스 커서 + UI 입력 (버튼 클릭용)
		if (PC)
		{
			PC->bShowMouseCursor = true;
			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(GameOverWidget->TakeWidget());
			Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PC->SetInputMode(Mode);
		}
	}
}
