// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieAIController.h"
#include "ZombieCharacter.h"
#include "ZombiePlayerCharacter.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// 기본 PathFollowingComponent 대신 CrowdFollowingComponent를 사용 →
// 좀비들이 서로 회피하며(Detour Crowd) 앞 좀비를 돌아 플레이어를 둘러싼다.
AZombieAIController::AZombieAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	PrimaryActorTick.bCanEverTick = true;
}

void AZombieAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// ─── 군중 회피(Detour Crowd) 설정 ────────────────────────────────
	// 분리(Separation)로 서로 밀어내 일렬 정체 대신 옆으로 퍼져 둘러싸게 함.
	if (UCrowdFollowingComponent* Crowd = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
	{
		// 분리(Separation)는 끔: 좀비끼리 서로 밀어내는 힘이 매 프레임 앞으로/뒤로
		// 미세하게 밀어 '따라올 때 앞뒤로 떠는' 진동의 주원인. 충돌 방지는 회피(avoidance)가
		// 담당하므로 끄더라도 줄서기/겹침은 발생하지 않고, 이동만 매끄러워진다.
		Crowd->SetCrowdSeparation(false);
		Crowd->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Good); // 샘플 방향 ↑ → 회피 진동 감소
		Crowd->SetCrowdCollisionQueryRange(600.f);        // 주변 에이전트 고려 범위
		Crowd->SetCrowdAvoidanceRangeMultiplier(1.2f);    // 회피 반응 거리
		Crowd->SetCrowdAnticipateTurns(true);             // 회전을 미리 예측 → 부드러운 진로
		Crowd->SetCrowdSlowdownAtGoal(true);              // 목표 근처 감속 → 급정지 방지
		Crowd->SetCrowdOptimizeVisibility(true);          // 경로 시야 최적화로 흔들림 완화
	}

	GetWorld()->GetTimerManager().SetTimer(
		ChaseTimer, this, &AZombieAIController::UpdateChase, ChaseInterval, true);
}

// 정지 상태로 '진입할 때만' 1회 이동 정지 + 잔여 속도 0 (매 틱 StopMovement로 인한
// 군중 시뮬 속도 0↔이동 깜빡임 + 잔여속도 방향 orient 떨림 방지)
void AZombieAIController::HaltMovement(AZombieCharacter* Zombie)
{
	if (bHalted) return;
	StopMovement();
	if (Zombie)
		if (UCharacterMovementComponent* M = Zombie->GetCharacterMovement())
			M->StopMovementImmediately();
	bHalted = true;
}

void AZombieAIController::UpdateChase()
{
	AZombieCharacter* Zombie = Cast<AZombieCharacter>(GetPawn());
	if (!Zombie || Zombie->IsDead()) return;

	// 스턴 중 정지
	if (Zombie->bIsStunned)
	{
		HaltMovement(Zombie);
		return;
	}

	APawn* Player = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!Player) return;

	// 플레이어 사망 시 추적/공격 중지 (시체를 계속 때리지 않도록)
	if (AZombiePlayerCharacter* PC = Cast<AZombiePlayerCharacter>(Player))
	{
		if (PC->IsDead())
		{
			HaltMovement(Zombie);
			bEngaged = false;
			return;
		}
	}

	// 수평(2D) 거리로 판정 → 스폰 높이차/지형 Z 차이로 사거리에 못 들어가는 문제 방지
	const FVector PlayerLoc = Player->GetActorLocation();
	const float Dist = FVector::Dist2D(Zombie->GetActorLocation(), PlayerLoc);

	// ─── 교전 히스테리시스 (사거리 경계 덜덜거림 방지) ───────────────
	// 사거리(150) 안에 들면 '교전' 시작. 한번 교전하면 사거리+여유(데드존)
	// 밖으로 확실히 벗어나야 교전 해제 → 경계 들락거림 빈도↓.
	if (Dist <= AttackRange)
		bEngaged = true;
	else if (Dist > AttackRange + AttackRangeHysteresis)
		bEngaged = false;

	// 교전(또는 공격 진행) 중이면 제자리 유지 + 공격. 재경로 안 함.
	if (bEngaged || Zombie->bIsAttacking)
	{
		HaltMovement(Zombie);          // 진입 시 1회만 정지 (래치)
		Zombie->StartAttack();
		return;
	}

	// ─── 추격 (교전 아닐 때만) ───────────────────────────────────────
	bHalted = false; // 다시 움직이므로 정지 래치 해제

	// 재경로는 "꼭 필요할 때만" — 매 틱 MoveToActor 재호출은 경로/군중 시뮬을
	// 리셋해 속도가 순간 0이 됨. 플레이어가 RepathTolerance 이상 움직였거나
	// 멈춰 있는(도착/실패) 상태일 때만 재요청.
	const bool bIdle        = (GetMoveStatus() == EPathFollowingStatus::Idle);
	const bool bPlayerMoved = FVector::DistSquared2D(PlayerLoc, LastMoveGoal) > FMath::Square(RepathTolerance);

	if (bIdle || bPlayerMoved)
	{
		LastMoveGoal = PlayerLoc;
		// 도착 반경을 교전 임계(AttackRange)보다 작게 정렬 + bStopOnOverlap=false로
		// 캡슐 반경 이중가산 제거 → 도착(~110)이 곧장 교전(150)으로 이어져
		// '전진하라/멈춰라'가 충돌하던 밴드를 없앤다.
		MoveToActor(Player, AttackRange - 40.f, /*bStopOnOverlap=*/false);
	}
}
