// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieHUDWidget.h"
#include "Engine/Texture2D.h"
#include "UObject/ConstructorHelpers.h"
#include "../WeaponComponent.h"
#include "../ZombiePlayerCharacter.h"

UZombieHUDWidget::UZombieHUDWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// 아이템 아이콘 기본값 자동 로드 (WBP_ZombieHUD에서 덮어쓰기 가능)
	static ConstructorHelpers::FObjectFinder<UTexture2D> HealTex(TEXT("/Game/Icon/T_Item_Health.T_Item_Health"));
	if (HealTex.Succeeded()) Icon_HealSelf = HealTex.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> ReloadTex(TEXT("/Game/Icon/T_Item_ReloadSpeed.T_Item_ReloadSpeed"));
	if (ReloadTex.Succeeded()) Icon_FireRateUp = ReloadTex.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> FreezeTex(TEXT("/Game/Icon/T_Item_ZombieFreeze.T_Item_ZombieFreeze"));
	if (FreezeTex.Succeeded()) Icon_StunAll = FreezeTex.Object;
}

// ─── 아이템 (보유 / 발동 중) ────────────────────────────────────────────────
UWeaponComponent* UZombieHUDWidget::GetWeapon() const
{
	if (AZombiePlayerCharacter* Player = Cast<AZombiePlayerCharacter>(GetOwningPlayerPawn()))
		return Player->WeaponComp;
	return nullptr;
}

UTexture2D* UZombieHUDWidget::GetIconForItem(EItemType Item) const
{
	switch (Item)
	{
	case EItemType::HealSelf:   return Icon_HealSelf;
	case EItemType::FireRateUp: return Icon_FireRateUp;
	case EItemType::StunAll:    return Icon_StunAll;
	default:                    return nullptr;
	}
}

bool UZombieHUDWidget::HasHeldItem() const
{
	const UWeaponComponent* W = GetWeapon();
	return W && W->HeldItem != EItemType::None;
}

UTexture2D* UZombieHUDWidget::GetHeldItemIcon() const
{
	const UWeaponComponent* W = GetWeapon();
	return W ? GetIconForItem(W->HeldItem) : nullptr;
}

bool UZombieHUDWidget::HasActiveBuff() const
{
	const UWeaponComponent* W = GetWeapon();
	return W && W->ActiveTimedItem != EItemType::None;
}

UTexture2D* UZombieHUDWidget::GetActiveBuffIcon() const
{
	const UWeaponComponent* W = GetWeapon();
	return W ? GetIconForItem(W->ActiveTimedItem) : nullptr;
}

float UZombieHUDWidget::GetActiveBuffProgress() const
{
	const UWeaponComponent* W = GetWeapon();
	return W ? W->GetActiveTimedProgress() : 0.f;
}

float UZombieHUDWidget::GetActiveBuffElapsed() const
{
	return 1.f - GetActiveBuffProgress();
}

FLinearColor UZombieHUDWidget::GetActiveBuffTint() const
{
	// Elapsed 0(방금 발동)=밝게(흰색) → 1(종료 직전)=어둡게(짙은 회색)
	const float B = FMath::Lerp(1.0f, 0.3f, GetActiveBuffElapsed());
	return FLinearColor(B, B, B, 1.0f);
}

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
	return FText::FromString(FString::Printf(TEXT("PlayTime : %02d:%02d"), Min, Sec));
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

FText UZombieHUDWidget::GetKillsText() const
{
	return FText::FromString(FString::Printf(TEXT("Kill : %d"), TotalKills));
}

FText UZombieHUDWidget::GetScoreText() const
{
	return FText::FromString(FString::Printf(TEXT("Score : %d"), TotalScore));
}

// ─── 웨이브 ───────────────────────────────────────────────────────────────
void UZombieHUDWidget::SetWave_Implementation(int32 NewWave)
{
	CurrentWave = NewWave;
}
