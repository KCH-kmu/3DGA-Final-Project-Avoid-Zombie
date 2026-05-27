// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieCharacter.h"
#include "ZombieAIController.h"
#include "ZombiePlayerCharacter.h"
#include "ZombieGameState.h"
#include "WaveManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AZombieCharacter::AZombieCharacter()
{
	AIControllerClass  = AZombieAIController::StaticClass();
	AutoPossessAI      = EAutoPossessAI::PlacedInWorldOrSpawned;
	PrimaryActorTick.bCanEverTick = true;
}

void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
}

void AZombieCharacter::TakeDamageAmount(float Amount)
{
	if (IsDead()) return;
	CurrentHealth = FMath::Clamp(CurrentHealth - Amount, 0.f, MaxHealth);
	if (CurrentHealth <= 0.f) Die();
}

void AZombieCharacter::StartAttack()
{
	if (bIsAttacking || bIsStunned || IsDead()) return;
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
	// 21프레임 히트 판정
	if (!IsPlayerInAttackRange()) return;

	if (AZombiePlayerCharacter* Player = Cast<AZombiePlayerCharacter>(
		UGameplayStatics::GetPlayerPawn(this, 0)))
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
	return FVector::Dist(GetActorLocation(), P->GetActorLocation()) <= AttackRange;
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
	SetLifeSpan(3.f);
	UE_LOG(LogTemp, Log, TEXT("[Zombie] 사망"));
}
