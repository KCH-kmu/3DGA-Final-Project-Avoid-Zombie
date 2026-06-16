// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "WeaponComponent.h"
#include "ZombieCharacter.h"
#include "ZombiePlayerCharacter.h"
#include "ZombieGameState.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = MaxAmmo;
	OnAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
}

void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ─── 버프 타이머 ────────────────────────────────────────────────
	if (bIsFireRateBuff)
	{
		BuffTimer -= DeltaTime;
		if (BuffTimer <= 0.f) EndFireRateBuff();
	}

	// ─── 재장전 타이머 ──────────────────────────────────────────────
	if (bIsReloading)
	{
		ReloadTimer -= DeltaTime;
		// 분모는 재장전 시작 때 고정한 값 사용 (몽타주 재생속도·완료시점과 일치)
		const float Denom = (CurrentReloadDuration > 0.f) ? CurrentReloadDuration : GetCurrentReloadTime();
		ReloadProgress = 1.f - FMath::Clamp(ReloadTimer / Denom, 0.f, 1.f);
		if (ReloadTimer <= 0.f) FinishReload();
		return;
	}

	// ─── 자동 사격 타이머 ────────────────────────────────────────────
	if (bIsFiring)
	{
		FireTimer -= DeltaTime;
		if (FireTimer <= 0.f) FireOnce();
	}
}

// ─────────────────────────────────────────────────────────────────────────────
void UWeaponComponent::StartFire()
{
	if (bIsReloading) return;
	if (bIsFiring) return; // 이미 발사 중이면 무시 (FireTimer 리셋 방지 → 매 틱 호출해도 안전)
	bIsFiring = true;
	FireTimer = 0.f; // 첫 발은 즉시 발사
}

void UWeaponComponent::StopFire()
{
	bIsFiring = false;
}

void UWeaponComponent::FireOnce()
{
	if (CurrentAmmo <= 0)
	{
		StopFire();
		StartReload();
		return;
	}

	CurrentAmmo--;
	OnAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
	PerformLineTrace();
	OnWeaponFired.Broadcast(); // 발사 몽타주 재생 트리거 (캐릭터가 바인딩)

	FireTimer = (GetCurrentRPS() > 0.f) ? (1.f / GetCurrentRPS()) : 0.1f;

	if (CurrentAmmo <= 0)
	{
		StopFire();
		StartReload();
	}
}

// ─── LineTrace 히트 판정 ──────────────────────────────────────────────────
void UWeaponComponent::PerformLineTrace()
{
	ACharacter* OwnerChar = Cast<ACharacter>(GetOwner());
	if (!OwnerChar) return;

	UCameraComponent* Camera = OwnerChar->FindComponentByClass<UCameraComponent>();
	FVector Start, Dir;

	if (Camera)
	{
		Start = Camera->GetComponentLocation();
		Dir   = Camera->GetForwardVector();
	}
	else
	{
		APlayerController* PC = Cast<APlayerController>(OwnerChar->GetController());
		if (!PC) return;
		FRotator Rot;
		PC->GetPlayerViewPoint(Start, Rot);
		Dir = Rot.Vector();
	}

	const FVector End = Start + Dir * 10000.f;

	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());

	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Pawn, Params);

#if WITH_EDITOR
	DrawDebugLine(GetWorld(), Start, bHit ? Hit.ImpactPoint : End,
		bHit ? FColor::Red : FColor::Green, false, 0.05f, 0, 1.f);
#endif

	if (bHit)
	{
		if (AZombieCharacter* Zombie = Cast<AZombieCharacter>(Hit.GetActor()))
			Zombie->TakeDamageAmount(BaseDamagePerBullet);
	}
}

// ─── 재장전 ───────────────────────────────────────────────────────────────
void UWeaponComponent::StartReload()
{
	if (bIsReloading || CurrentAmmo >= MaxAmmo) return;
	bIsReloading          = true;
	ReloadProgress        = 0.f;
	ReloadTimer           = GetCurrentReloadTime();
	CurrentReloadDuration = ReloadTimer; // 진행률 분모로 고정 (도중 버프 만료와 무관)
	OnReloadStarted.Broadcast(ReloadTimer); // 재장전 몽타주 재생 트리거 (수동/자동 모두 이 경로)
	UE_LOG(LogTemp, Log, TEXT("[Weapon] 재장전 시작 (%.1f초)"), ReloadTimer);
}

void UWeaponComponent::FinishReload()
{
	bIsReloading   = false;
	ReloadProgress = 1.f;
	CurrentAmmo    = MaxAmmo;
	OnAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
	UE_LOG(LogTemp, Log, TEXT("[Weapon] 재장전 완료"));
}

// ─── 아이템 ───────────────────────────────────────────────────────────────
void UWeaponComponent::ReceiveItem(EItemType ItemType)
{
	HeldItem = ItemType;
}

void UWeaponComponent::UseHeldItem()
{
	if (HeldItem == EItemType::None) return;

	switch (HeldItem)
	{
	case EItemType::StunAll:
	{
		TArray<AActor*> Zombies;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AZombieCharacter::StaticClass(), Zombies);
		for (AActor* A : Zombies)
			if (AZombieCharacter* Z = Cast<AZombieCharacter>(A))
				Z->ApplyStun(3.f);
		UE_LOG(LogTemp, Log, TEXT("[Item] 전체 스턴 (%d마리)"), Zombies.Num());
		break;
	}
	case EItemType::FireRateUp:
		bIsFireRateBuff = true;
		BuffTimer       = BuffDuration;
		UE_LOG(LogTemp, Log, TEXT("[Item] 발사속도 버프 (%.0f초)"), BuffDuration);
		break;

	case EItemType::HealSelf:
		if (AZombiePlayerCharacter* Player = Cast<AZombiePlayerCharacter>(GetOwner()))
			Player->HealHealth(2.f);
		UE_LOG(LogTemp, Log, TEXT("[Item] 체력 2 회복"));
		break;

	default: break;
	}

	HeldItem = EItemType::None;
}

void UWeaponComponent::EndFireRateBuff()
{
	bIsFireRateBuff = false;
	UE_LOG(LogTemp, Log, TEXT("[Weapon] 발사속도 버프 종료"));
}

float UWeaponComponent::GetCurrentRPS()        const { return bIsFireRateBuff ? BuffRPS        : BaseRPS;        }
float UWeaponComponent::GetCurrentReloadTime() const { return bIsFireRateBuff ? BuffReloadTime : BaseReloadTime; }
