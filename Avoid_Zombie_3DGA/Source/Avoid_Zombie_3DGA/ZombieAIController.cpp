// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "ZombieAIController.h"
#include "ZombieCharacter.h"
#include "Navigation/PathFollowingComponent.h"
#include "Kismet/GameplayStatics.h"

AZombieAIController::AZombieAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AZombieAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AZombieAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Possess 완료 후 추적 타이머 시작
	GetWorld()->GetTimerManager().SetTimer(
		ChaseTimerHandle,
		this,
		&AZombieAIController::UpdateChase,
		ChaseUpdateInterval,
		true // 반복
	);
}

void AZombieAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AZombieAIController::UpdateChase()
{
	AZombieCharacter* Zombie = Cast<AZombieCharacter>(GetPawn());
	if (!Zombie || Zombie->IsDead()) return;

	// 스턴 또는 공격 중이면 이동 중단
	if (Zombie->bIsStunned || Zombie->bIsAttacking)
	{
		StopMovement();
		return;
	}

	// 플레이어 위치 확인
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn) return;

	const float Distance = FVector::Dist(Zombie->GetActorLocation(), PlayerPawn->GetActorLocation());

	if (Distance <= AttackRange)
	{
		// 공격 범위 진입 → 이동 중단 + 공격 시작
		StopMovement();
		Zombie->StartAttack();
	}
	else
	{
		// NavMesh로 플레이어 추적
		MoveToActor(PlayerPawn, AttackRange - 10.f); // 약간 여유를 두고 정지
	}
}
