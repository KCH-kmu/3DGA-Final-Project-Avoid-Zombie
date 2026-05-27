// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ZombieAttackNotify.h"
#include "ZombieCharacter.h"
#include "Components/SkeletalMeshComponent.h"

void UZombieAttackNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (!MeshComp) return;
	if (AZombieCharacter* Zombie = Cast<AZombieCharacter>(MeshComp->GetOwner()))
		Zombie->OnAttackHit();
}
