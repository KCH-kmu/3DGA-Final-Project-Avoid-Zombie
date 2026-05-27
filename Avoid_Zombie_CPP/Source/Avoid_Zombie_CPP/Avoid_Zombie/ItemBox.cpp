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

	// 이미 아이템 보유 중이면 수령 무시
	if (Weapon->HeldItem != EItemType::None) return;

	Weapon->ReceiveItem(ContainedItem);
	UE_LOG(LogTemp, Log, TEXT("[ItemBox] 아이템 전달: %d"), (int32)ContainedItem);

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
