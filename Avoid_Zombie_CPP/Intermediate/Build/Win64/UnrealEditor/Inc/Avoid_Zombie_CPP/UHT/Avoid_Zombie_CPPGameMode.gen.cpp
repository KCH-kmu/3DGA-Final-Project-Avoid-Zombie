// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CPPGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAvoid_Zombie_CPPGameMode() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AAvoid_Zombie_CPPGameMode();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AAvoid_Zombie_CPPGameMode ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AAvoid_Zombie_CPPGameMode;
UClass* AAvoid_Zombie_CPPGameMode::GetPrivateStaticClass()
{
	using TClass = AAvoid_Zombie_CPPGameMode;
	if (!Z_Registration_Info_UClass_AAvoid_Zombie_CPPGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("Avoid_Zombie_CPPGameMode"),
			Z_Registration_Info_UClass_AAvoid_Zombie_CPPGameMode.InnerSingleton,
			StaticRegisterNativesAAvoid_Zombie_CPPGameMode,
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
	return Z_Registration_Info_UClass_AAvoid_Zombie_CPPGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_NoRegister()
{
	return AAvoid_Zombie_CPPGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a third person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Avoid_Zombie_CPPGameMode.h" },
		{ "ModuleRelativePath", "Avoid_Zombie_CPPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a third person game" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AAvoid_Zombie_CPPGameMode constinit property declarations ****************
// ********** End Class AAvoid_Zombie_CPPGameMode constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAvoid_Zombie_CPPGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_Statics
UObject* (*const Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_Statics::ClassParams = {
	&AAvoid_Zombie_CPPGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_Statics::Class_MetaDataParams)
};
void AAvoid_Zombie_CPPGameMode::StaticRegisterNativesAAvoid_Zombie_CPPGameMode()
{
}
UClass* Z_Construct_UClass_AAvoid_Zombie_CPPGameMode()
{
	if (!Z_Registration_Info_UClass_AAvoid_Zombie_CPPGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAvoid_Zombie_CPPGameMode.OuterSingleton, Z_Construct_UClass_AAvoid_Zombie_CPPGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAvoid_Zombie_CPPGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AAvoid_Zombie_CPPGameMode);
AAvoid_Zombie_CPPGameMode::~AAvoid_Zombie_CPPGameMode() {}
// ********** End Class AAvoid_Zombie_CPPGameMode **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_CPPGameMode_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAvoid_Zombie_CPPGameMode, AAvoid_Zombie_CPPGameMode::StaticClass, TEXT("AAvoid_Zombie_CPPGameMode"), &Z_Registration_Info_UClass_AAvoid_Zombie_CPPGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAvoid_Zombie_CPPGameMode), 1862859869U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_CPPGameMode_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_CPPGameMode_h__Script_Avoid_Zombie_CPP_1677341180{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_CPPGameMode_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_CPPGameMode_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
