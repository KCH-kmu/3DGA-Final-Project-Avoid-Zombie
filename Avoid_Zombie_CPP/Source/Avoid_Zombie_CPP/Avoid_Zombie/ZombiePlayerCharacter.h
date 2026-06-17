// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Templates/SubclassOf.h"
#include "ZombiePlayerCharacter.generated.h"

class UZombieCameraComponent;
class UZombieCameraMode;
class UWeaponComponent;
class UInputMappingContext;
class UInputAction;
class UStaticMeshComponent;
class UAnimMontage;

/** 체력 변경 델리게이트 (현재 체력, 최대 체력) */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, CurrentHealth, float, MaxHealth);

/**
 * Avoid Zombie 플레이어 캐릭터
 *
 * - WASD 이동 (2m/s), Shift 달리기 (4m/s)
 * - 달리기 중 공격 불가
 * - 체력 최대 10
 * - WeaponComponent (AR) 부착
 * - 좌클릭 사격, R 재장전, 우클릭 아이템 사용
 * - 마우스로 카메라 & 공격 방향 제어
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API AZombiePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AZombiePlayerCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// ─── 카메라 (Lyra 이식: 카메라 모드 스택 기반, 스프링암 없음) ───
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UZombieCameraComponent> CameraComp;

	/** 평상시 카메라 모드 */
	UPROPERTY(EditDefaultsOnly, Category = "Camera")
	TSubclassOf<UZombieCameraMode> DefaultCameraMode;

	/** 사망 시 카메라 모드 (게임오버 UI 배경 연출용, 미지정 시 평상시 모드 유지) */
	UPROPERTY(EditDefaultsOnly, Category = "Camera")
	TSubclassOf<UZombieCameraMode> DeathCameraMode;

	// ─── 무기 컴포넌트 ──────────────────────────────────────────────
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	TObjectPtr<UWeaponComponent> WeaponComp;

	// ─── 무기 비주얼 메시 (손에 부착되는 소총) ──────────────────────
	// 생성자에서 hand_r 본에 부착됨. 정확한 소켓/위치는 BP에서
	// 이 컴포넌트의 Parent Socket·Transform으로 조정 (뷰포트에 그대로 반영됨)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	TObjectPtr<UStaticMeshComponent> WeaponMeshComp;

	// ─── 무장 애니메이션 몽타주 (에디터에서 할당) ──────────────────
	/** 발사 시 재생할 몽타주 (예: AM_Rifle_Fire) */
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	TObjectPtr<UAnimMontage> FireMontage;

	/** 재장전 시 재생할 몽타주 (예: AM_Rifle_Reload, 길이는 재장전 시간에 맞춰 자동 보정) */
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	TObjectPtr<UAnimMontage> ReloadMontage;

	// ─── 체력 델리게이트 ────────────────────────────────────────────
	/** 체력 변경 시 broadcast (HUD 갱신용) */
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChanged OnHealthChanged;

	// ─── 체력 ───────────────────────────────────────────────────────
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float MaxHealth = 10.f;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeDamageAmount(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void HealHealth(float Amount);

	UFUNCTION(BlueprintPure, Category = "Health")
	bool IsDead() const { return CurrentHealth <= 0.f; }

	/** 현재 발사 가능한 상태인지 (사망/달리기/복귀 회전/공중/과도한 조준각이면 불가) — HUD 표시용 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	bool CanFire() const { return !IsDead() && !bIsSprinting && !bRealigningToCamera && !IsInAir() && !IsAimBlocked(); }

	/** 공중(낙하/점프) 상태인지 — 공중에서는 발사 불가 */
	UFUNCTION(BlueprintPure, Category = "Movement")
	bool IsInAir() const;

	/** 위/아래를 허용각보다 가파르게 보면 true → 총기 기울기 정지 + 발사 불가 (위/아래 각도 분리) */
	UFUNCTION(BlueprintPure, Category = "Aim")
	bool IsAimBlocked() const { const float P = GetAimPitch(); return P > MaxAimPitchUp || P < -MaxAimPitchDown; }

	// ─── AnimBP용 조준/상태 헬퍼 (Aim Offset·블렌드 배선용) ─────────
	/** 조준 상하각: 컨트롤 회전 Pitch (-90~90). Aim Offset 세로축에 연결 */
	UFUNCTION(BlueprintPure, Category = "Aim")
	float GetAimPitch() const;

	/** 조준 좌우각: 컨트롤 회전 Yaw - 액터 Yaw (-180~180). Aim Offset 가로축에 연결 */
	UFUNCTION(BlueprintPure, Category = "Aim")
	float GetAimYaw() const;

	/** 재장전 중인지 (AnimBP 상체 블렌드 조건용) */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	bool IsReloading() const;

	/** 왼손 IK 타겟 — 소총 'LeftHandGrip' 소켓의 월드 트랜스폼 (AnimBP Two Bone IK 이펙터용) */
	UFUNCTION(BlueprintPure, Category = "Aim")
	FTransform GetLeftHandIKTransform() const;

	// ─── 이동 상태 ──────────────────────────────────────────────────
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsSprinting = false;

	// ─── 입력 액션 (에디터에서 할당) ────────────────────────────────
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> MappingContext;

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
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float WalkSpeed = 200.f;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float SprintSpeed = 400.f;

	/** 발사 버튼을 누르고 있는지 (달리기 종료 시 발사 재개용) */
	bool bWantsToFire = false;

	/** 달리기 종료 후 카메라 방향으로 부드럽게 회전 중인지 */
	bool bRealigningToCamera = false;

	/** 달리기 종료 시 카메라 방향으로 회전하는 속도 (도/초, 일정 속도) */
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float RealignSpeed = 600.f;

	/** 정면 기준 이 각도(도) 이내로 돌아오면 발사 재개 */
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float FireAlignAngle = 20.f;

	/** 조준점 계산용 트레이스 거리 (무기 사거리와 동일하게) */
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float AimTraceDistance = 10000.f;

	/** 조준점을 향해 캐릭터가 회전하는 보간 속도 */
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float AimFaceInterpSpeed = 20.f;

	/** 달리기 중 이동(속도) 방향을 바라보는 회전 보간 속도 */
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float SprintFaceInterpSpeed = 10.f;

	/** 총기 비주얼이 시점(상하)을 따라 기울어지는 정도. 위아래가 뒤집히면 부호 반대로, 0이면 끔 */
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float GunPitchScale = -1.0f;

	/** 위로 이 각도(도) 넘게 보면 총기 기울기 정지 + 발사 불가 (위쪽이 더 어색해 작게) */
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float MaxAimPitchUp = 40.f;

	/** 아래로 이 각도(도) 넘게 보면 총기 기울기 정지 + 발사 불가 */
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float MaxAimPitchDown = 60.f;

	/** BeginPlay에서 저장하는 소총의 기본 상대 회전 (BP에서 맞춘 그립 기준값) */
	FRotator WeaponRestRelativeRotation = FRotator::ZeroRotator;

	/** 어깨 오프셋 카메라 기준 실제 조준점(크로스헤어가 가리키는 곳)을 바라보도록 회전 */
	void FaceAimPoint(float DeltaTime);

	/** 달리기 중 이동(velocity) 방향을 바라보도록 회전 — 정면 달리기(키보드 방향) */
	void FaceMovementDirection(float DeltaTime);

	/** 카메라 컴포넌트가 매 프레임 묻는 현재 카메라 모드 (사망 시 DeathCameraMode 반환) */
	TSubclassOf<UZombieCameraMode> DetermineCameraMode() const;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartSprint();
	void StopSprint();
	void StartFire();
	void StopFire();
	void Reload();
	void UseItem();
	void Die();

	// ─── 무장 애니메이션 이벤트 핸들러 (WeaponComp 델리게이트 바인딩) ──
	/** 발사 1회 시 발사 몽타주 재생 */
	UFUNCTION()
	void HandleWeaponFired();

	/** 재장전 시작 시 재장전 몽타주 재생 (재장전 시간에 맞춰 재생속도 보정) */
	UFUNCTION()
	void HandleReloadStarted(float ReloadTime);

	UFUNCTION(BlueprintNativeEvent, Category = "Health")
	void OnDeath();
	virtual void OnDeath_Implementation();
};
