// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ZombieAttackNotify.generated.h"

/**
 * 좀비 공격 히트 판정 AnimNotify
 * Attack2 몽타주의 21프레임 위치에 배치.
 * → ZombieCharacter::OnAttackHit() 호출
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API UZombieAttackNotify : public UAnimNotify
{
	GENERATED_BODY()
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
