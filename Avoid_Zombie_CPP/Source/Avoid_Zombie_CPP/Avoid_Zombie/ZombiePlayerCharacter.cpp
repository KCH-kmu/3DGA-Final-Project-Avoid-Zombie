// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombiePlayerCharacter.h"
#include "WeaponComponent.h"
#include "ZombieGameMode.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Kismet/GameplayStatics.h"

AZombiePlayerCharacter::AZombiePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// ─── 스프링암 & 카메라 ───────────────────────────────────────────
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// ─── 무기 컴포넌트 ──────────────────────────────────────────────
	WeaponComp = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComp"));

	// ─── 이동 설정 ───────────────────────────────────────────────────
	// 캐릭터가 카메라 방향(마우스 방향)을 바라보도록 설정
	bUseControllerRotationYaw   = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll  = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->MaxWalkSpeed = 200.f;
}

void AZombiePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	// Enhanced Input 매핑 컨텍스트 등록
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Sub =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			if (MappingContext)
				Sub->AddMappingContext(MappingContext, 0);
		}
	}
}

void AZombiePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
			EIC->BindAction(MoveAction,   ETriggerEvent::Triggered, this, &AZombiePlayerCharacter::Move);
		if (LookAction)
			EIC->BindAction(LookAction,   ETriggerEvent::Triggered, this, &AZombiePlayerCharacter::Look);
		if (SprintAction)
		{
			EIC->BindAction(SprintAction, ETriggerEvent::Started,   this, &AZombiePlayerCharacter::StartSprint);
			EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AZombiePlayerCharacter::StopSprint);
		}
		if (FireAction)
		{
			EIC->BindAction(FireAction,   ETriggerEvent::Started,   this, &AZombiePlayerCharacter::StartFire);
			EIC->BindAction(FireAction,   ETriggerEvent::Completed, this, &AZombiePlayerCharacter::StopFire);
		}
		if (ReloadAction)
			EIC->BindAction(ReloadAction,   ETriggerEvent::Started, this, &AZombiePlayerCharacter::Reload);
		if (UseItemAction)
			EIC->BindAction(UseItemAction,  ETriggerEvent::Started, this, &AZombiePlayerCharacter::UseItem);
	}
}

// ─── 이동 / 카메라 ────────────────────────────────────────────────────────
void AZombiePlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D V = Value.Get<FVector2D>();
	if (!Controller || V.IsZero()) return;

	const FRotator Rot(0, Controller->GetControlRotation().Yaw, 0);
	AddMovementInput(FRotationMatrix(Rot).GetUnitAxis(EAxis::X), V.Y);
	AddMovementInput(FRotationMatrix(Rot).GetUnitAxis(EAxis::Y), V.X);
}

void AZombiePlayerCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D V = Value.Get<FVector2D>();
	if (!Controller) return;
	AddControllerYawInput(V.X);
	AddControllerPitchInput(V.Y);
}

// ─── 달리기 ───────────────────────────────────────────────────────────────
void AZombiePlayerCharacter::StartSprint()
{
	bIsSprinting = true;
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	if (WeaponComp) WeaponComp->StopFire();
}

void AZombiePlayerCharacter::StopSprint()
{
	bIsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

// ─── 사격 ─────────────────────────────────────────────────────────────────
void AZombiePlayerCharacter::StartFire()
{
	if (bIsSprinting || IsDead()) return;
	if (WeaponComp) WeaponComp->StartFire();
}

void AZombiePlayerCharacter::StopFire()
{
	if (WeaponComp) WeaponComp->StopFire();
}

// ─── 재장전 / 아이템 ──────────────────────────────────────────────────────
void AZombiePlayerCharacter::Reload()
{
	if (!IsDead() && WeaponComp) WeaponComp->StartReload();
}

void AZombiePlayerCharacter::UseItem()
{
	if (!IsDead() && WeaponComp) WeaponComp->UseHeldItem();
}

// ─── 체력 ─────────────────────────────────────────────────────────────────
void AZombiePlayerCharacter::TakeDamageAmount(float Amount)
{
	if (IsDead()) return;
	CurrentHealth = FMath::Clamp(CurrentHealth - Amount, 0.f, MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	UE_LOG(LogTemp, Log, TEXT("[Player] 피해 %.0f | 남은 체력 %.0f"), Amount, CurrentHealth);
	if (CurrentHealth <= 0.f) Die();
}

void AZombiePlayerCharacter::HealHealth(float Amount)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.f, MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
}

// ─── 사망 ─────────────────────────────────────────────────────────────────
void AZombiePlayerCharacter::Die() { OnDeath(); }

void AZombiePlayerCharacter::OnDeath_Implementation()
{
	DisableInput(Cast<APlayerController>(GetController()));

	if (AZombieGameMode* GM = Cast<AZombieGameMode>(UGameplayStatics::GetGameMode(this)))
		GM->OnPlayerDead();

	UE_LOG(LogTemp, Warning, TEXT("[Player] 사망"));
}
