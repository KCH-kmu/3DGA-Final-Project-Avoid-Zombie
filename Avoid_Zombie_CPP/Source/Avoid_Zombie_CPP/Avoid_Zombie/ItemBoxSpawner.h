// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBoxSpawner.generated.h"

class AItemBox;

/**
 * 아이템 박스 필드 드롭 스포너
 *
 * - 레벨에 1개 배치 (WaveManager처럼 인스턴스 액터)
 * - 스스로 타이머를 돌리지 않고, WaveManager가 '웨이브 클리어' 시 TrySpawnItemBox()를 호출해 드롭
 * - 좀비 포탈처럼 SpawnPoints(지정 위치) 중에서 랜덤 선택 (연속 같은 위치는 가급적 회피)
 * - 필드 1개 제한은 AItemBox가 보장 (이미 박스가 있으면 드롭 무시)
 */
UCLASS()
class AVOID_ZOMBIE_CPP_API AItemBoxSpawner : public AActor
{
	GENERATED_BODY()

public:
	AItemBoxSpawner();

	virtual void BeginPlay() override;

	/** 스폰할 아이템 박스 BP (GiftBox 메시 기반 BP_ItemBox 지정) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemBox")
	TSubclassOf<AItemBox> ItemBoxClass;

	/** 스폰 위치 후보 (레벨에 배치한 위치 마커). 좀비 포탈처럼 이 중에서 랜덤 선택 */
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "ItemBox")
	TArray<TObjectPtr<AActor>> SpawnPoints;

	/** 스폰 위치 Z 오프셋(cm) — 땅에 반쯤 묻히면 올림 */
	UPROPERTY(EditAnywhere, Category = "ItemBox")
	float SpawnZOffset = 0.f;

	/** 박스가 없으면 1개 드롭. 이미 있으면 무시. 드롭 성공 시 true (WaveManager가 호출) */
	UFUNCTION(BlueprintCallable, Category = "ItemBox")
	bool TrySpawnItemBox();

protected:
	/** 직전에 사용한 SpawnPoints 인덱스 (연속 같은 위치 방지) */
	int32 LastSpawnIndex = INDEX_NONE;

	/** SpawnPoints 중 랜덤 인덱스 선택 (직전 위치는 가급적 회피). 없으면 INDEX_NONE */
	int32 PickSpawnPointIndex();
};
