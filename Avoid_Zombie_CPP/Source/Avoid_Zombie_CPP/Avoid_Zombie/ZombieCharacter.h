// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieCharacter.generated.h"

class UAnimMontage;

/**
 * 좀비 캐릭터
 * - 이동속도 1m/s (WaveManager가 스폰 후 설정)
 * - 체력 6 (WaveManager가 스폰 후 설정)
 * - 근접 공격 데미지 1, Attack2 몽타주 21프레임에 히트
 * - 스턴 지원
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API AZombieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AZombieCharacter();

	virtual void BeginPlay() override;

	// ─── 스탯 (WaveManager에서 스폰 후 설정) ────────────────────────
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zombie")
	float MoveSpeed = 100.f; // 1m/s

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zombie")
	float MaxHealth = 6.f;

	UPROPERTY(BlueprintReadOnly, Category = "Zombie")
	float CurrentHealth;

	UPROPERTY(EditDefaultsOnly, Category = "Zombie")
	float AttackDamage = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "Zombie")
	float AttackRange = 150.f;

	// ─── 애니메이션 ─────────────────────────────────────────────────
	/** Attack2 몽타주 — 21프레임에 ZombieAttackNotify 배치 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Zombie|Anim")
	TObjectPtr<UAnimMontage> AttackMontage;

	// ─── 상태 ───────────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Zombie")
	bool bIsAttacking = false;

	UPROPERTY(BlueprintReadOnly, Category = "Zombie")
	bool bIsStunned = false;

	// ─── 공개 함수 ──────────────────────────────────────────────────
	UFUNCTION(BlueprintCallable, Category = "Zombie")
	void TakeDamageAmount(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Zombie")
	void StartAttack();

	/** AnimNotify(21프레임)에서 호출 */
	UFUNCTION(BlueprintCallable, Category = "Zombie")
	void OnAttackHit();

	/** 몽타주 종료 후 호출 */
	UFUNCTION(BlueprintCallable, Category = "Zombie")
	void OnAttackEnd();

	UFUNCTION(BlueprintCallable, Category = "Zombie")
	void ApplyStun(float Duration);

	UFUNCTION(BlueprintPure, Category = "Zombie")
	bool IsPlayerInAttackRange() const;

	UFUNCTION(BlueprintPure, Category = "Zombie")
	bool IsDead() const { return CurrentHealth <= 0.f; }

protected:
	FTimerHandle StunTimerHandle;
	FTimerHandle AttackEndTimerHandle;  // 몽타주 종료 폴백 타이머

	void Die();
	void RemoveStun();

	UFUNCTION(BlueprintNativeEvent, Category = "Zombie")
	void OnDeath();
	virtual void OnDeath_Implementation();
};
