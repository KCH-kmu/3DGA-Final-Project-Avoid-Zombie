// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ZombieAIController.generated.h"

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
	AZombieAIController();

	virtual void OnPossess(APawn* InPawn) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float ChaseInterval = 0.2f;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float AttackRange = 150.f;

private:
	FTimerHandle ChaseTimer;
	void UpdateChase();
};
