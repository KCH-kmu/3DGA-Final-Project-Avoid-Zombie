// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieAIController.h"
#include "ZombieCharacter.h"
#include "Kismet/GameplayStatics.h"

AZombieAIController::AZombieAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AZombieAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	GetWorld()->GetTimerManager().SetTimer(
		ChaseTimer, this, &AZombieAIController::UpdateChase, ChaseInterval, true);
}

void AZombieAIController::UpdateChase()
{
	AZombieCharacter* Zombie = Cast<AZombieCharacter>(GetPawn());
	if (!Zombie || Zombie->IsDead()) return;

	if (Zombie->bIsStunned || Zombie->bIsAttacking)
	{
		StopMovement();
		return;
	}

	APawn* Player = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!Player) return;

	const float Dist = FVector::Dist(Zombie->GetActorLocation(), Player->GetActorLocation());

	if (Dist <= AttackRange)
	{
		StopMovement();
		Zombie->StartAttack();
	}
	else
	{
		MoveToActor(Player, AttackRange - 10.f);
	}
}
