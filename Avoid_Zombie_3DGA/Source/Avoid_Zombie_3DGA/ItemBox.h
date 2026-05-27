// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponComponent.h" // EItemType
#include "ItemBox.generated.h"

class USphereComponent;
class UStaticMeshComponent;

/**
 * 아이템 박스 (?상자)
 *
 * 규칙:
 * - 맵에 하나만 존재 (스폰 시 기존 박스 자동 제거)
 * - 플레이어 몸으로 닿으면 수령 (오버랩)
 * - 수령 시 WeaponComponent.ReceiveItem() 호출
 * - 이미 아이템을 보유 중이면 수령 무시
 *
 * 에디터 설정:
 * - 레벨에 여러 SpawnPoint Actor를 배치하고
 *   ItemBoxSpawnPoints 배열에 등록 (WaveManager 또는 GameMode에서 관리 가능)
 */
UCLASS()
class AVOID_ZOMBIE_3DGA_API AItemBox : public AActor
{
	GENERATED_BODY()

public:
	AItemBox();

	virtual void BeginPlay() override;

	// ─── 컴포넌트 ───────────────────────────────────────────────────
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ItemBox")
	TObjectPtr<UStaticMeshComponent> BoxMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ItemBox")
	TObjectPtr<USphereComponent> OverlapSphere;

	// ─── 아이템 타입 ─────────────────────────────────────────────────
	/** 이 박스가 담고 있는 아이템 (BeginPlay에서 랜덤 결정) */
	UPROPERTY(BlueprintReadOnly, Category = "ItemBox")
	EItemType ContainedItem;

	// ─── 스폰 지점 목록 (GameMode 또는 에디터에서 설정) ────────────
	/** 레벨에 배치된 스폰 포인트 액터들 */
	UPROPERTY(EditInstanceOnly, Category = "ItemBox|Spawn")
	TArray<TObjectPtr<AActor>> SpawnPoints;

	// ─── 정적 인스턴스 추적 (맵에 1개 제한) ────────────────────────
	/** 현재 맵에 존재하는 ItemBox (nullptr이면 없음) */
	static TWeakObjectPtr<AItemBox> ActiveItemBox;

	/** 새 ItemBox를 지정된 스폰 포인트들 중 랜덤 위치에 스폰 */
	UFUNCTION(BlueprintCallable, Category = "ItemBox", meta=(WorldContext="WorldContextObject"))
	static AItemBox* SpawnItemBox(UObject* WorldContextObject, TSubclassOf<AItemBox> BoxClass, const TArray<AActor*>& SpawnPointActors);

protected:
	/** 플레이어 오버랩 이벤트 */
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	                    AActor* OtherActor,
	                    UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex,
	                    bool bFromSweep,
	                    const FHitResult& SweepResult);

	/** 랜덤 아이템 타입 반환 */
	EItemType GetRandomItemType() const;
};
