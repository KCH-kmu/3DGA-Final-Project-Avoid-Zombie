// Copyright 2024, Avoid_Zombie_CPP. All Rights Reserved.
// Lyra(Epic Games) LyraCameraMode_ThirdPerson 이식

#include "ZombieCameraMode_ThirdPerson.h"
#include "Components/PrimitiveComponent.h"
#include "Curves/CurveVector.h"
#include "Engine/Canvas.h"
#include "GameFramework/CameraBlockingVolume.h"
#include "ZombieCameraAssistInterface.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/RotationMatrix.h"
#include "Animation/AnimTypes.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(ZombieCameraMode_ThirdPerson)

namespace ZombieCameraMode_ThirdPerson_Statics
{
	static const FName NAME_IgnoreCameraCollision = TEXT("IgnoreCameraCollision");
}

UZombieCameraMode_ThirdPerson::UZombieCameraMode_ThirdPerson()
{
	TargetOffsetCurve = nullptr;

	// 기본값: 기존 스프링암(거리 400) 느낌을 내는 런타임 커브
	// 커브 에셋(예: Lyra의 ThirdPersonOffsetCurve)을 마이그레이트해 BP 서브클래스에서
	// TargetOffsetCurve에 할당하면 bUseRuntimeFloatCurves를 꺼서 교체 가능
	bUseRuntimeFloatCurves = true;

	FRichCurve* CurveX = TargetOffsetX.GetRichCurve();
	CurveX->AddKey(-89.0f, -200.0f);  // 바로 아래를 볼 때는 가깝게
	CurveX->AddKey(0.0f, -400.0f);    // 수평일 때 기존 스프링암 길이와 동일
	CurveX->AddKey(89.0f, -200.0f);   // 바로 위를 볼 때도 가깝게

	// 오른쪽 어깨 너머 시점(+Y): 캐릭터가 화면 살짝 좌측에 보여 조준 대상 시야 확보
	TargetOffsetY.GetRichCurve()->AddKey(0.0f, 40.0f);
	TargetOffsetZ.GetRichCurve()->AddKey(0.0f, 0.0f);

	PenetrationAvoidanceFeelers.Add(FZombiePenetrationAvoidanceFeeler(FRotator(+00.0f, +00.0f, 0.0f), 1.00f, 1.00f, 14.f, 0));
	PenetrationAvoidanceFeelers.Add(FZombiePenetrationAvoidanceFeeler(FRotator(+00.0f, +16.0f, 0.0f), 0.75f, 0.75f, 00.f, 3));
	PenetrationAvoidanceFeelers.Add(FZombiePenetrationAvoidanceFeeler(FRotator(+00.0f, -16.0f, 0.0f), 0.75f, 0.75f, 00.f, 3));
	PenetrationAvoidanceFeelers.Add(FZombiePenetrationAvoidanceFeeler(FRotator(+00.0f, +32.0f, 0.0f), 0.50f, 0.50f, 00.f, 5));
	PenetrationAvoidanceFeelers.Add(FZombiePenetrationAvoidanceFeeler(FRotator(+00.0f, -32.0f, 0.0f), 0.50f, 0.50f, 00.f, 5));
	PenetrationAvoidanceFeelers.Add(FZombiePenetrationAvoidanceFeeler(FRotator(+20.0f, +00.0f, 0.0f), 1.00f, 1.00f, 00.f, 4));
	PenetrationAvoidanceFeelers.Add(FZombiePenetrationAvoidanceFeeler(FRotator(-20.0f, +00.0f, 0.0f), 0.50f, 0.50f, 00.f, 4));
}

void UZombieCameraMode_ThirdPerson::UpdateView(float DeltaTime)
{
	UpdateForTarget(DeltaTime);
	UpdateCrouchOffset(DeltaTime);
	UpdateMoveBendOffset(DeltaTime);

	FVector PivotLocation = GetPivotLocation() + CurrentCrouchOffset + FVector(0.f, 0.f, CurrentMoveBendZ);
	FRotator PivotRotation = GetPivotRotation();

	PivotRotation.Pitch = FMath::ClampAngle(PivotRotation.Pitch, ViewPitchMin, ViewPitchMax);

	View.Location = PivotLocation;
	View.Rotation = PivotRotation;
	View.ControlRotation = View.Rotation;
	View.FieldOfView = FieldOfView;

	// 피치 기반 3인칭 오프셋 적용
	if (!bUseRuntimeFloatCurves)
	{
		if (TargetOffsetCurve)
		{
			const FVector TargetOffset = TargetOffsetCurve->GetVectorValue(PivotRotation.Pitch);
			View.Location = PivotLocation + PivotRotation.RotateVector(TargetOffset);
		}
	}
	else
	{
		FVector TargetOffset(0.0f);

		TargetOffset.X = TargetOffsetX.GetRichCurveConst()->Eval(PivotRotation.Pitch);
		TargetOffset.Y = TargetOffsetY.GetRichCurveConst()->Eval(PivotRotation.Pitch);
		TargetOffset.Z = TargetOffsetZ.GetRichCurveConst()->Eval(PivotRotation.Pitch);

		View.Location = PivotLocation + PivotRotation.RotateVector(TargetOffset);
	}

	// 관통 방지를 위해 최종 카메라 위치 보정
	UpdatePreventPenetration(DeltaTime);
}

void UZombieCameraMode_ThirdPerson::UpdateForTarget(float DeltaTime)
{

	if (const ACharacter* TargetCharacter = Cast<ACharacter>(GetTargetActor()))
	{
		if (TargetCharacter->IsCrouched())
		{
			const ACharacter* TargetCharacterCDO = TargetCharacter->GetClass()->GetDefaultObject<ACharacter>();
			const float CrouchedHeightAdjustment = TargetCharacterCDO->CrouchedEyeHeight - TargetCharacterCDO->BaseEyeHeight;

			SetTargetCrouchOffset(FVector(0.f, 0.f, CrouchedHeightAdjustment));

			return;
		}
	}

	SetTargetCrouchOffset(FVector::ZeroVector);
}

void UZombieCameraMode_ThirdPerson::DrawDebug(UCanvas* Canvas) const
{
	Super::DrawDebug(Canvas);

#if ENABLE_DRAW_DEBUG
	FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;
	for (int i = 0; i < DebugActorsHitDuringCameraPenetration.Num(); i++)
	{
		DisplayDebugManager.DrawString(
			FString::Printf(TEXT("HitActorDuringPenetration[%d]: %s")
				, i
				, *DebugActorsHitDuringCameraPenetration[i]->GetName()));
	}

	LastDrawDebugTime = GetWorld()->GetTimeSeconds();
#endif
}

void UZombieCameraMode_ThirdPerson::UpdatePreventPenetration(float DeltaTime)
{
	if (!bPreventPenetration)
	{
		return;
	}

	AActor* TargetActor = GetTargetActor();

	APawn* TargetPawn = Cast<APawn>(TargetActor);
	AController* TargetController = TargetPawn ? TargetPawn->GetController() : nullptr;
	IZombieCameraAssistInterface* TargetControllerAssist = Cast<IZombieCameraAssistInterface>(TargetController);

	IZombieCameraAssistInterface* TargetActorAssist = Cast<IZombieCameraAssistInterface>(TargetActor);

	TOptional<AActor*> OptionalPPTarget = TargetActorAssist ? TargetActorAssist->GetCameraPreventPenetrationTarget() : TOptional<AActor*>();
	AActor* PPActor = OptionalPPTarget.IsSet() ? OptionalPPTarget.GetValue() : TargetActor;
	IZombieCameraAssistInterface* PPActorAssist = OptionalPPTarget.IsSet() ? Cast<IZombieCameraAssistInterface>(PPActor) : nullptr;

	const UPrimitiveComponent* PPActorRootComponent = Cast<UPrimitiveComponent>(PPActor->GetRootComponent());
	if (PPActorRootComponent)
	{
		// 조준선을 최대한 유지하기 위해 SafeLocation을 자동으로 선택
		// 캡슐에서 조준선에 가장 가까운 점을 고른다
		FVector ClosestPointOnLineToCapsuleCenter;
		FVector SafeLocation = PPActor->GetActorLocation();
		FMath::PointDistToLine(SafeLocation, View.Rotation.Vector(), View.Location, ClosestPointOnLineToCapsuleCenter);

		// Safe distance 높이를 조준선과 같게 하되 캡슐 내부로 제한
		float const PushInDistance = PenetrationAvoidanceFeelers[0].Extent + CollisionPushOutDistance;
		float const MaxHalfHeight = PPActor->GetSimpleCollisionHalfHeight() - PushInDistance;
		SafeLocation.Z = FMath::Clamp(ClosestPointOnLineToCapsuleCenter.Z, SafeLocation.Z - MaxHalfHeight, SafeLocation.Z + MaxHalfHeight);

		float DistanceSqr;
		PPActorRootComponent->GetSquaredDistanceToCollision(ClosestPointOnLineToCapsuleCenter, DistanceSqr, SafeLocation);
		// 라인 체크 시 초기 관통을 피하기 위해 캡슐 안쪽으로 밀어 넣는다
		if (PenetrationAvoidanceFeelers.Num() > 0)
		{
			SafeLocation += (SafeLocation - ClosestPointOnLineToCapsuleCenter).GetSafeNormal() * PushInDistance;
		}

		// 조준선에서 목표 카메라 위치까지
		bool const bSingleRayPenetrationCheck = !bDoPredictiveAvoidance;
		PreventCameraPenetration(*PPActor, SafeLocation, View.Location, DeltaTime, AimLineToDesiredPosBlockedPct, bSingleRayPenetrationCheck);

		IZombieCameraAssistInterface* AssistArray[] = { TargetControllerAssist, TargetActorAssist, PPActorAssist };

		if (AimLineToDesiredPosBlockedPct < ReportPenetrationPercent)
		{
			for (IZombieCameraAssistInterface* Assist : AssistArray)
			{
				if (Assist)
				{
					// 카메라가 너무 가까움을 알림
					Assist->OnCameraPenetratingTarget();
				}
			}
		}
	}
}

void UZombieCameraMode_ThirdPerson::PreventCameraPenetration(class AActor const& ViewTarget, FVector const& SafeLoc, FVector& CameraLoc, float const& DeltaTime, float& DistBlockedPct, bool bSingleRayOnly)
{
#if ENABLE_DRAW_DEBUG
	DebugActorsHitDuringCameraPenetration.Reset();
#endif

	float HardBlockedPct = DistBlockedPct;
	float SoftBlockedPct = DistBlockedPct;

	FVector BaseRay = CameraLoc - SafeLoc;
	FRotationMatrix BaseRayMatrix(BaseRay.Rotation());
	FVector BaseRayLocalUp, BaseRayLocalFwd, BaseRayLocalRight;

	BaseRayMatrix.GetScaledAxes(BaseRayLocalFwd, BaseRayLocalRight, BaseRayLocalUp);

	float DistBlockedPctThisFrame = 1.f;

	int32 const NumRaysToShoot = bSingleRayOnly ? FMath::Min(1, PenetrationAvoidanceFeelers.Num()) : PenetrationAvoidanceFeelers.Num();
	FCollisionQueryParams SphereParams(SCENE_QUERY_STAT(CameraPen), false, nullptr/*PlayerCamera*/);

	SphereParams.AddIgnoredActor(&ViewTarget);

	FCollisionShape SphereShape = FCollisionShape::MakeSphere(0.f);
	UWorld* World = GetWorld();

	for (int32 RayIdx = 0; RayIdx < NumRaysToShoot; ++RayIdx)
	{
		FZombiePenetrationAvoidanceFeeler& Feeler = PenetrationAvoidanceFeelers[RayIdx];
		if (Feeler.FramesUntilNextTrace <= 0)
		{
			// 레이 타겟 계산
			FVector RayTarget;
			{
				FVector RotatedRay = BaseRay.RotateAngleAxis(Feeler.AdjustmentRot.Yaw, BaseRayLocalUp);
				RotatedRay = RotatedRay.RotateAngleAxis(Feeler.AdjustmentRot.Pitch, BaseRayLocalRight);
				RayTarget = SafeLoc + RotatedRay;
			}

			// 카메라 타겟 폰을 안전하게 무시할 수 있도록 월드/폰 히트를 따로 캐스트
			SphereShape.Sphere.Radius = Feeler.Extent;
			ECollisionChannel TraceChannel = ECC_Camera;

			FHitResult Hit;
			const bool bHit = World->SweepSingleByChannel(Hit, SafeLoc, RayTarget, FQuat::Identity, TraceChannel, SphereShape, SphereParams);
#if ENABLE_DRAW_DEBUG
			if (World->TimeSince(LastDrawDebugTime) < 1.f)
			{
				DrawDebugSphere(World, SafeLoc, SphereShape.Sphere.Radius, 8, FColor::Red);
				DrawDebugSphere(World, bHit ? Hit.Location : RayTarget, SphereShape.Sphere.Radius, 8, FColor::Red);
				DrawDebugLine(World, SafeLoc, bHit ? Hit.Location : RayTarget, FColor::Red);
			}
#endif // ENABLE_DRAW_DEBUG

			Feeler.FramesUntilNextTrace = Feeler.TraceInterval;

			const AActor* HitActor = Hit.GetActor();

			if (bHit && HitActor)
			{
				bool bIgnoreHit = false;

				if (HitActor->ActorHasTag(ZombieCameraMode_ThirdPerson_Statics::NAME_IgnoreCameraCollision))
				{
					bIgnoreHit = true;
					SphereParams.AddIgnoredActor(HitActor);
				}

				// 뷰 타겟 앞쪽에서 발생한 CameraBlockingVolume 히트는 무시
				if (!bIgnoreHit && HitActor->IsA<ACameraBlockingVolume>())
				{
					const FVector ViewTargetForwardXY = ViewTarget.GetActorForwardVector().GetSafeNormal2D();
					const FVector ViewTargetLocation = ViewTarget.GetActorLocation();
					const FVector HitOffset = Hit.Location - ViewTargetLocation;
					const FVector HitDirectionXY = HitOffset.GetSafeNormal2D();
					const float DotHitDirection = FVector::DotProduct(ViewTargetForwardXY, HitDirectionXY);
					if (DotHitDirection > 0.0f)
					{
						bIgnoreHit = true;
						// 남은 스윕에서도 이 볼륨 무시
						SphereParams.AddIgnoredActor(HitActor);
					}
					else
					{
#if ENABLE_DRAW_DEBUG
						DebugActorsHitDuringCameraPenetration.AddUnique(TObjectPtr<const AActor>(HitActor));
#endif
					}
				}

				if (!bIgnoreHit)
				{
					float const Weight = Cast<APawn>(Hit.GetActor()) ? Feeler.PawnWeight : Feeler.WorldWeight;
					float NewBlockPct = Hit.Time;
					NewBlockPct += (1.f - NewBlockPct) * (1.f - Weight);

					// 푸시아웃 거리를 고려해 블록 비율 재계산
					NewBlockPct = ((Hit.Location - SafeLoc).Size() - CollisionPushOutDistance) / (RayTarget - SafeLoc).Size();
					DistBlockedPctThisFrame = FMath::Min(NewBlockPct, DistBlockedPctThisFrame);

					// 이 필러가 히트했으므로 다음 프레임에도 트레이스
					Feeler.FramesUntilNextTrace = 0;

#if ENABLE_DRAW_DEBUG
					DebugActorsHitDuringCameraPenetration.AddUnique(TObjectPtr<const AActor>(HitActor));
#endif
				}
			}

			if (RayIdx == 0)
			{
				// 0번은 중앙/메인 레이이므로 보간 없이 스냅
				HardBlockedPct = DistBlockedPctThisFrame;
			}
			else
			{
				SoftBlockedPct = DistBlockedPctThisFrame;
			}
		}
		else
		{
			--Feeler.FramesUntilNextTrace;
		}
	}

	if (bResetInterpolation)
	{
		DistBlockedPct = DistBlockedPctThisFrame;
	}
	else if (DistBlockedPct < DistBlockedPctThisFrame)
	{
		// 부드럽게 보간하며 빠져나감
		if (PenetrationBlendOutTime > DeltaTime)
		{
			DistBlockedPct = DistBlockedPct + DeltaTime / PenetrationBlendOutTime * (DistBlockedPctThisFrame - DistBlockedPct);
		}
		else
		{
			DistBlockedPct = DistBlockedPctThisFrame;
		}
	}
	else
	{
		if (DistBlockedPct > HardBlockedPct)
		{
			DistBlockedPct = HardBlockedPct;
		}
		else if (DistBlockedPct > SoftBlockedPct)
		{
			// 부드럽게 보간하며 들어감
			if (PenetrationBlendInTime > DeltaTime)
			{
				DistBlockedPct = DistBlockedPct - DeltaTime / PenetrationBlendInTime * (DistBlockedPct - SoftBlockedPct);
			}
			else
			{
				DistBlockedPct = SoftBlockedPct;
			}
		}
	}

	DistBlockedPct = FMath::Clamp<float>(DistBlockedPct, 0.f, 1.f);
	if (DistBlockedPct < (1.f - ZERO_ANIMWEIGHT_THRESH))
	{
		CameraLoc = SafeLoc + (CameraLoc - SafeLoc) * DistBlockedPct;
	}
}

void UZombieCameraMode_ThirdPerson::UpdateMoveBendOffset(float DeltaTime)
{
	// 이동 속도에 비례해 카메라 피벗을 부드럽게 내려, 무장 이동 시 허리 숙임을 따라간다.
	// (높이만 조정 — 피치를 바꾸면 카메라 정면=조준 방향이라 크로스헤어가 틀어짐)
	float TargetZ = 0.f;
	if (const ACharacter* TargetCharacter = Cast<ACharacter>(GetTargetActor()))
	{
		const UCharacterMovementComponent* Move = TargetCharacter->GetCharacterMovement();
		const bool bGrounded = Move ? !Move->IsFalling() : true;
		if (bGrounded && MoveBendReferenceSpeed > 0.f)
		{
			const float Speed2D = TargetCharacter->GetVelocity().Size2D();
			const float Alpha   = FMath::Clamp(Speed2D / MoveBendReferenceSpeed, 0.f, 1.f);
			TargetZ = -MoveBendOffsetZ * Alpha; // 아래로
		}
	}
	CurrentMoveBendZ = FMath::FInterpTo(CurrentMoveBendZ, TargetZ, DeltaTime, MoveBendBlendSpeed);
}

void UZombieCameraMode_ThirdPerson::SetTargetCrouchOffset(FVector NewTargetOffset)
{
	CrouchOffsetBlendPct = 0.0f;
	InitialCrouchOffset = CurrentCrouchOffset;
	TargetCrouchOffset = NewTargetOffset;
}


void UZombieCameraMode_ThirdPerson::UpdateCrouchOffset(float DeltaTime)
{
	if (CrouchOffsetBlendPct < 1.0f)
	{
		CrouchOffsetBlendPct = FMath::Min(CrouchOffsetBlendPct + DeltaTime * CrouchOffsetBlendMultiplier, 1.0f);
		CurrentCrouchOffset = FMath::InterpEaseInOut(InitialCrouchOffset, TargetCrouchOffset, CrouchOffsetBlendPct, 1.0f);
	}
	else
	{
		CurrentCrouchOffset = TargetCrouchOffset;
		CrouchOffsetBlendPct = 1.0f;
	}
}


//////////////////////////////////////////////////////////////////////////
// UZombieCameraMode_Death
//////////////////////////////////////////////////////////////////////////
UZombieCameraMode_Death::UZombieCameraMode_Death()
{
	// 게임오버 UI 뒤에서 천천히 멀어지는 연출
	BlendTime = 1.5f;
	BlendFunction = EZombieCameraModeBlendFunction::EaseInOut;

	// 더 멀고 약간 높은 시점
	FRichCurve* CurveX = TargetOffsetX.GetRichCurve();
	CurveX->Reset();
	CurveX->AddKey(-89.0f, -300.0f);
	CurveX->AddKey(0.0f, -600.0f);
	CurveX->AddKey(89.0f, -300.0f);

	// 사망 연출은 캐릭터를 화면 중앙에 두도록 어깨 오프셋 제거
	FRichCurve* CurveY = TargetOffsetY.GetRichCurve();
	CurveY->Reset();
	CurveY->AddKey(0.0f, 0.0f);

	FRichCurve* CurveZ = TargetOffsetZ.GetRichCurve();
	CurveZ->Reset();
	CurveZ->AddKey(0.0f, 100.0f);

	// 시체/좀비 무리에 카메라가 끼이지 않도록 관통 방지는 유지하되 예측 회피는 끔
	bDoPredictiveAvoidance = false;
}
