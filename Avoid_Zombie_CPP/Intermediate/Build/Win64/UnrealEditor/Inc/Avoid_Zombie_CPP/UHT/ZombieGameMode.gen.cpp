// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZombieGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieGameMode() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AWaveManager_NoRegister();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieGameMode();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieGameMode_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZombieGameMode Function OnPlayerDead ************************************
struct Z_Construct_UFunction_AZombieGameMode_OnPlayerDead_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Game" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameMode.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnPlayerDead constinit property declarations **************************
// ********** End Function OnPlayerDead constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieGameMode_OnPlayerDead_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieGameMode, nullptr, "OnPlayerDead", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieGameMode_OnPlayerDead_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieGameMode_OnPlayerDead_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AZombieGameMode_OnPlayerDead()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieGameMode_OnPlayerDead_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieGameMode::execOnPlayerDead)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPlayerDead();
	P_NATIVE_END;
}
// ********** End Class AZombieGameMode Function OnPlayerDead **************************************

// ********** Begin Class AZombieGameMode **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZombieGameMode;
UClass* AZombieGameMode::GetPrivateStaticClass()
{
	using TClass = AZombieGameMode;
	if (!Z_Registration_Info_UClass_AZombieGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieGameMode"),
			Z_Registration_Info_UClass_AZombieGameMode.InnerSingleton,
			StaticRegisterNativesAZombieGameMode,
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
	return Z_Registration_Info_UClass_AZombieGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AZombieGameMode_NoRegister()
{
	return AZombieGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZombieGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Avoid Zombie \xea\xb2\x8c\xec\x9e\x84 \xeb\xaa\xa8\xeb\x93\x9c\n * - BeginPlay \xec\x8b\x9c WaveManager \xec\x8a\xa4\xed\x8f\xb0\n * - Tick\xec\x97\x90\xec\x84\x9c GameState \xec\x8b\x9c\xea\xb0\x84 \xea\xb0\xb1\xec\x8b\xa0\n * - \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x82\xac\xeb\xa7\x9d \xec\x8b\x9c \xea\xb2\x8c\xec\x9e\x84 \xec\x98\xa4\xeb\xb2\x84 \xec\xb2\x98\xeb\xa6\xac\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Avoid_Zombie/ZombieGameMode.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Avoid Zombie \xea\xb2\x8c\xec\x9e\x84 \xeb\xaa\xa8\xeb\x93\x9c\n- BeginPlay \xec\x8b\x9c WaveManager \xec\x8a\xa4\xed\x8f\xb0\n- Tick\xec\x97\x90\xec\x84\x9c GameState \xec\x8b\x9c\xea\xb0\x84 \xea\xb0\xb1\xec\x8b\xa0\n- \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x82\xac\xeb\xa7\x9d \xec\x8b\x9c \xea\xb2\x8c\xec\x9e\x84 \xec\x98\xa4\xeb\xb2\x84 \xec\xb2\x98\xeb\xa6\xac" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaveManager_MetaData[] = {
		{ "Category", "Wave" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaveManagerClass_MetaData[] = {
		{ "Category", "Wave" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameMode.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AZombieGameMode constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WaveManager;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WaveManagerClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AZombieGameMode constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnPlayerDead"), .Pointer = &AZombieGameMode::execOnPlayerDead },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AZombieGameMode_OnPlayerDead, "OnPlayerDead" }, // 1061749040
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombieGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZombieGameMode_Statics

// ********** Begin Class AZombieGameMode Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombieGameMode_Statics::NewProp_WaveManager = { "WaveManager", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieGameMode, WaveManager), Z_Construct_UClass_AWaveManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaveManager_MetaData), NewProp_WaveManager_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AZombieGameMode_Statics::NewProp_WaveManagerClass = { "WaveManagerClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieGameMode, WaveManagerClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AWaveManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaveManagerClass_MetaData), NewProp_WaveManagerClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZombieGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieGameMode_Statics::NewProp_WaveManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieGameMode_Statics::NewProp_WaveManagerClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieGameMode_Statics::PropPointers) < 2048);
// ********** End Class AZombieGameMode Property Definitions ***************************************
UObject* (*const Z_Construct_UClass_AZombieGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZombieGameMode_Statics::ClassParams = {
	&AZombieGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AZombieGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AZombieGameMode_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AZombieGameMode_Statics::Class_MetaDataParams)
};
void AZombieGameMode::StaticRegisterNativesAZombieGameMode()
{
	UClass* Class = AZombieGameMode::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AZombieGameMode_Statics::Funcs));
}
UClass* Z_Construct_UClass_AZombieGameMode()
{
	if (!Z_Registration_Info_UClass_AZombieGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZombieGameMode.OuterSingleton, Z_Construct_UClass_AZombieGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZombieGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZombieGameMode);
AZombieGameMode::~AZombieGameMode() {}
// ********** End Class AZombieGameMode ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZombieGameMode, AZombieGameMode::StaticClass, TEXT("AZombieGameMode"), &Z_Registration_Info_UClass_AZombieGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZombieGameMode), 2287754335U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h__Script_Avoid_Zombie_CPP_4175674910{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
