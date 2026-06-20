// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieCharacter.h"
#include "ZombieAIController.h"
#include "ZombiePlayerCharacter.h"
#include "ZombieGameState.h"
#include "WaveManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "Kismet/GameplayStatics.h"

AZombieCharacter::AZombieCharacter()
{
	AIControllerClass  = AZombieAIController::StaticClass();
	AutoPossessAI      = EAutoPossessAI::PlacedInWorldOrSpawned;
	PrimaryActorTick.bCanEverTick = true;

	// ─── 회전: facing은 엔진 자동(velocity 추종) 대신 Tick에서 직접 제어 ──
	// bOrientRotationToMovement는 '진동하는 속도(velocity)'를 그대로 facing에
	// 반영해 밀집 시 메시가 좌우로 떨린다(지글링). 대신 UpdateFacing()에서
	// 이동 중엔 속도방향을 RInterpTo로 부드럽게(진동 흡수), 정지/공격 중엔
	// 플레이어 방향을 바라보게 한다 → 게걸음 방지(이동 정면주행)는 그대로 유지.
	bUseControllerRotationYaw = false;
	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		Move->bOrientRotationToMovement     = false;
		Move->bUseControllerDesiredRotation = false;

		// 밀집 시 캡슐 디펜트레이션 스냅 진동 완화 (기본 100cm → 4cm)
		Move->MaxDepenetrationWithPawn = 4.f;
	}

	// ─── 3인칭 카메라 침투방지(ECC_Camera) 레이가 좀비를 무시하게 ─────
	// 좀비가 플레이어에 붙어도 카메라가 갑자기 줌인되지 않도록.
	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
		Capsule->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	if (USkeletalMeshComponent* MeshComp = GetMesh())
		MeshComp->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	// 카메라 코드가 명시적으로 존중하는 태그(혹시 BP 충돌 프리셋이 Camera를 Block해도 무시됨)
	Tags.Add(FName(TEXT("IgnoreCameraCollision")));
}

void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
}

void AZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 실제 속도가 군중 회피로 출렁여도 로코모션 BlendSpace가 떨리지 않도록 저역통과.
	SmoothedGroundSpeed = FMath::FInterpTo(
		SmoothedGroundSpeed, GetVelocity().Size2D(), DeltaTime, GroundSpeedInterpSpeed);

	if (!IsDead())
		UpdateFacing(DeltaTime);
}

void AZombieCharacter::UpdateFacing(float DeltaTime)
{
	// 공격/스턴 중에는 회전 갱신 안 함 → StartAttack의 '플레이어 향함' 스냅 facing을 유지.
	if (bIsAttacking || bIsStunned) return;

	FVector Vel = GetVelocity();
	Vel.Z = 0.f;

	// 저속(밀집 정체 등)에서는 속도 '방향'이 노이즈라 따라가면 떨린다.
	// 또 임계값 위/아래로 목표를 바꾸면(예: 플레이어 vs 속도) 그 전환 자체가 떨림이 됨.
	// → 저속 프레임은 회전을 갱신하지 않고 '현재 facing 유지'(플레이어로도 스냅 안 함).
	if (Vel.SizeSquared() < FMath::Square(FacingSpeedThreshold)) return;

	// 충분히 이동 중일 때만 속도방향을 부드럽게 추종 — RInterpTo가 잔여 방향 진동을 흡수.
	const FRotator Target(0.f, Vel.Rotation().Yaw, 0.f);
	SetActorRotation(FMath::RInterpTo(GetActorRotation(), Target, DeltaTime, FacingInterpSpeed));
}

void AZombieCharacter::TakeDamageAmount(float Amount)
{
	if (IsDead()) return;
	CurrentHealth = FMath::Clamp(CurrentHealth - Amount, 0.f, MaxHealth);

	if (CurrentHealth <= 0.f)
	{
		Die();
		return;
	}

	// 살아있고 공격 중이 아닐 때만 피격 리액션 재생 (공격 스윙 끊김 방지)
	if (!bIsAttacking && HitReactMontages.Num() > 0)
	{
		const int32 Idx = FMath::RandRange(0, HitReactMontages.Num() - 1);
		if (HitReactMontages[Idx])
			PlayAnimMontage(HitReactMontages[Idx]);
	}
}

float AZombieCharacter::GetGroundSpeed() const
{
	// 스무딩된 값 반환 → 속도 출렁임이 BlendSpace 다리 떨림으로 보이지 않게
	return SmoothedGroundSpeed;
}

void AZombieCharacter::StartAttack()
{
	if (bIsAttacking || bIsStunned || IsDead()) return;

	// 플레이어가 죽었으면 공격하지 않음
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (AZombiePlayerCharacter* P = Cast<AZombiePlayerCharacter>(PlayerPawn))
		if (P->IsDead()) return;

	// 공격 시작 시 플레이어를 정면으로 바라보게 (이동 회전이 멈춰도 정면 타격)
	if (PlayerPawn)
	{
		FVector ToPlayer = PlayerPawn->GetActorLocation() - GetActorLocation();
		ToPlayer.Z = 0.f;
		if (!ToPlayer.IsNearlyZero())
			SetActorRotation(ToPlayer.Rotation());
	}

	bIsAttacking = true;

	float Duration = 1.5f; // ABP 없을 때 폴백 시간
	if (AttackMontage)
	{
		float Played = PlayAnimMontage(AttackMontage);
		if (Played > 0.f) Duration = Played;
	}

	// 몽타주가 끝나면(또는 ABP 없으면 Duration 후) 공격 상태 해제
	GetWorld()->GetTimerManager().SetTimer(
		AttackEndTimerHandle, this, &AZombieCharacter::OnAttackEnd, Duration, false);
}

void AZombieCharacter::OnAttackHit()
{
	// 21프레임 히트 판정 — 거리 안 + 정면 부채꼴 안일 때만
	if (!IsPlayerInAttackRange()) return;

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn) return;

	// 정면 부채꼴 각도 판정: 좀비 앞쪽 ±AttackHalfAngle 안에 있을 때만 히트.
	// (공격 도중 플레이어가 좀비 뒤/옆으로 돌면 빗나가도록 → 360° 피해 방지)
	FVector ToPlayer = PlayerPawn->GetActorLocation() - GetActorLocation();
	ToPlayer.Z = 0.f;
	if (!ToPlayer.IsNearlyZero())
	{
		const FVector Forward = GetActorForwardVector().GetSafeNormal2D();
		const float Cos = FVector::DotProduct(Forward, ToPlayer.GetSafeNormal());
		const float CosHalf = FMath::Cos(FMath::DegreesToRadians(AttackHalfAngle));
		if (Cos < CosHalf) return; // 부채꼴 밖 → 무효
	}

	if (AZombiePlayerCharacter* Player = Cast<AZombiePlayerCharacter>(PlayerPawn))
	{
		if (!Player->IsDead())
			Player->TakeDamageAmount(AttackDamage);
	}
}

void AZombieCharacter::OnAttackEnd()
{
	bIsAttacking = false;
}

bool AZombieCharacter::IsPlayerInAttackRange() const
{
	APawn* P = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!P) return false;
	return FVector::Dist2D(GetActorLocation(), P->GetActorLocation()) <= AttackRange;
}

void AZombieCharacter::ApplyStun(float Duration)
{
	bIsStunned = true;
	GetCharacterMovement()->MaxWalkSpeed = 0.f;

	GetWorld()->GetTimerManager().ClearTimer(StunTimerHandle);
	GetWorld()->GetTimerManager().SetTimer(
		StunTimerHandle, this, &AZombieCharacter::RemoveStun, Duration, false);
}

void AZombieCharacter::RemoveStun()
{
	bIsStunned = false;
	GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
}

void AZombieCharacter::Die()
{
	if (AZombieAIController* AIC = Cast<AZombieAIController>(GetController()))
		AIC->StopMovement();

	GetWorld()->GetTimerManager().ClearTimer(StunTimerHandle);

	// GameState 킬 점수 추가
	if (AZombieGameState* GS = GetWorld()->GetGameState<AZombieGameState>())
		GS->AddKillScore();

	// WaveManager에 사망 알림
	TArray<AActor*> WMs;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaveManager::StaticClass(), WMs);
	if (WMs.Num() > 0)
		if (AWaveManager* WM = Cast<AWaveManager>(WMs[0]))
			WM->OnZombieDead();

	OnDeath();
}

void AZombieCharacter::OnDeath_Implementation()
{
	SetActorEnableCollision(false);

	// 이동 정지 → 사망 애니 중 시체가 미끄러지지 않도록
	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		Move->StopMovementImmediately();
		Move->DisableMovement();
	}

	// 사망 몽타주 재생 후 시체 제거 (몽타주 길이 + 여유)
	float LifeSpan = 3.f;
	if (DeathMontage)
	{
		const float Played = PlayAnimMontage(DeathMontage);
		if (Played > 0.f) LifeSpan = Played + 0.5f;
	}
	SetLifeSpan(LifeSpan);

	UE_LOG(LogTemp, Log, TEXT("[Zombie] 사망"));
}
