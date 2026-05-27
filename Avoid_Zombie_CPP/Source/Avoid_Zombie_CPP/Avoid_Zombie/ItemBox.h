// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponComponent.h"
#include "ItemBox.generated.h"

class USphereComponent;
class UStaticMeshComponent;

/**
 * 아이템 박스 (?상자)
 * - 맵에 하나만 존재
 * - 플레이어 오버랩 시 수령
 * - 이미 아이템 보유 중이면 무시
 * - 3종류 아이템 랜덤 지급
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API AItemBox : public AActor
{
	GENERATED_BODY()

public:
	AItemBox();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ItemBox")
	TObjectPtr<UStaticMeshComponent> BoxMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ItemBox")
	TObjectPtr<USphereComponent> OverlapSphere;

	UPROPERTY(BlueprintReadOnly, Category = "ItemBox")
	EItemType ContainedItem;

	/** 현재 맵에 있는 ItemBox (맵 1개 제한) */
	static TWeakObjectPtr<AItemBox> ActiveItemBox;

	/** 랜덤 위치에 ItemBox 스폰 (이미 있으면 스킵) */
	UFUNCTION(BlueprintCallable, Category = "ItemBox", meta=(WorldContext="WorldContextObject"))
	static AItemBox* SpawnItemBox(UObject* WorldContextObject,
	                              TSubclassOf<AItemBox> BoxClass,
	                              const TArray<AActor*>& SpawnPoints);

protected:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	                    AActor* OtherActor,
	                    UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex,
	                    bool bFromSweep,
	                    const FHitResult& SweepResult);

	EItemType GetRandomItemType() const;
};
