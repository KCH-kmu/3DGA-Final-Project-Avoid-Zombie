// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "AvoidZombieCharacter.h"
#include "WeaponComponent.h"
#include "AvoidZombieGameMode.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Kismet/GameplayStatics.h"

AAvoidZombieCharacter::AAvoidZombieCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// ─── 스프링암 (카메라 붐) ───────────────────────────────────────
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.f;       // 캐릭터로부터 카메라 거리
	CameraBoom->bUsePawnControlRotation = true; // 컨트롤러 회전에 붐 연동

	// ─── 팔로우 카메라 ─────────────────────────────────────────────
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false; // 붐이 회전을 처리

	// ─── 무기 컴포넌트 ──────────────────────────────────────────────
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));

	// ─── 캐릭터 이동 설정 ───────────────────────────────────────────
	// 이동 방향으로 자동 회전 (달리기 시에도 적용됨)
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	// 컨트롤러 Yaw 회전만 캐릭터에 적용 (좌우 회전)
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
}

void AAvoidZombieCharacter::BeginPlay()
{
	Super::BeginPlay();

	// 체력 초기화
	CurrentHealth = MaxHealth;

	// Enhanced Input 매핑 컨텍스트 등록
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void AAvoidZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAvoidZombieCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// 이동
		if (MoveAction)
			EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAvoidZombieCharacter::Move);

		// 카메라 회전 (마우스)
		if (LookAction)
			EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAvoidZombieCharacter::Look);

		// 달리기 (Shift)
		if (SprintAction)
		{
			EnhancedInput->BindAction(SprintAction, ETriggerEvent::Started,   this, &AAvoidZombieCharacter::StartSprint);
			EnhancedInput->BindAction(SprintAction, ETriggerEvent::Completed, this, &AAvoidZombieCharacter::StopSprint);
		}

		// 사격 (좌클릭)
		if (FireAction)
		{
			EnhancedInput->BindAction(FireAction, ETriggerEvent::Started,   this, &AAvoidZombieCharacter::StartFire);
			EnhancedInput->BindAction(FireAction, ETriggerEvent::Completed, this, &AAvoidZombieCharacter::StopFire);
		}

		// 재장전 (R키)
		if (ReloadAction)
			EnhancedInput->BindAction(ReloadAction, ETriggerEvent::Started, this, &AAvoidZombieCharacter::Reload);

		// 아이템 사용 (우클릭)
		if (UseItemAction)
			EnhancedInput->BindAction(UseItemAction, ETriggerEvent::Started, this, &AAvoidZombieCharacter::UseItem);
	}
}

// ─── 이동 ─────────────────────────────────────────────────────────────────
void AAvoidZombieCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller && MovementVector != FVector2D::ZeroVector)
	{
		// 컨트롤러 Yaw 방향 기준으로 이동
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection   = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection,   MovementVector.X);
	}
}

// ─── 카메라 회전 ──────────────────────────────────────────────────────────
void AAvoidZombieCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookVector = Value.Get<FVector2D>();

	if (Controller)
	{
		AddControllerYawInput(LookVector.X);
		AddControllerPitchInput(LookVector.Y);
	}
}

// ─── 달리기 ───────────────────────────────────────────────────────────────
void AAvoidZombieCharacter::StartSprint()
{
	bIsSprinting = true;
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;

	// 달리기 중에는 사격 중지
	if (WeaponComponent)
	{
		WeaponComponent->StopFire();
	}
}

void AAvoidZombieCharacter::StopSprint()
{
	bIsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

// ─── 사격 ─────────────────────────────────────────────────────────────────
void AAvoidZombieCharacter::StartFire()
{
	// 달리기 중에는 공격 불가
	if (bIsSprinting) return;
	if (IsDead()) return;

	if (WeaponComponent)
	{
		WeaponComponent->StartFire();
	}
}

void AAvoidZombieCharacter::StopFire()
{
	if (WeaponComponent)
	{
		WeaponComponent->StopFire();
	}
}

// ─── 재장전 ───────────────────────────────────────────────────────────────
void AAvoidZombieCharacter::Reload()
{
	if (IsDead()) return;

	if (WeaponComponent)
	{
		WeaponComponent->StartReload();
	}
}

// ─── 아이템 사용 (우클릭) ─────────────────────────────────────────────────
void AAvoidZombieCharacter::UseItem()
{
	if (IsDead()) return;
	// ItemBox가 인벤토리에 넘긴 아이템 타입을 WeaponComponent 또는 캐릭터에 적용
	// 실제 사용 로직은 ItemBox.cpp 참고
}

// ─── 피해 받기 ────────────────────────────────────────────────────────────
void AAvoidZombieCharacter::TakeDamageAmount(float DamageAmount)
{
	if (IsDead()) return;

	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth);
	UE_LOG(LogTemp, Log, TEXT("[Player] 피해 수신: %.0f | 남은 체력: %.0f"), DamageAmount, CurrentHealth);

	if (CurrentHealth <= 0.f)
	{
		Die();
	}
}

void AAvoidZombieCharacter::HealHealth(float Amount)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.f, MaxHealth);
	UE_LOG(LogTemp, Log, TEXT("[Player] 체력 회복: %.0f | 현재 체력: %.0f"), Amount, CurrentHealth);
}

// ─── 사망 ─────────────────────────────────────────────────────────────────
void AAvoidZombieCharacter::Die()
{
	OnDeath();
}

void AAvoidZombieCharacter::OnDeath_Implementation()
{
	// 입력 비활성화
	DisableInput(Cast<APlayerController>(GetController()));

	// GameMode에 사망 알림
	if (AAvoidZombieGameMode* GM = Cast<AAvoidZombieGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		GM->OnPlayerDead();
	}

	UE_LOG(LogTemp, Warning, TEXT("[Player] 사망 처리 완료"));
}
