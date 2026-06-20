// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieHUD.h"
#include "ZombieHUDWidget.h"
#include "Engine/Canvas.h"
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
