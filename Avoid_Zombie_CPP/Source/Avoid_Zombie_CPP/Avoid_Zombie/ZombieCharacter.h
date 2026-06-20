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
	virtual void Tick(float DeltaTime) override;

	// ─── 회전(facing) 부드럽게 ──────────────────────────────────────
	/** facing 보간 속도. 클수록 빠르게 따라가고 작을수록 진동을 더 흡수 */
	UPROPERTY(EditDefaultsOnly, Category = "Zombie")
	float FacingInterpSpeed = 7.f;

	/** 이 속도(cm/s) 미만이면 '정지'로 보고 회전을 갱신하지 않음 (밀집 시 속도 노이즈로 인한 회전 떨림 방지) */
	UPROPERTY(EditDefaultsOnly, Category = "Zombie")
	float FacingSpeedThreshold = 50.f;

	/** GetGroundSpeed 스무딩 속도. 작을수록 더 부드럽지만 애니 반응이 느려짐 (속도 출렁임 → 로코모션 BlendSpace 떨림 방지) */
	UPROPERTY(EditDefaultsOnly, Category = "Zombie")
	float GroundSpeedInterpSpeed = 8.f;

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

	/** 공격 히트 부채꼴 반각(도). 정면 기준 ±이 각도 안에 있어야 피해 (예 60 → 정면 120° 부채꼴). 뒤/옆은 무효 */
	UPROPERTY(EditDefaultsOnly, Category = "Zombie")
	float AttackHalfAngle = 60.f;

	// ─── 애니메이션 ─────────────────────────────────────────────────
	/** Attack2 몽타주 — 21프레임에 ZombieAttackNotify 배치 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Zombie|Anim")
	TObjectPtr<UAnimMontage> AttackMontage;

	/** 사망 몽타주 — Anim_Whisper_Death 기반 (재생 후 마지막 포즈 유지) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Zombie|Anim")
	TObjectPtr<UAnimMontage> DeathMontage;

	/** 피격 리액션 몽타주 — Anim_Whisper_Taking_Damage1/2, 피격 시 랜덤 재생 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Zombie|Anim")
	TArray<TObjectPtr<UAnimMontage>> HitReactMontages;

	/** AnimBP 로코모션용 — 수평 이동 속도(cm/s) */
	UFUNCTION(BlueprintPure, Category = "Zombie|Anim")
	float GetGroundSpeed() const;

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

	/** 매 프레임 facing 갱신 — 이동 중엔 속도방향(스무딩), 정지/공격 중엔 플레이어 방향 */
	void UpdateFacing(float DeltaTime);

	/** GetGroundSpeed가 반환하는 스무딩된 수평속도 (BlendSpace 떨림 방지) */
	float SmoothedGroundSpeed = 0.f;

	void Die();
	void RemoveStun();

	UFUNCTION(BlueprintNativeEvent, Category = "Zombie")
	void OnDeath();
	virtual void OnDeath_Implementation();
};
