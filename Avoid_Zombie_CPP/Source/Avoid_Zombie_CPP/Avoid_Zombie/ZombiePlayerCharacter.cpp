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
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f); // 달리기 중 이동 방향 회전 속도
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

void AZombiePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ─── 달리기 종료 후 카메라 방향으로 부드럽게 회전 ──────────────
	if (bRealigningToCamera)
	{
		if (!Controller)
		{
			bRealigningToCamera = false;
		}
		else
		{
			const float TargetYaw = Controller->GetControlRotation().Yaw;
			const FRotator Target(0.f, TargetYaw, 0.f);

			// 일정 속도(도/초)로 회전 → 시작부터 끝까지 균일한 속도
			const FRotator NewRot = FMath::RInterpConstantTo(GetActorRotation(), Target, DeltaTime, RealignSpeed);
			SetActorRotation(NewRot);

			// 정면 도달 → 회전 완료 처리
			if (FMath::Abs(FMath::FindDeltaAngleDegrees(NewRot.Yaw, TargetYaw)) < 1.f)
			{
				SetActorRotation(Target);
				bRealigningToCamera = false;
				bUseControllerRotationYaw = true;
			}
		}
	}

	// ─── 발사 버튼 유지 중 자동 발사 재개 ───────────────────────────
	// (자동/수동 재장전 종료 후, 달리기 종료 후 등 모든 경우를 커버.
	//  WeaponComp->StartFire()는 재장전 중이거나 이미 발사 중이면 무시되므로 매 틱 호출해도 안전)
	if (bWantsToFire && !bIsSprinting && !IsDead() && WeaponComp)
	{
		bool bAimReady = !bRealigningToCamera;
		if (bRealigningToCamera && Controller)
		{
			// 회전 복귀 중에는 정면 기준 FireAlignAngle 이내일 때만 발사
			bAimReady = FMath::Abs(FMath::FindDeltaAngleDegrees(
				GetActorRotation().Yaw, Controller->GetControlRotation().Yaw)) < FireAlignAngle;
		}
		if (bAimReady)
			WeaponComp->StartFire();
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

	// 달리는 동안에는 이동 방향을 바라보도록 전환 (뒷걸음 달리기 방지)
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bRealigningToCamera = false;
}

void AZombiePlayerCharacter::StopSprint()
{
	bIsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	// 즉시 스냅하지 않고 Tick에서 카메라 방향으로 부드럽게 회전
	// (회전 완료 후 bUseControllerRotationYaw 복원 + 발사 재개)
	bRealigningToCamera = true;
}

// ─── 사격 ─────────────────────────────────────────────────────────────────
void AZombiePlayerCharacter::StartFire()
{
	bWantsToFire = true;
	if (bIsSprinting || bRealigningToCamera || IsDead()) return; // 회전 완료 후 Tick에서 발사 시작
	if (WeaponComp) WeaponComp->StartFire();
}

void AZombiePlayerCharacter::StopFire()
{
	bWantsToFire = false;
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
