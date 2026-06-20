// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ZombieAIController.generated.h"

class AZombieCharacter;

/**
 * 좀비 AI 컨트롤러
 * 0.2초마다 플레이어 위치를 갱신하며 NavMesh 추적.
 * 공격 범위 진입 시 이동 중지 → ZombieCharacter.StartAttack() 호출.
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API AZombieAIController : public AAIController
{
	GENERATED_BODY()

public:
	AZombieAIController(const FObjectInitializer& ObjectInitializer);

	virtual void OnPossess(APawn* InPawn) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float ChaseInterval = 0.2f;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float AttackRange = 150.f;

	/** 플레이어가 이 거리(이상) 움직였을 때만 경로를 다시 요청. 작을수록 재경로(→순간 속도출렁) 잦아 떨림.
	 *  MoveToActor는 목표 액터를 어느정도 자동 추적하므로 크게 둬도 추적엔 문제없음. */
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float RepathTolerance = 300.f;

	/** 교전 해제 여유(데드존). 사거리 안에서 교전 시작 후, 사거리+이 값 밖으로
	 *  확실히 벗어나야 다시 추격. 사거리 경계에서 멈춤/이동 반복(덜덜거림)을 막는다. */
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float AttackRangeHysteresis = 100.f;

private:
	FTimerHandle ChaseTimer;
	void UpdateChase();

	/** 정지 상태로 진입할 때 단 1회만 이동을 멈춘다 (매 틱 StopMovement로 인한 군중 깜빡임 방지) */
	void HaltMovement(AZombieCharacter* Zombie);

	/** 마지막으로 MoveToActor에 사용한 목표 위치 (재경로 판단용) */
	FVector LastMoveGoal = FVector::ZeroVector;

	/** 교전(사거리 진입) 상태 — 히스테리시스로 경계 진동 방지 */
	bool bEngaged = false;

	/** 정지 래치 — 정지 상태에서 StopMovement를 1회만 호출하기 위함 */
	bool bHalted = false;
};
