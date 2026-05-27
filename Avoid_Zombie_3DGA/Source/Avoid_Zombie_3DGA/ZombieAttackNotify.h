// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ZombieAttackNotify.generated.h"

/**
 * 좀비 공격 히트 판정 AnimNotify
 *
 * Attack2 몽타주의 21프레임 위치에 이 노티파이를 배치하면
 * ZombieCharacter::OnAttackHit()가 호출되어 플레이어에게 데미지를 줍니다.
 *
 * 에디터 설정:
 * 1. Attack2 AnimMontage를 열고
 * 2. 21프레임 위치에 우클릭 → Add Notify → ZombieAttackNotify 선택
 */
UCLASS()
class AVOID_ZOMBIE_3DGA_API UZombieAttackNotify : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
