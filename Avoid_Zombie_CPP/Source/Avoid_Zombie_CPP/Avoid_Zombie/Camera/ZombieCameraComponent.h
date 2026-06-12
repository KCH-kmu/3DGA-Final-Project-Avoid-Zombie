// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
// Lyra(Epic Games) LyraCameraComponent 이식
#pragma once

#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"

#include "ZombieCameraComponent.generated.h"

class UCanvas;
class UZombieCameraMode;
class UZombieCameraModeStack;
class UObject;
struct FFrame;
struct FGameplayTag;
struct FMinimalViewInfo;
template <class TClass> class TSubclassOf;

DECLARE_DELEGATE_RetVal(TSubclassOf<UZombieCameraMode>, FZombieCameraModeDelegate);


/**
 * UZombieCameraComponent
 *
 *	카메라 모드 스택 기반 카메라 컴포넌트 (스프링암 불필요)
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API UZombieCameraComponent : public UCameraComponent
{
	GENERATED_BODY()

public:

	UZombieCameraComponent(const FObjectInitializer& ObjectInitializer);

	// 지정된 액터에 카메라 컴포넌트가 있으면 반환
	UFUNCTION(BlueprintPure, Category = "Zombie|Camera")
	static UZombieCameraComponent* FindCameraComponent(const AActor* Actor) { return (Actor ? Actor->FindComponentByClass<UZombieCameraComponent>() : nullptr); }

	// 카메라가 바라보는 타겟 액터 반환
	virtual AActor* GetTargetActor() const { return GetOwner(); }

	// 최적 카메라 모드를 조회하는 델리게이트
	FZombieCameraModeDelegate DetermineCameraModeDelegate;

	// FOV 오프셋 추가. 한 프레임만 적용되며 적용 후 초기화됨
	void AddFieldOfViewOffset(float FovOffset) { FieldOfViewOffset += FovOffset; }

	virtual void DrawDebug(UCanvas* Canvas) const;

	// 최상위 레이어의 태그와 블렌드 가중치 반환
	void GetBlendInfo(float& OutWeightOfTopLayer, FGameplayTag& OutTagOfTopLayer) const;

protected:

	virtual void OnRegister() override;
	virtual void GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView) override;

	virtual void UpdateCameraModes();

protected:

	// 카메라 모드 블렌딩에 사용하는 스택
	UPROPERTY()
	TObjectPtr<UZombieCameraModeStack> CameraModeStack;

	// 시야각에 적용되는 오프셋. 한 프레임만 적용되며 적용 후 초기화됨
	float FieldOfViewOffset;

};
