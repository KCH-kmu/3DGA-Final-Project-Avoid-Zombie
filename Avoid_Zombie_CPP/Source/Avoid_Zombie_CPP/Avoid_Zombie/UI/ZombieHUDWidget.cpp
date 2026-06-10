// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieHUDWidget.h"

// ─── 탄약 ─────────────────────────────────────────────────────────────────
void UZombieHUDWidget::SetAmmo_Implementation(int32 Current, int32 Max)
{
	CurrentAmmo = Current;
	MaxAmmo     = Max;
}

// ─── 체력 ─────────────────────────────────────────────────────────────────
void UZombieHUDWidget::SetHealth_Implementation(float Current, float Max)
{
	CurrentHealth = Current;
	MaxHealth     = Max;
}

float UZombieHUDWidget::GetHealthPercent() const
{
	if (MaxHealth <= 0.f) return 0.f;
	return FMath::Clamp(CurrentHealth / MaxHealth, 0.f, 1.f);
}

FLinearColor UZombieHUDWidget::GetHealthBarColor() const
{
	// 7~10 → 초록, 4~6 → 노랑, 1~3 → 빨강
	if (CurrentHealth >= 7.f)
		return FLinearColor(0.f, 0.8f, 0.f, 1.f);   // 초록
	else if (CurrentHealth >= 4.f)
		return FLinearColor(1.f, 0.75f, 0.f, 1.f);  // 노랑
	else
		return FLinearColor(0.9f, 0.1f, 0.1f, 1.f); // 빨강
}
