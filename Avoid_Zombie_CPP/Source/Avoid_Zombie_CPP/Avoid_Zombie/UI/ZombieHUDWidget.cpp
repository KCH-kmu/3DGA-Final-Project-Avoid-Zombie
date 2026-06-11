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
	if (CurrentHealth >= 7.f)
		return FLinearColor(0.f, 0.8f, 0.f, 1.f);   // 초록
	else if (CurrentHealth >= 4.f)
		return FLinearColor(1.f, 0.75f, 0.f, 1.f);  // 노랑
	else
		return FLinearColor(0.9f, 0.1f, 0.1f, 1.f); // 빨강
}

// ─── 시간 ─────────────────────────────────────────────────────────────────
void UZombieHUDWidget::SetTime_Implementation(float NewTime)
{
	DisplayTime = NewTime;
}

FText UZombieHUDWidget::GetTimeText() const
{
	const int32 TotalSec = FMath::FloorToInt(DisplayTime);
	const int32 Min      = TotalSec / 60;
	const int32 Sec      = TotalSec % 60;
	return FText::FromString(FString::Printf(TEXT("%02d:%02d"), Min, Sec));
}

// ─── 점수 ─────────────────────────────────────────────────────────────────
void UZombieHUDWidget::SetScore_Implementation(int32 NewScore)
{
	TotalScore = NewScore;
}

// ─── 킬 카운트 ────────────────────────────────────────────────────────────
void UZombieHUDWidget::SetKills_Implementation(int32 NewKills)
{
	TotalKills = NewKills;
}

// ─── 웨이브 ───────────────────────────────────────────────────────────────
void UZombieHUDWidget::SetWave_Implementation(int32 NewWave)
{
	CurrentWave = NewWave;
}
