// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
// Lyra(Epic Games) LyraCameraMode 이식
#pragma once

#include "Engine/World.h"
#include "GameplayTagContainer.h"

#include "ZombieCameraMode.generated.h"

// LyraPlayerCameraManager의 기본값 상수 (카메라 매니저는 이식하지 않으므로 여기서 정의)
#define ZOMBIE_CAMERA_DEFAULT_FOV		(80.0f)
#define ZOMBIE_CAMERA_DEFAULT_PITCH_MIN	(-89.0f)
#define ZOMBIE_CAMERA_DEFAULT_PITCH_MAX	(89.0f)

class AActor;
class UCanvas;
class UZombieCameraComponent;

/**
 * EZombieCameraModeBlendFunction
 *
 *	카메라 모드 전환에 사용하는 블렌드 함수
 */
UENUM(BlueprintType)
enum class EZombieCameraModeBlendFunction : uint8
{
	// 단순 선형 보간
	Linear,

	// 즉시 가속, 목표에 부드럽게 감속. Exponent로 정도 조절
	EaseIn,

	// 부드럽게 가속, 감속 없음. Exponent로 정도 조절
	EaseOut,

	// 부드럽게 가속/감속. Exponent로 정도 조절
	EaseInOut,

	COUNT	UMETA(Hidden)
};


/**
 * FZombieCameraModeView
 *
 *	카메라 모드가 생성하는 뷰 데이터. 모드 간 블렌딩에 사용
 */
struct FZombieCameraModeView
{
public:

	FZombieCameraModeView();

	void Blend(const FZombieCameraModeView& Other, float OtherWeight);

public:

	FVector Location;
	FRotator Rotation;
	FRotator ControlRotation;
	float FieldOfView;
};


/**
 * UZombieCameraMode
 *
 *	모든 카메라 모드의 베이스 클래스
 */
UCLASS(Abstract, NotBlueprintable)
class AVOID_ZOMBIE_CPP_API UZombieCameraMode : public UObject
{
	GENERATED_BODY()

public:

	UZombieCameraMode();

	UZombieCameraComponent* GetZombieCameraComponent() const;

	virtual UWorld* GetWorld() const override;

	AActor* GetTargetActor() const;

	const FZombieCameraModeView& GetCameraModeView() const { return View; }

	// 카메라 모드 스택에서 활성화될 때 호출
	virtual void OnActivation() {};

	// 카메라 모드 스택에서 비활성화될 때 호출
	virtual void OnDeactivation() {};

	void UpdateCameraMode(float DeltaTime);

	float GetBlendTime() const { return BlendTime; }
	float GetBlendWeight() const { return BlendWeight; }
	void SetBlendWeight(float Weight);

	FGameplayTag GetCameraTypeTag() const
	{
		return CameraTypeTag;
	}

	virtual void DrawDebug(UCanvas* Canvas) const;

protected:

	virtual FVector GetPivotLocation() const;
	virtual FRotator GetPivotRotation() const;

	virtual void UpdateView(float DeltaTime);
	virtual void UpdateBlending(float DeltaTime);

protected:
	// 특정 모드를 직접 묻지 않고도 게임플레이 코드가 조회할 수 있는 태그 (예: 조준 중 여부)
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	FGameplayTag CameraTypeTag;

	// 카메라 모드가 출력하는 뷰
	FZombieCameraModeView View;

	// 수평 시야각 (도)
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "5.0", UIMax = "170", ClampMin = "5.0", ClampMax = "170.0"))
	float FieldOfView;

	// 최소 뷰 피치 (도)
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "-89.9", UIMax = "89.9", ClampMin = "-89.9", ClampMax = "89.9"))
	float ViewPitchMin;

	// 최대 뷰 피치 (도)
	UPROPERTY(EditDefaultsOnly, Category = "View", Meta = (UIMin = "-89.9", UIMax = "89.9", ClampMin = "-89.9", ClampMax = "89.9"))
	float ViewPitchMax;

	// 이 모드가 블렌드 인 되는 시간
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	float BlendTime;

	// 블렌딩에 사용할 함수
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	EZombieCameraModeBlendFunction BlendFunction;

	// 블렌드 곡선 모양을 제어하는 지수
	UPROPERTY(EditDefaultsOnly, Category = "Blending")
	float BlendExponent;

	// 블렌드 가중치 계산에 사용하는 선형 알파
	float BlendAlpha;

	// 블렌드 알파와 함수로 계산된 블렌드 가중치
	float BlendWeight;

protected:
	/** true면 보간을 모두 건너뛰고 카메라를 이상적인 위치에 즉시 배치. 다음 프레임에 자동으로 false */
	UPROPERTY(transient)
	uint32 bResetInterpolation:1;
};


/**
 * UZombieCameraModeStack
 *
 *	카메라 모드 블렌딩에 사용하는 스택
 */
UCLASS()
class UZombieCameraModeStack : public UObject
{
	GENERATED_BODY()

public:

	UZombieCameraModeStack();

	void ActivateStack();
	void DeactivateStack();

	bool IsStackActivate() const { return bIsActive; }

	void PushCameraMode(TSubclassOf<UZombieCameraMode> CameraModeClass);

	bool EvaluateStack(float DeltaTime, FZombieCameraModeView& OutCameraModeView);

	void DrawDebug(UCanvas* Canvas) const;

	// 최상위 레이어의 태그와 블렌드 가중치 반환
	void GetBlendInfo(float& OutWeightOfTopLayer, FGameplayTag& OutTagOfTopLayer) const;

protected:

	UZombieCameraMode* GetCameraModeInstance(TSubclassOf<UZombieCameraMode> CameraModeClass);

	void UpdateStack(float DeltaTime);
	void BlendStack(FZombieCameraModeView& OutCameraModeView) const;

protected:

	bool bIsActive;

	UPROPERTY()
	TArray<TObjectPtr<UZombieCameraMode>> CameraModeInstances;

	UPROPERTY()
	TArray<TObjectPtr<UZombieCameraMode>> CameraModeStack;
};
