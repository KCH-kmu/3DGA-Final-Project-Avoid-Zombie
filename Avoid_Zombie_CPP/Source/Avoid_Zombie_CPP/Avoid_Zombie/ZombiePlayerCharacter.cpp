// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombiePlayerCharacter.h"
#include "WeaponComponent.h"
#include "ZombieGameMode.h"
#include "Camera/ZombieCameraComponent.h"
#include "Camera/ZombieCameraMode_ThirdPerson.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Kismet/GameplayStatics.h"

AZombiePlayerCharacter::AZombiePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// ─── 카메라 (Lyra 이식) ─────────────────────────────────────────
	// 스프링암 없이 카메라 모드 스택이 매 프레임 위치/회전/FOV를 계산
	CameraComp = CreateDefaultSubobject<UZombieCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(RootComponent);

	DefaultCameraMode = UZombieCameraMode_ThirdPerson::StaticClass();
	DeathCameraMode   = UZombieCameraMode_Death::StaticClass();

	// ─── 무기 컴포넌트 ──────────────────────────────────────────────
	WeaponComp = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComp"));

	// ─── 무기 비주얼 메시 (오른손 본에 부착되는 소총) ───────────────
	// 메시(SM_Rifle_Olive)와 정확한 소켓/위치는 BP에서 컴포넌트 단위로 보정
	WeaponMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMeshComp"));
	WeaponMeshComp->SetupAttachment(GetMesh(), TEXT("hand_r"));
	WeaponMeshComp->SetCollisionProfileName(TEXT("NoCollision"));
	WeaponMeshComp->SetGenerateOverlapEvents(false);

	// ─── 이동 설정 ───────────────────────────────────────────────────
	// 캐릭터 회전은 Tick의 FaceAimPoint()가 실제 조준점을 향해 처리
	// (어깨 오프셋 카메라에서는 카메라 정면과 조준점 방향이 살짝 다름)
	bUseControllerRotationYaw   = false;
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

	// ─── 발사/재장전 몽타주 델리게이트 바인딩 ──────────────────────
	if (WeaponComp)
	{
		WeaponComp->OnWeaponFired.AddDynamic(this, &AZombiePlayerCharacter::HandleWeaponFired);
		WeaponComp->OnReloadStarted.AddDynamic(this, &AZombiePlayerCharacter::HandleReloadStarted);
	}

	// 카메라 모드 질의 델리게이트 바인딩 (CDO 복제 문제를 피하기 위해 런타임에 바인딩)
	if (CameraComp)
	{
		CameraComp->DetermineCameraModeDelegate.BindUObject(this, &AZombiePlayerCharacter::DetermineCameraMode);
	}

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

			// 정면 도달 → 회전 완료 처리 (이후 FaceAimPoint가 이어받음)
			if (FMath::Abs(FMath::FindDeltaAngleDegrees(NewRot.Yaw, TargetYaw)) < 1.f)
			{
				SetActorRotation(Target);
				bRealigningToCamera = false;
			}
		}
	}

	// ─── 조준점 바라보기 ─────────────────────────────────────────────
	// 어깨 오프셋 카메라 기준, 크로스헤어가 실제로 가리키는 지점을 향해 회전
	if (!bIsSprinting && !bRealigningToCamera && !IsDead())
	{
		FaceAimPoint(DeltaTime);
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

// ─── 카메라 모드 결정 ─────────────────────────────────────────────────────
TSubclassOf<UZombieCameraMode> AZombiePlayerCharacter::DetermineCameraMode() const
{
	// 사망 시 게임오버 UI 뒤에서 카메라가 천천히 멀어지는 연출
	if (IsDead() && DeathCameraMode)
	{
		return DeathCameraMode;
	}
	return DefaultCameraMode;
}

// ─── 조준점 바라보기 ──────────────────────────────────────────────────────
void AZombiePlayerCharacter::FaceAimPoint(float DeltaTime)
{
	if (!CameraComp || !Controller) return;

	// 무기(WeaponComponent::PerformLineTrace)와 동일한 트레이스로 실제 조준점 계산
	const FVector Start = CameraComp->GetComponentLocation();
	const FVector End   = Start + CameraComp->GetForwardVector() * AimTraceDistance;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	FHitResult Hit;
	FVector AimPoint = End;
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Pawn, Params))
	{
		AimPoint = Hit.ImpactPoint;
	}

	// 수평(Yaw)만 조준점을 향해 회전
	FVector ToAim = AimPoint - GetActorLocation();
	ToAim.Z = 0.f;
	if (ToAim.SizeSquared() < KINDA_SMALL_NUMBER) return;

	const FRotator TargetRot(0.f, ToAim.Rotation().Yaw, 0.f);
	SetActorRotation(FMath::RInterpTo(GetActorRotation(), TargetRot, DeltaTime, AimFaceInterpSpeed));
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

// ─── 무장 애니메이션 ────────────────────────────────────────────────────────
void AZombiePlayerCharacter::HandleWeaponFired()
{
	if (FireMontage)
	{
		// RPS가 높으면 몽타주가 끝나기 전 재시작될 수 있음 (최소 구성의 의도된 한계)
		PlayAnimMontage(FireMontage);
	}
}

void AZombiePlayerCharacter::HandleReloadStarted(float ReloadTime)
{
	if (!ReloadMontage) return;

	// 몽타주 길이를 실제 재장전 시간(기본 2초 / 버프 1초)에 맞추도록 재생속도 보정
	const float Length = ReloadMontage->GetPlayLength();
	const float Rate   = (ReloadTime > 0.f && Length > 0.f) ? (Length / ReloadTime) : 1.f;
	PlayAnimMontage(ReloadMontage, Rate);
}

// ─── AnimBP용 조준/상태 헬퍼 ────────────────────────────────────────────────
float AZombiePlayerCharacter::GetAimPitch() const
{
	if (!Controller) return 0.f;
	// 컨트롤 회전 Pitch를 -180~180으로 정규화 (위/아래 조준 → Aim Offset 세로축)
	return FRotator::NormalizeAxis(Controller->GetControlRotation().Pitch);
}

float AZombiePlayerCharacter::GetAimYaw() const
{
	if (!Controller) return 0.f;
	// 조준 방향과 캐릭터 정면의 좌우 차이 (-180~180 → Aim Offset 가로축)
	return FRotator::NormalizeAxis(Controller->GetControlRotation().Yaw - GetActorRotation().Yaw);
}

bool AZombiePlayerCharacter::IsReloading() const
{
	return WeaponComp && WeaponComp->bIsReloading;
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
