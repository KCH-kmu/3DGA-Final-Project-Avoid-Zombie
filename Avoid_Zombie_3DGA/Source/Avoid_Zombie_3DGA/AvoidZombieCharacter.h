// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AvoidZombieCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UWeaponComponent;
class UInputMappingContext;
class UInputAction;

/**
 * 플레이어 캐릭터
 *
 * 기능:
 * - WASD 이동 (2m/s), Shift 달리기 (4m/s)
 * - 달리기 중 공격 불가
 * - X 점프
 * - 마우스로 카메라/공격 방향 제어
 * - 최대 체력 10
 * - WeaponComponent로 사격/재장전
 */
UCLASS()
class AVOID_ZOMBIE_3DGA_API AAvoidZombieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAvoidZombieCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// ─── 카메라 ─────────────────────────────────────────────────────
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

	// ─── 무기 컴포넌트 ──────────────────────────────────────────────
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	TObjectPtr<UWeaponComponent> WeaponComponent;

	// ─── 체력 ───────────────────────────────────────────────────────
	/** 최대 체력 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float MaxHealth = 10.f;

	/** 현재 체력 */
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

	/** 피해 받기 */
	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeDamageAmount(float DamageAmount);

	/** 체력 회복 */
	UFUNCTION(BlueprintCallable, Category = "Health")
	void HealHealth(float Amount);

	/** 사망 여부 */
	UFUNCTION(BlueprintPure, Category = "Health")
	bool IsDead() const { return CurrentHealth <= 0.f; }

	// ─── 이동 상태 ──────────────────────────────────────────────────
	/** 현재 달리기 중인지 여부 (BlendSpace, 무기 공격 제한용) */
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsSprinting = false;

	// ─── Enhanced Input 매핑 (에디터에서 할당) ─────────────────────
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> ReloadAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> UseItemAction;

protected:
	// ─── 이동 속도 상수 ──────────────────────────────────────────────
	/** 기본 이동 속도: 2m/s = 200cm/s */
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float WalkSpeed = 200.f;

	/** 달리기 속도: 4m/s = 400cm/s */
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float SprintSpeed = 400.f;

	// ─── 입력 콜백 ───────────────────────────────────────────────────
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartSprint();
	void StopSprint();
	void StartFire();
	void StopFire();
	void Reload();
	void UseItem();

	// ─── 사망 처리 ───────────────────────────────────────────────────
	void Die();

	/** 사망 후 GameMode에 알림 (블루프린트에서 오버라이드 가능) */
	UFUNCTION(BlueprintNativeEvent, Category = "Health")
	void OnDeath();
	virtual void OnDeath_Implementation();
};
