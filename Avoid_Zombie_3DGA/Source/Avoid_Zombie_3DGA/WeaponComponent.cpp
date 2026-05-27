// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "WeaponComponent.h"
#include "ZombieCharacter.h"
#include "AvoidZombieCharacter.h"
#include "AvoidZombieGameState.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = MaxAmmo;
}

void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ─── 버프 타이머 ────────────────────────────────────────────────
	if (bIsFireRateBuff)
	{
		BuffTimer -= DeltaTime;
		if (BuffTimer <= 0.f)
		{
			EndFireRateBuff();
		}
	}

	// ─── 재장전 타이머 ──────────────────────────────────────────────
	if (bIsReloading)
	{
		ReloadTimer -= DeltaTime;
		// 진행률 계산 (0 → 1)
		ReloadProgress = 1.f - FMath::Clamp(ReloadTimer / GetCurrentReloadTime(), 0.f, 1.f);

		if (ReloadTimer <= 0.f)
		{
			FinishReload();
		}
		return; // 재장전 중에는 사격 처리 안 함
	}

	// ─── 자동 사격 타이머 ────────────────────────────────────────────
	if (bIsFiring)
	{
		FireTimer -= DeltaTime;
		if (FireTimer <= 0.f)
		{
			FireOnce();
		}
	}
}

// ─── 사격 시작/중지 ───────────────────────────────────────────────────────
void UWeaponComponent::StartFire()
{
	if (bIsReloading) return;

	bIsFiring = true;
	FireTimer = 0.f; // 첫 발은 즉시 발사
}

void UWeaponComponent::StopFire()
{
	bIsFiring = false;
}

// ─── 발사 1회 ─────────────────────────────────────────────────────────────
void UWeaponComponent::FireOnce()
{
	// 탄약 없으면 자동 재장전
	if (CurrentAmmo <= 0)
	{
		StopFire();
		StartReload();
		return;
	}

	CurrentAmmo--;
	PerformLineTrace();

	// 다음 발사 딜레이 설정
	const float RPS = GetCurrentRPS();
	FireTimer = (RPS > 0.f) ? (1.f / RPS) : 0.1f;

	// 0발이 됐으면 자동 재장전
	if (CurrentAmmo <= 0)
	{
		StopFire();
		StartReload();
	}
}

// ─── LineTrace 히트 판정 ──────────────────────────────────────────────────
void UWeaponComponent::PerformLineTrace()
{
	AActor* Owner = GetOwner();
	if (!Owner) return;

	// 카메라가 바라보는 방향으로 LineTrace
	ACharacter* Character = Cast<ACharacter>(Owner);
	if (!Character) return;

	// 카메라 컴포넌트를 찾아서 시작 위치/방향 결정
	UCameraComponent* Camera = Character->FindComponentByClass<UCameraComponent>();
	FVector TraceStart;
	FVector TraceDirection;

	if (Camera)
	{
		TraceStart     = Camera->GetComponentLocation();
		TraceDirection = Camera->GetForwardVector();
	}
	else
	{
		// 폴백: 컨트롤러 회전 방향
		APlayerController* PC = Cast<APlayerController>(Character->GetController());
		if (!PC) return;
		PC->GetPlayerViewPoint(TraceStart, FRotator());
		TraceDirection = Character->GetControlRotation().Vector();
	}

	const FVector TraceEnd = TraceStart + TraceDirection * 10000.f; // 100m

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Owner); // 본인 제외

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Pawn, Params);

#if WITH_EDITOR
	// 에디터에서 디버그 라인 표시 (0.05초)
	DrawDebugLine(GetWorld(), TraceStart, bHit ? HitResult.ImpactPoint : TraceEnd,
		bHit ? FColor::Red : FColor::Green, false, 0.05f, 0, 1.f);
#endif

	if (bHit)
	{
		AZombieCharacter* Zombie = Cast<AZombieCharacter>(HitResult.GetActor());
		if (Zombie)
		{
			Zombie->TakeDamageAmount(BaseDamagePerBullet);
		}
	}
}

// ─── 재장전 ───────────────────────────────────────────────────────────────
void UWeaponComponent::StartReload()
{
	// 이미 재장전 중이거나 탄약이 가득 차면 무시
	if (bIsReloading)    return;
	if (CurrentAmmo >= MaxAmmo) return;

	bIsReloading    = true;
	ReloadProgress  = 0.f;
	ReloadTimer     = GetCurrentReloadTime();

	UE_LOG(LogTemp, Log, TEXT("[Weapon] 재장전 시작 (%.1f초)"), ReloadTimer);
}

void UWeaponComponent::FinishReload()
{
	bIsReloading   = false;
	ReloadProgress = 1.f;
	CurrentAmmo    = MaxAmmo;

	UE_LOG(LogTemp, Log, TEXT("[Weapon] 재장전 완료"));
}

// ─── 아이템 ───────────────────────────────────────────────────────────────
void UWeaponComponent::ReceiveItem(EItemType ItemType)
{
	HeldItem = ItemType;
	UE_LOG(LogTemp, Log, TEXT("[Weapon] 아이템 획득: %d"), (int32)ItemType);
}

void UWeaponComponent::UseHeldItem()
{
	if (HeldItem == EItemType::None) return;

	UWorld* World = GetWorld();
	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());

	switch (HeldItem)
	{
	// ─── 전체 스턴 3초 ──────────────────────────────────────────────
	case EItemType::StunAll:
	{
		// 월드에 존재하는 모든 좀비를 3초 스턴
		TArray<AActor*> Zombies;
		UGameplayStatics::GetAllActorsOfClass(World, AZombieCharacter::StaticClass(), Zombies);
		for (AActor* Actor : Zombies)
		{
			AZombieCharacter* Zombie = Cast<AZombieCharacter>(Actor);
			if (Zombie) Zombie->ApplyStun(3.f);
		}
		UE_LOG(LogTemp, Log, TEXT("[Item] 전체 스턴 사용 (%d마리)"), Zombies.Num());
		break;
	}

	// ─── 발사속도/재장전 버프 5초 ───────────────────────────────────
	case EItemType::FireRateUp:
	{
		bIsFireRateBuff = true;
		BuffTimer       = BuffDuration;
		UE_LOG(LogTemp, Log, TEXT("[Item] 발사속도 버프 사용 (%.0f초)"), BuffDuration);
		break;
	}

	// ─── 체력 2 회복 ─────────────────────────────────────────────────
	case EItemType::HealSelf:
	{
		if (AAvoidZombieCharacter* Player = Cast<AAvoidZombieCharacter>(OwnerCharacter))
		{
			Player->HealHealth(2.f);
		}
		UE_LOG(LogTemp, Log, TEXT("[Item] 체력 2 회복 사용"));
		break;
	}

	default:
		break;
	}

	// 사용 후 아이템 초기화
	HeldItem = EItemType::None;
}

void UWeaponComponent::EndFireRateBuff()
{
	bIsFireRateBuff = false;
	UE_LOG(LogTemp, Log, TEXT("[Weapon] 발사속도 버프 종료"));
}

// ─── 현재 스펙 반환 ───────────────────────────────────────────────────────
float UWeaponComponent::GetCurrentRPS() const
{
	return bIsFireRateBuff ? BuffRPS : BaseRPS;
}

float UWeaponComponent::GetCurrentReloadTime() const
{
	return bIsFireRateBuff ? BuffReloadTime : BaseReloadTime;
}
