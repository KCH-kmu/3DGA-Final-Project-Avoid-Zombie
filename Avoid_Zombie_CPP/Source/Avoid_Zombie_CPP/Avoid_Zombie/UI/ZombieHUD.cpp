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

	// 달리기 중에는 공격 불가 → 흐리게 표시
	FLinearColor Color = CrosshairColor;
	if (Player && Player->bIsSprinting)
	{
		Color.A *= SprintCrosshairAlpha;
	}

	const float CX = Canvas->ClipX * 0.5f;
	const float CY = Canvas->ClipY * 0.5f;

	// 상 / 하 / 좌 / 우 4선
	DrawLine(CX, CY - CrosshairGap, CX, CY - CrosshairGap - CrosshairSize, Color, CrosshairThickness);
	DrawLine(CX, CY + CrosshairGap, CX, CY + CrosshairGap + CrosshairSize, Color, CrosshairThickness);
	DrawLine(CX - CrosshairGap, CY, CX - CrosshairGap - CrosshairSize, CY, Color, CrosshairThickness);
	DrawLine(CX + CrosshairGap, CY, CX + CrosshairGap + CrosshairSize, CY, Color, CrosshairThickness);

	// 중심점
	DrawRect(Color, CX - 1.f, CY - 1.f, 2.f, 2.f);
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
