// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
// Lyra(Epic Games) LyraCameraAssistInterface 이식
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "ZombieCameraAssistInterface.generated.h"

UINTERFACE(BlueprintType)
class UZombieCameraAssistInterface : public UInterface
{
	GENERATED_BODY()
};

class IZombieCameraAssistInterface
{
	GENERATED_BODY()

public:
	/** 카메라 관통을 허용할 액터 목록 (탈것, 추가 뷰 타겟 등) */
	virtual void GetIgnoredActorsForCameraPentration(TArray<const AActor*>& OutActorsAllowPenetration) const { }

	/** 관통 방지 대상 액터. 미구현 시 뷰 타겟 사용 */
	virtual TOptional<AActor*> GetCameraPreventPenetrationTarget() const
	{
		return TOptional<AActor*>();
	}

	/** 카메라가 포커스 타겟을 관통했을 때 호출 (타겟 숨김 처리 등에 사용) */
	virtual void OnCameraPenetratingTarget() { }
};
