// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZombieAIController.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieAIController() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieAIController();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieAIController_NoRegister();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZombieAIController ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZombieAIController;
UClass* AZombieAIController::GetPrivateStaticClass()
{
	using TClass = AZombieAIController;
	if (!Z_Registration_Info_UClass_AZombieAIController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieAIController"),
			Z_Registration_Info_UClass_AZombieAIController.InnerSingleton,
			StaticRegisterNativesAZombieAIController,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AZombieAIController.InnerSingleton;
}
UClass* Z_Construct_UClass_AZombieAIController_NoRegister()
{
	return AZombieAIController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZombieAIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xec\xa2\x80\xeb\xb9\x84 AI \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4\xeb\x9f\xac\n * 0.2\xec\xb4\x88\xeb\xa7\x88\xeb\x8b\xa4 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x9c\x84\xec\xb9\x98\xeb\xa5\xbc \xea\xb0\xb1\xec\x8b\xa0\xed\x95\x98\xeb\xa9\xb0 NavMesh \xec\xb6\x94\xec\xa0\x81.\n * \xea\xb3\xb5\xea\xb2\xa9 \xeb\xb2\x94\xec\x9c\x84 \xec\xa7\x84\xec\x9e\x85 \xec\x8b\x9c \xec\x9d\xb4\xeb\x8f\x99 \xec\xa4\x91\xec\xa7\x80 \xe2\x86\x92 ZombieCharacter.StartAttack() \xed\x98\xb8\xec\xb6\x9c.\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Avoid_Zombie/ZombieAIController.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieAIController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa2\x80\xeb\xb9\x84 AI \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4\xeb\x9f\xac\n0.2\xec\xb4\x88\xeb\xa7\x88\xeb\x8b\xa4 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x9c\x84\xec\xb9\x98\xeb\xa5\xbc \xea\xb0\xb1\xec\x8b\xa0\xed\x95\x98\xeb\xa9\xb0 NavMesh \xec\xb6\x94\xec\xa0\x81.\n\xea\xb3\xb5\xea\xb2\xa9 \xeb\xb2\x94\xec\x9c\x84 \xec\xa7\x84\xec\x9e\x85 \xec\x8b\x9c \xec\x9d\xb4\xeb\x8f\x99 \xec\xa4\x91\xec\xa7\x80 \xe2\x86\x92 ZombieCharacter.StartAttack() \xed\x98\xb8\xec\xb6\x9c." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChaseInterval_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieAIController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AZombieAIController constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChaseInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AZombieAIController constinit property declarations ************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombieAIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZombieAIController_Statics

// ********** Begin Class AZombieAIController Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombieAIController_Statics::NewProp_ChaseInterval = { "ChaseInterval", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieAIController, ChaseInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChaseInterval_MetaData), NewProp_ChaseInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombieAIController_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieAIController, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRange_MetaData), NewProp_AttackRange_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZombieAIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieAIController_Statics::NewProp_ChaseInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieAIController_Statics::NewProp_AttackRange,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieAIController_Statics::PropPointers) < 2048);
// ********** End Class AZombieAIController Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_AZombieAIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieAIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZombieAIController_Statics::ClassParams = {
	&AZombieAIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AZombieAIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AZombieAIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_AZombieAIController_Statics::Class_MetaDataParams)
};
void AZombieAIController::StaticRegisterNativesAZombieAIController()
{
}
UClass* Z_Construct_UClass_AZombieAIController()
{
	if (!Z_Registration_Info_UClass_AZombieAIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZombieAIController.OuterSingleton, Z_Construct_UClass_AZombieAIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZombieAIController.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZombieAIController);
AZombieAIController::~AZombieAIController() {}
// ********** End Class AZombieAIController ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAIController_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZombieAIController, AZombieAIController::StaticClass, TEXT("AZombieAIController"), &Z_Registration_Info_UClass_AZombieAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZombieAIController), 2432506369U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAIController_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAIController_h__Script_Avoid_Zombie_CPP_3538892195{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAIController_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAIController_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
