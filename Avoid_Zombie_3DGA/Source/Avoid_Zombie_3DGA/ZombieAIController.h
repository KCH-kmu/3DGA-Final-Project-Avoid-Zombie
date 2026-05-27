// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ZombieAIController.generated.h"

/**
 * 좀비 AI 컨트롤러
 *
 * 동작:
 * 1. 매 0.2초마다 플레이어 위치를 갱신하며 NavMesh로 이동
 * 2. 공격 범위(1.5m) 진입 시 이동 중지 → ZombieCharacter.StartAttack() 호출
 * 3. 공격 중에는 이동 중단, 애니메이션 종료 후 다시 추적
 */
UCLASS()
class AVOID_ZOMBIE_3DGA_API AZombieAIController : public AAIController
{
	GENERATED_BODY()

public:
	AZombieAIController();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnPossess(APawn* InPawn) override;

protected:
	/** 플레이어 추적 갱신 간격 (초) */
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float ChaseUpdateInterval = 0.2f;

	/** 공격 범위 (ZombieCharacter.AttackRange와 동기화 필요) */
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float AttackRange = 150.f;

private:
	/** 추적 타이머 핸들 */
	FTimerHandle ChaseTimerHandle;

	/** 플레이어를 향해 이동 갱신 */
	void UpdateChase();
};
