// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ItemBoxSpawner.h"
#include "ItemBox.h"
#include "Engine/World.h"

AItemBoxSpawner::AItemBoxSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AItemBoxSpawner::BeginPlay()
{
	Super::BeginPlay();

	// 타이머 없음 — WaveManager가 웨이브 클리어 시 TrySpawnItemBox()를 호출한다.
	if (!ItemBoxClass)
		UE_LOG(LogTemp, Warning, TEXT("[ItemBoxSpawner] ItemBoxClass 미지정 — 드롭 안 됨"));
	if (SpawnPoints.Num() == 0)
		UE_LOG(LogTemp, Warning, TEXT("[ItemBoxSpawner] SpawnPoints 비어있음 — 레벨에 위치 마커 지정 필요"));
}

bool AItemBoxSpawner::TrySpawnItemBox()
{
	// 이미 필드에 박스가 있으면 드롭하지 않음 (필드 1개 제한)
	if (AItemBox::ActiveItemBox.IsValid()) return false;
	if (!ItemBoxClass) return false;

	const int32 Idx = PickSpawnPointIndex();
	if (Idx == INDEX_NONE) return false;

	FVector Loc = SpawnPoints[Idx]->GetActorLocation();
	Loc.Z += SpawnZOffset;

	FActorSpawnParameters P;
	P.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (AItemBox* Box = GetWorld()->SpawnActor<AItemBox>(ItemBoxClass, Loc, FRotator::ZeroRotator, P))
	{
		LastSpawnIndex = Idx;
		UE_LOG(LogTemp, Log, TEXT("[ItemBoxSpawner] 박스 드롭 @ point[%d] %s"), Idx, *Loc.ToCompactString());
		return true;
	}
	return false;
}

int32 AItemBoxSpawner::PickSpawnPointIndex()
{
	// 유효한 스폰포인트 인덱스 수집
	TArray<int32> Valid;
	for (int32 i = 0; i < SpawnPoints.Num(); i++)
		if (SpawnPoints[i]) Valid.Add(i);

	if (Valid.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ItemBoxSpawner] SpawnPoints 비어있음 — 위치 마커 지정 필요"));
		return INDEX_NONE;
	}
	if (Valid.Num() == 1)
		return Valid[0];

	// 직전과 다른 위치를 우선 (연속 같은 자리 방지 → 더 랜덤하게 느껴지도록)
	TArray<int32> Candidates = Valid;
	Candidates.Remove(LastSpawnIndex);
	const TArray<int32>& Pool = (Candidates.Num() > 0) ? Candidates : Valid;
	return Pool[FMath::RandRange(0, Pool.Num() - 1)];
}
