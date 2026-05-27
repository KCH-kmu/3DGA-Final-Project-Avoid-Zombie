// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WaveManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeWaveManager() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AWaveManager();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AWaveManager_NoRegister();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieCharacter_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AWaveManager Function OnZombieDead ***************************************
struct Z_Construct_UFunction_AWaveManager_OnZombieDead_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** ZombieCharacter::Die()\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WaveManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ZombieCharacter::Die()\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnZombieDead constinit property declarations **************************
// ********** End Function OnZombieDead constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWaveManager_OnZombieDead_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWaveManager, nullptr, "OnZombieDead", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWaveManager_OnZombieDead_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWaveManager_OnZombieDead_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AWaveManager_OnZombieDead()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWaveManager_OnZombieDead_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWaveManager::execOnZombieDead)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnZombieDead();
	P_NATIVE_END;
}
// ********** End Class AWaveManager Function OnZombieDead *****************************************

// ********** Begin Class AWaveManager Function StopWave *******************************************
struct Z_Construct_UFunction_AWaveManager_StopWave_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xea\xb2\x8c\xec\x9e\x84 \xec\x98\xa4\xeb\xb2\x84 \xec\x8b\x9c \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xec\xa4\x91\xeb\x8b\xa8 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WaveManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb2\x8c\xec\x9e\x84 \xec\x98\xa4\xeb\xb2\x84 \xec\x8b\x9c \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xec\xa4\x91\xeb\x8b\xa8" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StopWave constinit property declarations ******************************
// ********** End Function StopWave constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWaveManager_StopWave_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWaveManager, nullptr, "StopWave", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWaveManager_StopWave_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWaveManager_StopWave_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AWaveManager_StopWave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWaveManager_StopWave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWaveManager::execStopWave)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopWave();
	P_NATIVE_END;
}
// ********** End Class AWaveManager Function StopWave *********************************************

// ********** Begin Class AWaveManager *************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AWaveManager;
UClass* AWaveManager::GetPrivateStaticClass()
{
	using TClass = AWaveManager;
	if (!Z_Registration_Info_UClass_AWaveManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("WaveManager"),
			Z_Registration_Info_UClass_AWaveManager.InnerSingleton,
			StaticRegisterNativesAWaveManager,
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
	return Z_Registration_Info_UClass_AWaveManager.InnerSingleton;
}
UClass* Z_Construct_UClass_AWaveManager_NoRegister()
{
	return AWaveManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AWaveManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xeb\xa7\xa4\xeb\x8b\x88\xec\xa0\x80\n *\n * - 20\xec\xb4\x88\xeb\xa7\x88\xeb\x8b\xa4 \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xec\xa6\x9d\xea\xb0\x80\n * - \xed\x8f\xac\xed\x83\x88 8\xea\xb0\x9c \xec\xa4\x91 \xeb\x9e\x9c\xeb\x8d\xa4 \xec\x84\xa0\xed\x83\x9d, \xed\x8f\xac\xed\x83\x88\xeb\x8b\xb9 1\xec\xb4\x88 \xeb\x82\xb4\xeb\xb6\x80 \xec\xbf\xa8\xeb\x8b\xa4\xec\x9a\xb4 (\xea\xb2\xb9\xec\xb9\xa8 \xeb\xb0\xa9\xec\xa7\x80)\n * - 1\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c 6\xeb\xa7\x88\xeb\xa6\xac, \xeb\xa7\xa4 \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c +1\xeb\xa7\x88\xeb\xa6\xac (\xec\xb5\x9c\xeb\x8c\x80 40\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c)\n * - \xeb\xa7\xa4 2\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c\xeb\xa7\x88\xeb\x8b\xa4 \xec\x9d\xb4\xeb\x8f\x99\xec\x86\x8d\xeb\x8f\x84 +0.2m/s (20cm/s)\n * - \xeb\xa7\xa4 5\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c\xeb\xa7\x88\xeb\x8b\xa4 \xec\xb2\xb4\xeb\xa0\xa5 +1\n * - \xed\x98\x84\xec\x9e\xac \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xec\xa2\x80\xeb\xb9\x84 \xec\xa0\x84\xeb\xa9\xb8 \xec\x8b\x9c \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xed\x81\xb4\xeb\xa6\xac\xec\x96\xb4\n */" },
#endif
		{ "IncludePath", "Avoid_Zombie/WaveManager.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/WaveManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xeb\xa7\xa4\xeb\x8b\x88\xec\xa0\x80\n\n- 20\xec\xb4\x88\xeb\xa7\x88\xeb\x8b\xa4 \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xec\xa6\x9d\xea\xb0\x80\n- \xed\x8f\xac\xed\x83\x88 8\xea\xb0\x9c \xec\xa4\x91 \xeb\x9e\x9c\xeb\x8d\xa4 \xec\x84\xa0\xed\x83\x9d, \xed\x8f\xac\xed\x83\x88\xeb\x8b\xb9 1\xec\xb4\x88 \xeb\x82\xb4\xeb\xb6\x80 \xec\xbf\xa8\xeb\x8b\xa4\xec\x9a\xb4 (\xea\xb2\xb9\xec\xb9\xa8 \xeb\xb0\xa9\xec\xa7\x80)\n- 1\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c 6\xeb\xa7\x88\xeb\xa6\xac, \xeb\xa7\xa4 \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c +1\xeb\xa7\x88\xeb\xa6\xac (\xec\xb5\x9c\xeb\x8c\x80 40\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c)\n- \xeb\xa7\xa4 2\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c\xeb\xa7\x88\xeb\x8b\xa4 \xec\x9d\xb4\xeb\x8f\x99\xec\x86\x8d\xeb\x8f\x84 +0.2m/s (20cm/s)\n- \xeb\xa7\xa4 5\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c\xeb\xa7\x88\xeb\x8b\xa4 \xec\xb2\xb4\xeb\xa0\xa5 +1\n- \xed\x98\x84\xec\x9e\xac \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xec\xa2\x80\xeb\xb9\x84 \xec\xa0\x84\xeb\xa9\xb8 \xec\x8b\x9c \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xed\x81\xb4\xeb\xa6\xac\xec\x96\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Portals_MetaData[] = {
		{ "Category", "Wave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xa0\x88\xeb\xb2\xa8\xec\x97\x90 \xeb\xb0\xb0\xec\xb9\x98\xeb\x90\x9c \xed\x8f\xac\xed\x83\x88 Actor 8\xea\xb0\x9c (\xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c \xec\xa7\x80\xec\xa0\x95) */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WaveManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xa0\x88\xeb\xb2\xa8\xec\x97\x90 \xeb\xb0\xb0\xec\xb9\x98\xeb\x90\x9c \xed\x8f\xac\xed\x83\x88 Actor 8\xea\xb0\x9c (\xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c \xec\xa7\x80\xec\xa0\x95)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZombieClass_MetaData[] = {
		{ "Category", "Wave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\xa2\x80\xeb\xb9\x84 \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4 (\xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c \xec\xa7\x80\xec\xa0\x95) */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WaveManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa2\x80\xeb\xb9\x84 \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4 (\xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c \xec\xa7\x80\xec\xa0\x95)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWave_MetaData[] = {
		{ "Category", "Wave" },
		{ "ModuleRelativePath", "Avoid_Zombie/WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AliveZombieCount_MetaData[] = {
		{ "Category", "Wave" },
		{ "ModuleRelativePath", "Avoid_Zombie/WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWaveActive_MetaData[] = {
		{ "Category", "Wave" },
		{ "ModuleRelativePath", "Avoid_Zombie/WaveManager.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AWaveManager constinit property declarations *****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Portals_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Portals;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ZombieClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentWave;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AliveZombieCount;
	static void NewProp_bWaveActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWaveActive;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AWaveManager constinit property declarations *******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnZombieDead"), .Pointer = &AWaveManager::execOnZombieDead },
		{ .NameUTF8 = UTF8TEXT("StopWave"), .Pointer = &AWaveManager::execStopWave },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AWaveManager_OnZombieDead, "OnZombieDead" }, // 473296398
		{ &Z_Construct_UFunction_AWaveManager_StopWave, "StopWave" }, // 2257197613
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWaveManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AWaveManager_Statics

// ********** Begin Class AWaveManager Property Definitions ****************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_Portals_Inner = { "Portals", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_Portals = { "Portals", nullptr, (EPropertyFlags)0x0114000000000805, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveManager, Portals), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Portals_MetaData), NewProp_Portals_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_ZombieClass = { "ZombieClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveManager, ZombieClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AZombieCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZombieClass_MetaData), NewProp_ZombieClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_CurrentWave = { "CurrentWave", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveManager, CurrentWave), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWave_MetaData), NewProp_CurrentWave_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_AliveZombieCount = { "AliveZombieCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveManager, AliveZombieCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AliveZombieCount_MetaData), NewProp_AliveZombieCount_MetaData) };
void Z_Construct_UClass_AWaveManager_Statics::NewProp_bWaveActive_SetBit(void* Obj)
{
	((AWaveManager*)Obj)->bWaveActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_bWaveActive = { "bWaveActive", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AWaveManager), &Z_Construct_UClass_AWaveManager_Statics::NewProp_bWaveActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWaveActive_MetaData), NewProp_bWaveActive_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWaveManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_Portals_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_Portals,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_ZombieClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_CurrentWave,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_AliveZombieCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_bWaveActive,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveManager_Statics::PropPointers) < 2048);
// ********** End Class AWaveManager Property Definitions ******************************************
UObject* (*const Z_Construct_UClass_AWaveManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWaveManager_Statics::ClassParams = {
	&AWaveManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AWaveManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AWaveManager_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AWaveManager_Statics::Class_MetaDataParams)
};
void AWaveManager::StaticRegisterNativesAWaveManager()
{
	UClass* Class = AWaveManager::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AWaveManager_Statics::Funcs));
}
UClass* Z_Construct_UClass_AWaveManager()
{
	if (!Z_Registration_Info_UClass_AWaveManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWaveManager.OuterSingleton, Z_Construct_UClass_AWaveManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWaveManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AWaveManager);
AWaveManager::~AWaveManager() {}
// ********** End Class AWaveManager ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWaveManager, AWaveManager::StaticClass, TEXT("AWaveManager"), &Z_Registration_Info_UClass_AWaveManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWaveManager), 706103269U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h__Script_Avoid_Zombie_CPP_2600427571{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
