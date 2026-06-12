// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
// Lyra(Epic Games) LyraPenetrationAvoidanceFeeler 이식
#pragma once

#include "CoreMinimal.h"

#include "ZombiePenetrationAvoidanceFeeler.generated.h"

/**
 * 카메라 벽 뚫림 방지에 사용하는 필러(feeler) 레이 정의 구조체
 */
USTRUCT()
struct FZombiePenetrationAvoidanceFeeler
{
	GENERATED_BODY()

	/** 메인 레이 기준 편차 회전 */
	UPROPERTY(EditAnywhere, Category = PenetrationAvoidanceFeeler)
	FRotator AdjustmentRot;

	/** 월드에 맞았을 때 최종 위치에 주는 영향 */
	UPROPERTY(EditAnywhere, Category = PenetrationAvoidanceFeeler)
	float WorldWeight;

	/** Pawn에 맞았을 때 최종 위치에 주는 영향 (0이면 Pawn과 충돌 안 함) */
	UPROPERTY(EditAnywhere, Category = PenetrationAvoidanceFeeler)
	float PawnWeight;

	/** 이 필러 트레이스에 사용할 콜리전 크기 */
	UPROPERTY(EditAnywhere, Category = PenetrationAvoidanceFeeler)
	float Extent;

	/** 지난 프레임에 아무것도 안 맞았을 때 트레이스 최소 프레임 간격 */
	UPROPERTY(EditAnywhere, Category = PenetrationAvoidanceFeeler)
	int32 TraceInterval;

	/** 이 필러가 사용된 후 지난 프레임 수 */
	UPROPERTY(transient)
	int32 FramesUntilNextTrace;


	FZombiePenetrationAvoidanceFeeler()
		: AdjustmentRot(ForceInit)
		, WorldWeight(0)
		, PawnWeight(0)
		, Extent(0)
		, TraceInterval(0)
		, FramesUntilNextTrace(0)
	{
	}

	FZombiePenetrationAvoidanceFeeler(const FRotator& InAdjustmentRot,
									const float& InWorldWeight,
									const float& InPawnWeight,
									const float& InExtent,
									const int32& InTraceInterval = 0,
									const int32& InFramesUntilNextTrace = 0)
		: AdjustmentRot(InAdjustmentRot)
		, WorldWeight(InWorldWeight)
		, PawnWeight(InPawnWeight)
		, Extent(InExtent)
		, TraceInterval(InTraceInterval)
		, FramesUntilNextTrace(InFramesUntilNextTrace)
	{
	}
};
