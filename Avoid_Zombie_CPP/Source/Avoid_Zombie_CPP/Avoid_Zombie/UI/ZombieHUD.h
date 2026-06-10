// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ZombieHUD.generated.h"

class UZombieHUDWidget;

UCLASS()
class AVOID_ZOMBIE_CPP_API AZombieHUD : public AHUD
{
	GENERATED_BODY()

public:
	AZombieHUD();

	virtual void BeginPlay() override;

	/** 탄약 HUD 갱신 — WeaponComponent.OnAmmoChanged에 바인딩 */
	UFUNCTION()
	void OnAmmoChanged(int32 Current, int32 Max);

	/** 체력 HUD 갱신 — ZombiePlayerCharacter.OnHealthChanged에 바인딩 */
	UFUNCTION()
	void OnHealthChanged(float Current, float Max);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	TSubclassOf<UZombieHUDWidget> HUDWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UZombieHUDWidget> HUDWidget;
};
