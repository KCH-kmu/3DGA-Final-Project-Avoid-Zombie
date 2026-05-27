// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "ZombieAttackNotify.h"
#include "ZombieCharacter.h"
#include "Components/SkeletalMeshComponent.h"

void UZombieAttackNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (!MeshComp) return;

	// 소유 액터가 ZombieCharacter인지 확인
	AZombieCharacter* Zombie = Cast<AZombieCharacter>(MeshComp->GetOwner());
	if (Zombie)
	{
		// 21프레임 히트 판정 실행
		Zombie->OnAttackHit();
	}
}
