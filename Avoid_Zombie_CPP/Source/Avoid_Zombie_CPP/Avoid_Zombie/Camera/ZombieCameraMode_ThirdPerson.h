// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
// Lyra(Epic Games) LyraCameraMode_ThirdPerson 이식
#pragma once

#include "ZombieCameraMode.h"
#include "Curves/CurveFloat.h"
#include "ZombiePenetrationAvoidanceFeeler.h"
#include "DrawDebugHelpers.h"
#include "ZombieCameraMode_ThirdPerson.generated.h"

class UCurveVector;

/**
 * UZombieCameraMode_ThirdPerson
 *
 *	기본 3인칭 카메라 모드
 *	- 피치 각도에 따라 커브로 카메라 오프셋 계산
 *	- 필러 레이 기반 벽 뚫림 방지 (예측 회피 포함)
 */
UCLASS(Blueprintable)
class AVOID_ZOMBIE_CPP_API UZombieCameraMode_ThirdPerson : public UZombieCameraMode
{
	GENERATED_BODY()

public:

	UZombieCameraMode_ThirdPerson();

protected:

	virtual void UpdateView(float DeltaTime) override;

	void UpdateForTarget(float DeltaTime);
	void UpdatePreventPenetration(float DeltaTime);
	void PreventCameraPenetration(class AActor const& ViewTarget, FVector const& SafeLoc, FVector& CameraLoc, float const& DeltaTime, float& DistBlockedPct, bool bSingleRayOnly);

	virtual void DrawDebug(UCanvas* Canvas) const override;

protected:

	// 뷰 피치로 평가하는, 타겟 기준 로컬 공간 오프셋 커브 (커브 에셋)
	UPROPERTY(EditDefaultsOnly, Category = "Third Person", Meta = (EditCondition = "!bUseRuntimeFloatCurves"))
	TObjectPtr<const UCurveVector> TargetOffsetCurve;

	// true면 커브 에셋 대신 아래 런타임 커브 사용
	UPROPERTY(EditDefaultsOnly, Category = "Third Person")
	bool bUseRuntimeFloatCurves;

	UPROPERTY(EditDefaultsOnly, Category = "Third Person", Meta = (EditCondition = "bUseRuntimeFloatCurves"))
	FRuntimeFloatCurve TargetOffsetX;

	UPROPERTY(EditDefaultsOnly, Category = "Third Person", Meta = (EditCondition = "bUseRuntimeFloatCurves"))
	FRuntimeFloatCurve TargetOffsetY;

	UPROPERTY(EditDefaultsOnly, Category = "Third Person", Meta = (EditCondition = "bUseRuntimeFloatCurves"))
	FRuntimeFloatCurve TargetOffsetZ;

	// 앉기 오프셋 블렌드 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Third Person")
	float CrouchOffsetBlendMultiplier = 5.0f;

	// 관통 방지
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	float PenetrationBlendInTime = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	float PenetrationBlendOutTime = 0.15f;

	/** true면 충돌 검사로 카메라가 월드를 뚫지 않게 유지 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	bool bPreventPenetration = true;

	/** true면 주변 벽을 미리 감지해 카메라를 당겨 팝핑 방지 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	bool bDoPredictiveAvoidance = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	float CollisionPushOutDistance = 2.f;

	/** 관통으로 인해 카메라 거리가 이 비율까지 밀려들어오면 보고 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	float ReportPenetrationPercent = 0.f;

	/**
	 * 카메라 배치 위치를 찾는 필러 레이들
	 * Index 0  : 충돌 방지에 사용하는 기본 필러
	 * Index 1+ : bDoPredictiveAvoidance=true일 때 잠재적 충돌을 미리 스캔하는 필러
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Collision")
	TArray<FZombiePenetrationAvoidanceFeeler> PenetrationAvoidanceFeelers;

	UPROPERTY(Transient)
	float AimLineToDesiredPosBlockedPct;

	UPROPERTY(Transient)
	TArray<TObjectPtr<const AActor>> DebugActorsHitDuringCameraPenetration;

#if ENABLE_DRAW_DEBUG
	mutable float LastDrawDebugTime = -MAX_FLT;
#endif

protected:

	void SetTargetCrouchOffset(FVector NewTargetOffset);
	void UpdateCrouchOffset(float DeltaTime);

	FVector InitialCrouchOffset = FVector::ZeroVector;
	FVector TargetCrouchOffset = FVector::ZeroVector;
	float CrouchOffsetBlendPct = 1.0f;
	FVector CurrentCrouchOffset = FVector::ZeroVector;

};


/**
 * UZombieCameraMode_Death
 *
 *	사망(게임오버) 카메라 모드
 *	- 카메라가 천천히 멀어지며 위로 올라가 게임오버 UI 뒤 배경 연출
 */
UCLASS(Blueprintable)
class AVOID_ZOMBIE_CPP_API UZombieCameraMode_Death : public UZombieCameraMode_ThirdPerson
{
	GENERATED_BODY()

public:

	UZombieCameraMode_Death();
};
