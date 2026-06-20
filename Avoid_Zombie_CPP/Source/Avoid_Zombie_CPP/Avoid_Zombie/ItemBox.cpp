// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.

#include "ItemBox.h"
#include "ZombiePlayerCharacter.h"
#include "WeaponComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

TWeakObjectPtr<AItemBox> AItemBox::ActiveItemBox = nullptr;

AItemBox::AItemBox()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	RootComponent = BoxMesh;
	// 몸으로 통과해서 먹어야 하므로 메시는 충돌/막힘 없음 (픽업은 아래 OverlapSphere가 담당)
	BoxMesh->SetCollisionProfileName(TEXT("NoCollision"));
	BoxMesh->SetGenerateOverlapEvents(false);

	OverlapSphere = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapSphere"));
	OverlapSphere->SetupAttachment(RootComponent);
	OverlapSphere->SetSphereRadius(80.f);
	OverlapSphere->SetCollisionProfileName(TEXT("Trigger"));
	OverlapSphere->OnComponentBeginOverlap.AddDynamic(this, &AItemBox::OnOverlapBegin);
}

void AItemBox::BeginPlay()
{
	Super::BeginPlay();

	// 이미 맵에 박스가 있으면 자신을 제거
	if (ActiveItemBox.IsValid() && ActiveItemBox.Get() != this)
	{
		Destroy();
		return;
	}

	ActiveItemBox  = this;
	ContainedItem  = GetRandomItemType();
}

void AItemBox::OnOverlapBegin(UPrimitiveComponent*, AActor* OtherActor,
                               UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	AZombiePlayerCharacter* Player = Cast<AZombiePlayerCharacter>(OtherActor);
	if (!Player) return;

	UWeaponComponent* Weapon = Player->WeaponComp;
	if (!Weapon) return;

	// 미보유면 새 아이템 지급. 이미 보유 중이면 기존 아이템을 그대로 유지하고
	// 새 아이템은 버린다. 어느 경우든 박스 자체는 소멸한다.
	if (Weapon->HeldItem == EItemType::None)
	{
		Weapon->ReceiveItem(ContainedItem);
		UE_LOG(LogTemp, Log, TEXT("[ItemBox] 아이템 전달: %d"), (int32)ContainedItem);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[ItemBox] 이미 아이템 보유 — 박스만 소멸(기존 아이템 유지)"));
	}

	ActiveItemBox = nullptr;
	Destroy();
}

AItemBox* AItemBox::SpawnItemBox(UObject* WorldContextObject,
                                  TSubclassOf<AItemBox> BoxClass,
                                  const TArray<AActor*>& SpawnPoints)
{
	if (ActiveItemBox.IsValid()) return nullptr;
	if (SpawnPoints.IsEmpty() || !BoxClass) return nullptr;

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World) return nullptr;

	const int32 Idx = FMath::RandRange(0, SpawnPoints.Num() - 1);
	if (!SpawnPoints[Idx]) return nullptr;

	FActorSpawnParameters P;
	P.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	return World->SpawnActor<AItemBox>(BoxClass,
		SpawnPoints[Idx]->GetActorLocation(),
		SpawnPoints[Idx]->GetActorRotation(), P);
}

EItemType AItemBox::GetRandomItemType() const
{
	switch (FMath::RandRange(1, 3))
	{
	case 1:  return EItemType::StunAll;
	case 2:  return EItemType::FireRateUp;
	default: return EItemType::HealSelf;
	}
}
