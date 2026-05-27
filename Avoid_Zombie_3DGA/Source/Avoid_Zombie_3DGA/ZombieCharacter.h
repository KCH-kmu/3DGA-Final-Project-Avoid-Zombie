// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieCharacter.generated.h"

class UAnimMontage;

/**
 * 좀비 캐릭터
 *
 * 스펙:
 * - 이동 속도 1m/s (웨이브 매니저가 동적으로 설정)
 * - 체력 6
 * - 근접 공격 데미지 1 (Attack2 애니메이션 21프레임에 히트)
 * - 한번 공격 시 애니메이션 끝까지 진행
 * - 스턴 효과 지원
 */
UCLASS()
class AVOID_ZOMBIE_3DGA_API AZombieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AZombieCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// ─── 스탯 (WaveManager가 Spawn 후 설정) ────────────────────────
	/** 이동 속도 (cm/s). 기본 100 = 1m/s */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zombie|Stats")
	float MoveSpeed = 100.f;

	/** 현재 체력 */
	UPROPERTY(BlueprintReadOnly, Category = "Zombie|Stats")
	float CurrentHealth;

	/** 최대 체력 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zombie|Stats")
	float MaxHealth = 6.f;

	/** 근접 공격 데미지 */
	UPROPERTY(EditDefaultsOnly, Category = "Zombie|Stats")
	float AttackDamage = 1.f;

	// ─── 애니메이션 ─────────────────────────────────────────────────
	/** Attack2 몽타주 (21프레임에 ZombieAttackNotify 배치 필요) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Zombie|Anim")
	TObjectPtr<UAnimMontage> AttackMontage;

	// ─── 공격 상태 ──────────────────────────────────────────────────
	/** 공격 애니메이션 재생 중인지 여부 */
	UPROPERTY(BlueprintReadOnly, Category = "Zombie|Combat")
	bool bIsAttacking = false;

	/** 스턴 상태 */
	UPROPERTY(BlueprintReadOnly, Category = "Zombie|Combat")
	bool bIsStunned = false;

	// ─── 공개 함수 ──────────────────────────────────────────────────
	/** 피해 받기 (WeaponComponent의 LineTrace에서 호출) */
	UFUNCTION(BlueprintCallable, Category = "Zombie|Combat")
	void TakeDamageAmount(float DamageAmount);

	/** 공격 시작 (AIController에서 호출) */
	UFUNCTION(BlueprintCallable, Category = "Zombie|Combat")
	void StartAttack();

	/** 공격 히트 판정 (AnimNotify에서 21프레임에 호출) */
	UFUNCTION(BlueprintCallable, Category = "Zombie|Combat")
	void OnAttackHit();

	/** 공격 애니메이션 종료 콜백 */
	UFUNCTION(BlueprintCallable, Category = "Zombie|Combat")
	void OnAttackEnd();

	/** 스턴 적용 */
	UFUNCTION(BlueprintCallable, Category = "Zombie|Combat")
	void ApplyStun(float Duration);

	/** 공격 범위 내 플레이어 확인 */
	UFUNCTION(BlueprintPure, Category = "Zombie|Combat")
	bool IsPlayerInAttackRange() const;

	/** 사망 여부 */
	UFUNCTION(BlueprintPure, Category = "Zombie|Combat")
	bool IsDead() const { return CurrentHealth <= 0.f; }

	// ─── 공격 범위 ──────────────────────────────────────────────────
	UPROPERTY(EditDefaultsOnly, Category = "Zombie|Combat")
	float AttackRange = 150.f; // 1.5m

protected:
	void Die();

	/** 스턴 해제 타이머 핸들 */
	FTimerHandle StunTimerHandle;

	/** 스턴 해제 */
	void RemoveStun();

	/** 사망 시 블루프린트 이벤트 */
	UFUNCTION(BlueprintNativeEvent, Category = "Zombie|Combat")
	void OnDeath();
	virtual void OnDeath_Implementation();
};
