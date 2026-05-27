// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "ZombieCharacter.h"
#include "ZombieAIController.h"
#include "AvoidZombieCharacter.h"
#include "AvoidZombieGameState.h"
#include "WaveManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimMontage.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

AZombieCharacter::AZombieCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// AI 컨트롤러 자동 설정
	AIControllerClass = AZombieAIController::StaticClass();
	AutoPossessAI     = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	// 이동 속도 적용
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
	}
}

void AZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ─── 피해 받기 ────────────────────────────────────────────────────────────
void AZombieCharacter::TakeDamageAmount(float DamageAmount)
{
	if (IsDead()) return;

	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth);

	if (CurrentHealth <= 0.f)
	{
		Die();
	}
}

// ─── 공격 ─────────────────────────────────────────────────────────────────
void AZombieCharacter::StartAttack()
{
	if (bIsAttacking || bIsStunned || IsDead()) return;

	bIsAttacking = true;

	// Attack2 몽타주 재생
	if (AttackMontage)
	{
		PlayAnimMontage(AttackMontage);
	}
}

void AZombieCharacter::OnAttackHit()
{
	// 21프레임 - 공격 히트 판정
	// 범위 내 플레이어에게 데미지
	if (!IsPlayerInAttackRange()) return;

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (AAvoidZombieCharacter* Player = Cast<AAvoidZombieCharacter>(PlayerPawn))
	{
		if (!Player->IsDead())
		{
			Player->TakeDamageAmount(AttackDamage);
			UE_LOG(LogTemp, Log, TEXT("[Zombie] 플레이어 공격 - 데미지: %.0f"), AttackDamage);
		}
	}
}

void AZombieCharacter::OnAttackEnd()
{
	// 애니메이션 완전히 끝난 후 bIsAttacking 해제
	bIsAttacking = false;
}

bool AZombieCharacter::IsPlayerInAttackRange() const
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn) return false;

	const float Distance = FVector::Dist(GetActorLocation(), PlayerPawn->GetActorLocation());
	return Distance <= AttackRange;
}

// ─── 스턴 ─────────────────────────────────────────────────────────────────
void AZombieCharacter::ApplyStun(float Duration)
{
	bIsStunned = true;

	// 이동 중지
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = 0.f;
	}

	// 기존 스턴 타이머 초기화 후 재설정
	GetWorld()->GetTimerManager().ClearTimer(StunTimerHandle);
	GetWorld()->GetTimerManager().SetTimer(StunTimerHandle, this, &AZombieCharacter::RemoveStun, Duration, false);

	UE_LOG(LogTemp, Log, TEXT("[Zombie] 스턴 적용 (%.1f초)"), Duration);
}

void AZombieCharacter::RemoveStun()
{
	bIsStunned = false;

	// 이동 속도 복구
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
	}

	UE_LOG(LogTemp, Log, TEXT("[Zombie] 스턴 해제"));
}

// ─── 사망 ─────────────────────────────────────────────────────────────────
void AZombieCharacter::Die()
{
	// AI 비활성화
	if (AZombieAIController* AIC = Cast<AZombieAIController>(GetController()))
	{
		AIC->StopMovement();
	}

	// 타이머 정리
	GetWorld()->GetTimerManager().ClearTimer(StunTimerHandle);

	// GameState에 킬 점수 추가
	if (AAvoidZombieGameState* GS = GetWorld()->GetGameState<AAvoidZombieGameState>())
	{
		GS->AddKillScore();
	}

	// WaveManager에 사망 알림 (웨이브 클리어 체크)
	TArray<AActor*> WaveManagers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaveManager::StaticClass(), WaveManagers);
	for (AActor* Actor : WaveManagers)
	{
		if (AWaveManager* WM = Cast<AWaveManager>(Actor))
		{
			WM->OnZombieDead();
			break;
		}
	}

	OnDeath();
}

void AZombieCharacter::OnDeath_Implementation()
{
	// 블루프린트에서 사망 애니메이션 / 이펙트 처리
	// 기본 구현: 일정 시간 후 제거
	SetLifeSpan(3.f);

	// 콜리전 비활성화
	SetActorEnableCollision(false);

	UE_LOG(LogTemp, Log, TEXT("[Zombie] 사망 처리 완료"));
}
