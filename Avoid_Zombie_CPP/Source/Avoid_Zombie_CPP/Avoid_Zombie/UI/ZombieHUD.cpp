// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieHUD.h"
#include "ZombieHUDWidget.h"
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
