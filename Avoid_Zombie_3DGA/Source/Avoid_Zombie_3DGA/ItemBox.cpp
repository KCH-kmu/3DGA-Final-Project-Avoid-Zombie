// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

#include "ItemBox.h"
#include "AvoidZombieCharacter.h"
#include "WeaponComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// 정적 멤버 초기화
TWeakObjectPtr<AItemBox> AItemBox::ActiveItemBox = nullptr;

AItemBox::AItemBox()
{
	PrimaryActorTick.bCanEverTick = false;

	// ─── 메시 컴포넌트 ────────────────────────────────────────────
	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	RootComponent = BoxMesh;

	// ─── 오버랩 구체 ──────────────────────────────────────────────
	OverlapSphere = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapSphere"));
	OverlapSphere->SetupAttachment(RootComponent);
	OverlapSphere->SetSphereRadius(80.f);   // 수령 반경
	OverlapSphere->SetCollisionProfileName(TEXT("Trigger"));

	OverlapSphere->OnComponentBeginOverlap.AddDynamic(this, &AItemBox::OnOverlapBegin);
}

void AItemBox::BeginPlay()
{
	Super::BeginPlay();

	// 이미 맵에 ItemBox가 존재하면 자신을 제거
	if (ActiveItemBox.IsValid() && ActiveItemBox.Get() != this)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ItemBox] 이미 맵에 존재 → 중복 스폰 제거"));
		Destroy();
		return;
	}

	// 현재 활성 박스로 등록
	ActiveItemBox = this;

	// 랜덤 아이템 결정
	ContainedItem = GetRandomItemType();

	UE_LOG(LogTemp, Log, TEXT("[ItemBox] 스폰 완료 - 아이템: %d"), (int32)ContainedItem);
}

// ─── 플레이어 오버랩 수령 ────────────────────────────────────────────────
void AItemBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
                               AActor* OtherActor,
                               UPrimitiveComponent* OtherComp,
                               int32 OtherBodyIndex,
                               bool bFromSweep,
                               const FHitResult& SweepResult)
{
	AAvoidZombieCharacter* Player = Cast<AAvoidZombieCharacter>(OtherActor);
	if (!Player) return;

	// 이미 아이템을 보유 중이면 수령 무시
	if (UWeaponComponent* Weapon = Player->WeaponComponent)
	{
		if (Weapon->HeldItem != EItemType::None)
		{
			UE_LOG(LogTemp, Log, TEXT("[ItemBox] 아이템 보유 중 → 수령 무시"));
			return;
		}

		// 아이템 전달
		Weapon->ReceiveItem(ContainedItem);
		UE_LOG(LogTemp, Log, TEXT("[ItemBox] 플레이어에게 아이템 전달: %d"), (int32)ContainedItem);
	}

	// 박스 제거
	ActiveItemBox = nullptr;
	Destroy();
}

// ─── 정적 스폰 함수 ───────────────────────────────────────────────────────
AItemBox* AItemBox::SpawnItemBox(UObject* WorldContextObject,
                                  TSubclassOf<AItemBox> BoxClass,
                                  const TArray<AActor*>& SpawnPointActors)
{
	// 이미 박스가 있으면 스폰 안 함
	if (ActiveItemBox.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("[ItemBox] 이미 맵에 존재 → 스폰 스킵"));
		return nullptr;
	}

	if (SpawnPointActors.IsEmpty() || !BoxClass) return nullptr;

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World) return nullptr;

	// 랜덤 스폰 포인트 선택
	const int32 RandIdx = FMath::RandRange(0, SpawnPointActors.Num() - 1);
	AActor* SpawnPoint = SpawnPointActors[RandIdx];
	if (!SpawnPoint) return nullptr;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AItemBox* NewBox = World->SpawnActor<AItemBox>(
		BoxClass,
		SpawnPoint->GetActorLocation(),
		SpawnPoint->GetActorRotation(),
		Params
	);

	UE_LOG(LogTemp, Log, TEXT("[ItemBox] 새 박스 스폰 (포인트 %d)"), RandIdx);
	return NewBox;
}

// ─── 랜덤 아이템 타입 ────────────────────────────────────────────────────
EItemType AItemBox::GetRandomItemType() const
{
	// 3종류 중 균등 확률
	const int32 Rand = FMath::RandRange(1, 3);
	switch (Rand)
	{
	case 1: return EItemType::StunAll;
	case 2: return EItemType::FireRateUp;
	case 3: return EItemType::HealSelf;
	default: return EItemType::StunAll;
	}
}
