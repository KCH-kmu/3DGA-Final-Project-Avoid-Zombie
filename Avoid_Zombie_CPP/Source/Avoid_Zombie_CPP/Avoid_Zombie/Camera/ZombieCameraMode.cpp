// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
// Lyra(Epic Games) LyraCameraMode 이식

#include "ZombieCameraMode.h"

#include "Components/CapsuleComponent.h"
#include "Engine/Canvas.h"
#include "GameFramework/Character.h"
#include "ZombieCameraComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(ZombieCameraMode)


//////////////////////////////////////////////////////////////////////////
// FZombieCameraModeView
//////////////////////////////////////////////////////////////////////////
FZombieCameraModeView::FZombieCameraModeView()
	: Location(ForceInit)
	, Rotation(ForceInit)
	, ControlRotation(ForceInit)
	, FieldOfView(ZOMBIE_CAMERA_DEFAULT_FOV)
{
}

void FZombieCameraModeView::Blend(const FZombieCameraModeView& Other, float OtherWeight)
{
	if (OtherWeight <= 0.0f)
	{
		return;
	}
	else if (OtherWeight >= 1.0f)
	{
		*this = Other;
		return;
	}

	Location = FMath::Lerp(Location, Other.Location, OtherWeight);

	const FRotator DeltaRotation = (Other.Rotation - Rotation).GetNormalized();
	Rotation = Rotation + (OtherWeight * DeltaRotation);

	const FRotator DeltaControlRotation = (Other.ControlRotation - ControlRotation).GetNormalized();
	ControlRotation = ControlRotation + (OtherWeight * DeltaControlRotation);

	FieldOfView = FMath::Lerp(FieldOfView, Other.FieldOfView, OtherWeight);
}


//////////////////////////////////////////////////////////////////////////
// UZombieCameraMode
//////////////////////////////////////////////////////////////////////////
UZombieCameraMode::UZombieCameraMode()
{
	FieldOfView = ZOMBIE_CAMERA_DEFAULT_FOV;
	ViewPitchMin = ZOMBIE_CAMERA_DEFAULT_PITCH_MIN;
	ViewPitchMax = ZOMBIE_CAMERA_DEFAULT_PITCH_MAX;

	BlendTime = 0.5f;
	BlendFunction = EZombieCameraModeBlendFunction::EaseOut;
	BlendExponent = 4.0f;
	BlendAlpha = 1.0f;
	BlendWeight = 1.0f;
}

UZombieCameraComponent* UZombieCameraMode::GetZombieCameraComponent() const
{
	return CastChecked<UZombieCameraComponent>(GetOuter());
}

UWorld* UZombieCameraMode::GetWorld() const
{
	return HasAnyFlags(RF_ClassDefaultObject) ? nullptr : GetOuter()->GetWorld();
}

AActor* UZombieCameraMode::GetTargetActor() const
{
	const UZombieCameraComponent* ZombieCameraComponent = GetZombieCameraComponent();

	return ZombieCameraComponent->GetTargetActor();
}

FVector UZombieCameraMode::GetPivotLocation() const
{
	const AActor* TargetActor = GetTargetActor();
	check(TargetActor);

	if (const APawn* TargetPawn = Cast<APawn>(TargetActor))
	{
		// 캐릭터의 경우 앉기(크라우치)를 고려한 높이 보정
		if (const ACharacter* TargetCharacter = Cast<ACharacter>(TargetPawn))
		{
			const ACharacter* TargetCharacterCDO = TargetCharacter->GetClass()->GetDefaultObject<ACharacter>();
			check(TargetCharacterCDO);

			const UCapsuleComponent* CapsuleComp = TargetCharacter->GetCapsuleComponent();
			check(CapsuleComp);

			const UCapsuleComponent* CapsuleCompCDO = TargetCharacterCDO->GetCapsuleComponent();
			check(CapsuleCompCDO);

			const float DefaultHalfHeight = CapsuleCompCDO->GetUnscaledCapsuleHalfHeight();
			const float ActualHalfHeight = CapsuleComp->GetUnscaledCapsuleHalfHeight();
			const float HeightAdjustment = (DefaultHalfHeight - ActualHalfHeight) + TargetCharacterCDO->BaseEyeHeight;

			return TargetCharacter->GetActorLocation() + (FVector::UpVector * HeightAdjustment);
		}

		return TargetPawn->GetPawnViewLocation();
	}

	return TargetActor->GetActorLocation();
}

FRotator UZombieCameraMode::GetPivotRotation() const
{
	const AActor* TargetActor = GetTargetActor();
	check(TargetActor);

	if (const APawn* TargetPawn = Cast<APawn>(TargetActor))
	{
		return TargetPawn->GetViewRotation();
	}

	return TargetActor->GetActorRotation();
}

void UZombieCameraMode::UpdateCameraMode(float DeltaTime)
{
	UpdateView(DeltaTime);
	UpdateBlending(DeltaTime);
}

void UZombieCameraMode::UpdateView(float DeltaTime)
{
	FVector PivotLocation = GetPivotLocation();
	FRotator PivotRotation = GetPivotRotation();

	PivotRotation.Pitch = FMath::ClampAngle(PivotRotation.Pitch, ViewPitchMin, ViewPitchMax);

	View.Location = PivotLocation;
	View.Rotation = PivotRotation;
	View.ControlRotation = View.Rotation;
	View.FieldOfView = FieldOfView;
}

void UZombieCameraMode::SetBlendWeight(float Weight)
{
	BlendWeight = FMath::Clamp(Weight, 0.0f, 1.0f);

	// 가중치를 직접 설정하므로 블렌드 함수를 고려해 알파를 역산한다
	const float InvExponent = (BlendExponent > 0.0f) ? (1.0f / BlendExponent) : 1.0f;

	switch (BlendFunction)
	{
	case EZombieCameraModeBlendFunction::Linear:
		BlendAlpha = BlendWeight;
		break;

	case EZombieCameraModeBlendFunction::EaseIn:
		BlendAlpha = FMath::InterpEaseIn(0.0f, 1.0f, BlendWeight, InvExponent);
		break;

	case EZombieCameraModeBlendFunction::EaseOut:
		BlendAlpha = FMath::InterpEaseOut(0.0f, 1.0f, BlendWeight, InvExponent);
		break;

	case EZombieCameraModeBlendFunction::EaseInOut:
		BlendAlpha = FMath::InterpEaseInOut(0.0f, 1.0f, BlendWeight, InvExponent);
		break;

	default:
		checkf(false, TEXT("SetBlendWeight: Invalid BlendFunction [%d]\n"), (uint8)BlendFunction);
		break;
	}
}

void UZombieCameraMode::UpdateBlending(float DeltaTime)
{
	if (BlendTime > 0.0f)
	{
		BlendAlpha += (DeltaTime / BlendTime);
		BlendAlpha = FMath::Min(BlendAlpha, 1.0f);
	}
	else
	{
		BlendAlpha = 1.0f;
	}

	const float Exponent = (BlendExponent > 0.0f) ? BlendExponent : 1.0f;

	switch (BlendFunction)
	{
	case EZombieCameraModeBlendFunction::Linear:
		BlendWeight = BlendAlpha;
		break;

	case EZombieCameraModeBlendFunction::EaseIn:
		BlendWeight = FMath::InterpEaseIn(0.0f, 1.0f, BlendAlpha, Exponent);
		break;

	case EZombieCameraModeBlendFunction::EaseOut:
		BlendWeight = FMath::InterpEaseOut(0.0f, 1.0f, BlendAlpha, Exponent);
		break;

	case EZombieCameraModeBlendFunction::EaseInOut:
		BlendWeight = FMath::InterpEaseInOut(0.0f, 1.0f, BlendAlpha, Exponent);
		break;

	default:
		checkf(false, TEXT("UpdateBlending: Invalid BlendFunction [%d]\n"), (uint8)BlendFunction);
		break;
	}
}

void UZombieCameraMode::DrawDebug(UCanvas* Canvas) const
{
	check(Canvas);

	FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;

	DisplayDebugManager.SetDrawColor(FColor::White);
	DisplayDebugManager.DrawString(FString::Printf(TEXT("      ZombieCameraMode: %s (%f)"), *GetName(), BlendWeight));
}


//////////////////////////////////////////////////////////////////////////
// UZombieCameraModeStack
//////////////////////////////////////////////////////////////////////////
UZombieCameraModeStack::UZombieCameraModeStack()
{
	bIsActive = true;
}

void UZombieCameraModeStack::ActivateStack()
{
	if (!bIsActive)
	{
		bIsActive = true;

		// 카메라 모드들에 활성화 알림
		for (UZombieCameraMode* CameraMode : CameraModeStack)
		{
			check(CameraMode);
			CameraMode->OnActivation();
		}
	}
}

void UZombieCameraModeStack::DeactivateStack()
{
	if (bIsActive)
	{
		bIsActive = false;

		// 카메라 모드들에 비활성화 알림
		for (UZombieCameraMode* CameraMode : CameraModeStack)
		{
			check(CameraMode);
			CameraMode->OnDeactivation();
		}
	}
}

void UZombieCameraModeStack::PushCameraMode(TSubclassOf<UZombieCameraMode> CameraModeClass)
{
	if (!CameraModeClass)
	{
		return;
	}

	UZombieCameraMode* CameraMode = GetCameraModeInstance(CameraModeClass);
	check(CameraMode);

	int32 StackSize = CameraModeStack.Num();

	if ((StackSize > 0) && (CameraModeStack[0] == CameraMode))
	{
		// 이미 스택 최상위
		return;
	}

	// 이미 스택에 있으면 제거하고, 스택에 기여하던 정도를 계산
	int32 ExistingStackIndex = INDEX_NONE;
	float ExistingStackContribution = 1.0f;

	for (int32 StackIndex = 0; StackIndex < StackSize; ++StackIndex)
	{
		if (CameraModeStack[StackIndex] == CameraMode)
		{
			ExistingStackIndex = StackIndex;
			ExistingStackContribution *= CameraMode->GetBlendWeight();
			break;
		}
		else
		{
			ExistingStackContribution *= (1.0f - CameraModeStack[StackIndex]->GetBlendWeight());
		}
	}

	if (ExistingStackIndex != INDEX_NONE)
	{
		CameraModeStack.RemoveAt(ExistingStackIndex);
		StackSize--;
	}
	else
	{
		ExistingStackContribution = 0.0f;
	}

	// 시작 가중치 결정
	const bool bShouldBlend = ((CameraMode->GetBlendTime() > 0.0f) && (StackSize > 0));
	const float BlendWeight = (bShouldBlend ? ExistingStackContribution : 1.0f);

	CameraMode->SetBlendWeight(BlendWeight);

	// 스택 최상위에 추가
	CameraModeStack.Insert(CameraMode, 0);

	// 스택 바닥은 항상 100% 가중치 유지
	CameraModeStack.Last()->SetBlendWeight(1.0f);

	// 스택에 새로 추가되는 경우 알림
	if (ExistingStackIndex == INDEX_NONE)
	{
		CameraMode->OnActivation();
	}
}

bool UZombieCameraModeStack::EvaluateStack(float DeltaTime, FZombieCameraModeView& OutCameraModeView)
{
	if (!bIsActive)
	{
		return false;
	}

	UpdateStack(DeltaTime);
	BlendStack(OutCameraModeView);

	return true;
}

UZombieCameraMode* UZombieCameraModeStack::GetCameraModeInstance(TSubclassOf<UZombieCameraMode> CameraModeClass)
{
	check(CameraModeClass);

	// 이미 생성된 인스턴스가 있는지 확인
	for (UZombieCameraMode* CameraMode : CameraModeInstances)
	{
		if ((CameraMode != nullptr) && (CameraMode->GetClass() == CameraModeClass))
		{
			return CameraMode;
		}
	}

	// 없으면 새로 생성
	UZombieCameraMode* NewCameraMode = NewObject<UZombieCameraMode>(GetOuter(), CameraModeClass, NAME_None, RF_NoFlags);
	check(NewCameraMode);

	CameraModeInstances.Add(NewCameraMode);

	return NewCameraMode;
}

void UZombieCameraModeStack::UpdateStack(float DeltaTime)
{
	const int32 StackSize = CameraModeStack.Num();
	if (StackSize <= 0)
	{
		return;
	}

	int32 RemoveCount = 0;
	int32 RemoveIndex = INDEX_NONE;

	for (int32 StackIndex = 0; StackIndex < StackSize; ++StackIndex)
	{
		UZombieCameraMode* CameraMode = CameraModeStack[StackIndex];
		check(CameraMode);

		CameraMode->UpdateCameraMode(DeltaTime);

		if (CameraMode->GetBlendWeight() >= 1.0f)
		{
			// 이 모드 아래는 더 이상 의미 없으므로 제거
			RemoveIndex = (StackIndex + 1);
			RemoveCount = (StackSize - RemoveIndex);
			break;
		}
	}

	if (RemoveCount > 0)
	{
		// 스택에서 제거됨을 알림
		for (int32 StackIndex = RemoveIndex; StackIndex < StackSize; ++StackIndex)
		{
			UZombieCameraMode* CameraMode = CameraModeStack[StackIndex];
			check(CameraMode);

			CameraMode->OnDeactivation();
		}

		CameraModeStack.RemoveAt(RemoveIndex, RemoveCount);
	}
}

void UZombieCameraModeStack::BlendStack(FZombieCameraModeView& OutCameraModeView) const
{
	const int32 StackSize = CameraModeStack.Num();
	if (StackSize <= 0)
	{
		return;
	}

	// 바닥에서 시작해 위로 블렌드
	const UZombieCameraMode* CameraMode = CameraModeStack[StackSize - 1];
	check(CameraMode);

	OutCameraModeView = CameraMode->GetCameraModeView();

	for (int32 StackIndex = (StackSize - 2); StackIndex >= 0; --StackIndex)
	{
		CameraMode = CameraModeStack[StackIndex];
		check(CameraMode);

		OutCameraModeView.Blend(CameraMode->GetCameraModeView(), CameraMode->GetBlendWeight());
	}
}

void UZombieCameraModeStack::DrawDebug(UCanvas* Canvas) const
{
	check(Canvas);

	FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;

	DisplayDebugManager.SetDrawColor(FColor::Green);
	DisplayDebugManager.DrawString(FString(TEXT("   --- Camera Modes (Begin) ---")));

	for (const UZombieCameraMode* CameraMode : CameraModeStack)
	{
		check(CameraMode);
		CameraMode->DrawDebug(Canvas);
	}

	DisplayDebugManager.SetDrawColor(FColor::Green);
	DisplayDebugManager.DrawString(FString::Printf(TEXT("   --- Camera Modes (End) ---")));
}

void UZombieCameraModeStack::GetBlendInfo(float& OutWeightOfTopLayer, FGameplayTag& OutTagOfTopLayer) const
{
	if (CameraModeStack.Num() == 0)
	{
		OutWeightOfTopLayer = 1.0f;
		OutTagOfTopLayer = FGameplayTag();
		return;
	}
	else
	{
		UZombieCameraMode* TopEntry = CameraModeStack.Last();
		check(TopEntry);
		OutWeightOfTopLayer = TopEntry->GetBlendWeight();
		OutTagOfTopLayer = TopEntry->GetCameraTypeTag();
	}
}
