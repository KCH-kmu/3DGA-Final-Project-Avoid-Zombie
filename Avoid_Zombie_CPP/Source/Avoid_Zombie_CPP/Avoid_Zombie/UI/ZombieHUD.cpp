// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieHUD.h"
#include "ZombieHUDWidget.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "RenderUtils.h"
#include "UObject/ConstructorHelpers.h"
#include "../WeaponComponent.h"
#include "../ZombiePlayerCharacter.h"
#include "../ZombieGameState.h"

AZombieHUD::AZombieHUD()
{
	// 아이템 아이콘 기본값 자동 로드 (BP_ZombieHUD에서 덮어쓰기 가능)
	static ConstructorHelpers::FObjectFinder<UTexture2D> HealTex(TEXT("/Game/Icon/T_Item_Health.T_Item_Health"));
	if (HealTex.Succeeded()) Icon_HealSelf = HealTex.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> ReloadTex(TEXT("/Game/Icon/T_Item_ReloadSpeed.T_Item_ReloadSpeed"));
	if (ReloadTex.Succeeded()) Icon_FireRateUp = ReloadTex.Object;

	static ConstructorHelpers::FObjectFinder<UTexture2D> FreezeTex(TEXT("/Game/Icon/T_Item_ZombieFreeze.T_Item_ZombieFreeze"));
	if (FreezeTex.Succeeded()) Icon_StunAll = FreezeTex.Object;
}

UTexture2D* AZombieHUD::GetIconForItem(EItemType Item) const
{
	switch (Item)
	{
	case EItemType::HealSelf:   return Icon_HealSelf;
	case EItemType::FireRateUp: return Icon_FireRateUp;
	case EItemType::StunAll:    return Icon_StunAll;
	default:                    return nullptr;
	}
}

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

	// ─── 보유 아이템 슬롯 (탄약 '/' 위, 크게) ────────────────────────
	// 들고 있는 아이템이 있을 때만: 회색 테두리 + 검정 반투명 배경 + 아이콘
	if (Weapon && Weapon->HeldItem != EItemType::None)
	{
		const float Size    = ItemSlotSize;
		const float B       = ItemSlotBorderThickness;
		const float CenterX = Canvas->ClipX - ItemSlotCenterFromRight; // 탄약 '/' 기준 가로 중심
		const float SlotX   = CenterX - Size * 0.5f;
		const float SlotY   = Canvas->ClipY - ItemSlotMarginBottom - Size;

		DrawRect(ItemSlotBorderColor, SlotX - B, SlotY - B, Size + 2.f * B, Size + 2.f * B);
		DrawRect(ItemSlotBgColor, SlotX, SlotY, Size, Size);
		if (UTexture2D* Icon = GetIconForItem(Weapon->HeldItem))
		{
			const float Pad = ItemSlotPadding;
			DrawTexture(Icon, SlotX + Pad, SlotY + Pad, Size - 2.f * Pad, Size - 2.f * Pad,
				0.f, 0.f, 1.f, 1.f);
		}
	}

	// ─── 발동 중 지속시간 아이템 슬롯 (탄약 왼쪽, 64px, 사각 카운트다운) ──
	if (Weapon && Weapon->ActiveTimedItem != EItemType::None)
	{
		const float Size  = ActiveSlotSize;
		const float B     = ItemSlotBorderThickness;
		const float SlotX = Canvas->ClipX - ActiveSlotMarginRight - Size;
		const float SlotY = Canvas->ClipY - ActiveSlotMarginBottom - Size;

		DrawRect(ItemSlotBorderColor, SlotX - B, SlotY - B, Size + 2.f * B, Size + 2.f * B);
		DrawRect(ItemSlotBgColor, SlotX, SlotY, Size, Size);

		const float Pad = ActiveSlotPadding;
		const float IX  = SlotX + Pad;
		const float IY  = SlotY + Pad;
		const float IS  = Size - 2.f * Pad;
		if (UTexture2D* Icon = GetIconForItem(Weapon->ActiveTimedItem))
			DrawTexture(Icon, IX, IY, IS, IS, 0.f, 0.f, 1.f, 1.f);

		// 경과분만큼 12시부터 시계방향으로 어두워지는 사각 카운트다운
		const float Elapsed = 1.f - Weapon->GetActiveTimedProgress();
		DrawSquareCountdown(IX + IS * 0.5f, IY + IS * 0.5f, IS * 0.5f, Elapsed, CountdownDarkColor);
	}
}

void AZombieHUD::DrawSquareCountdown(float CenterX, float CenterY, float HalfSize, float Elapsed, const FLinearColor& DarkColor)
{
	Elapsed = FMath::Clamp(Elapsed, 0.f, 1.f);
	if (Elapsed <= 0.f || !Canvas) return;

	const float TotalAngle = Elapsed * 2.f * PI;
	const int32 N = FMath::Max(1, FMath::CeilToInt(64.f * Elapsed)); // 세그먼트 수(부드럽게)

	// 각도(위=0, 시계방향) → 정사각형 둘레 위의 점 (모서리까지 덮도록 ray-square 교차)
	auto PerimPoint = [&](float Ang) -> FVector2D
	{
		const float dx = FMath::Sin(Ang);
		const float dy = -FMath::Cos(Ang);
		const float tx = (FMath::Abs(dx) > KINDA_SMALL_NUMBER) ? HalfSize / FMath::Abs(dx) : TNumericLimits<float>::Max();
		const float ty = (FMath::Abs(dy) > KINDA_SMALL_NUMBER) ? HalfSize / FMath::Abs(dy) : TNumericLimits<float>::Max();
		const float t  = FMath::Min(tx, ty);
		return FVector2D(CenterX + dx * t, CenterY + dy * t);
	};

	const FVector2D Center(CenterX, CenterY);
	TArray<FCanvasUVTri> Tris;
	Tris.Reserve(N);
	for (int32 i = 0; i < N; ++i)
	{
		const float A0 = TotalAngle * (i        / (float)N);
		const float A1 = TotalAngle * ((i + 1)   / (float)N);
		FCanvasUVTri T;
		T.V0_Pos = Center;          T.V0_UV = FVector2D::ZeroVector; T.V0_Color = DarkColor;
		T.V1_Pos = PerimPoint(A0);  T.V1_UV = FVector2D::ZeroVector; T.V1_Color = DarkColor;
		T.V2_Pos = PerimPoint(A1);  T.V2_UV = FVector2D::ZeroVector; T.V2_Color = DarkColor;
		Tris.Add(T);
	}

	// 반투명 블렌드로 아이콘 위에 어둡게 덮기
	FCanvasTriangleItem TriItem(FVector2D::ZeroVector, FVector2D::ZeroVector, FVector2D::ZeroVector, GWhiteTexture);
	TriItem.TriangleList = MoveTemp(Tris);
	TriItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TriItem);
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
