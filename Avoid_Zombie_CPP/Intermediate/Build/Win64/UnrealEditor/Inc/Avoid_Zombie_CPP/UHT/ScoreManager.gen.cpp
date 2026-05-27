// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ScoreManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeScoreManager() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UScoreManager();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UScoreManager_NoRegister();
AVOID_ZOMBIE_CPP_API UScriptStruct* Z_Construct_UScriptStruct_FGameOverData();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FGameOverData *****************************************************
struct Z_Construct_UScriptStruct_FGameOverData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGameOverData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGameOverData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xea\xb2\x8c\xec\x9e\x84\xec\x98\xa4\xeb\xb2\x84 \xed\x99\x94\xeb\xa9\xb4 \xed\x91\x9c\xec\x8b\x9c \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb2\x8c\xec\x9e\x84\xec\x98\xa4\xeb\xb2\x84 \xed\x99\x94\xeb\xa9\xb4 \xed\x91\x9c\xec\x8b\x9c \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurvivedTime_MetaData[] = {
		{ "Category", "GameOverData" },
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReachedWave_MetaData[] = {
		{ "Category", "GameOverData" },
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalKills_MetaData[] = {
		{ "Category", "GameOverData" },
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalScore_MetaData[] = {
		{ "Category", "GameOverData" },
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGameOverData constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SurvivedTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReachedWave;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalKills;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FinalScore;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGameOverData constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameOverData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGameOverData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGameOverData;
class UScriptStruct* FGameOverData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGameOverData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGameOverData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameOverData, (UObject*)Z_Construct_UPackage__Script_Avoid_Zombie_CPP(), TEXT("GameOverData"));
	}
	return Z_Registration_Info_UScriptStruct_FGameOverData.OuterSingleton;
	}

// ********** Begin ScriptStruct FGameOverData Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FGameOverData_Statics::NewProp_SurvivedTime = { "SurvivedTime", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameOverData, SurvivedTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurvivedTime_MetaData), NewProp_SurvivedTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGameOverData_Statics::NewProp_ReachedWave = { "ReachedWave", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameOverData, ReachedWave), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReachedWave_MetaData), NewProp_ReachedWave_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGameOverData_Statics::NewProp_TotalKills = { "TotalKills", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameOverData, TotalKills), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalKills_MetaData), NewProp_TotalKills_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGameOverData_Statics::NewProp_FinalScore = { "FinalScore", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameOverData, FinalScore), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalScore_MetaData), NewProp_FinalScore_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameOverData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameOverData_Statics::NewProp_SurvivedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameOverData_Statics::NewProp_ReachedWave,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameOverData_Statics::NewProp_TotalKills,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameOverData_Statics::NewProp_FinalScore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameOverData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGameOverData Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameOverData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
	nullptr,
	&NewStructOps,
	"GameOverData",
	Z_Construct_UScriptStruct_FGameOverData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameOverData_Statics::PropPointers),
	sizeof(FGameOverData),
	alignof(FGameOverData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameOverData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGameOverData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGameOverData()
{
	if (!Z_Registration_Info_UScriptStruct_FGameOverData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGameOverData.InnerSingleton, Z_Construct_UScriptStruct_FGameOverData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGameOverData.InnerSingleton);
}
// ********** End ScriptStruct FGameOverData *******************************************************

// ********** Begin Class UScoreManager Function BuildGameOverData *********************************
struct Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics
{
	struct ScoreManager_eventBuildGameOverData_Parms
	{
		FGameOverData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xea\xb2\x8c\xec\x9e\x84\xec\x98\xa4\xeb\xb2\x84 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xeb\xb0\x98\xed\x99\x98 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb2\x8c\xec\x9e\x84\xec\x98\xa4\xeb\xb2\x84 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xeb\xb0\x98\xed\x99\x98" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BuildGameOverData constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BuildGameOverData constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BuildGameOverData Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreManager_eventBuildGameOverData_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameOverData, METADATA_PARAMS(0, nullptr) }; // 1956661275
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::PropPointers) < 2048);
// ********** End Function BuildGameOverData Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UScoreManager, nullptr, "BuildGameOverData", 	Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::ScoreManager_eventBuildGameOverData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::ScoreManager_eventBuildGameOverData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UScoreManager_BuildGameOverData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreManager_BuildGameOverData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UScoreManager::execBuildGameOverData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameOverData*)Z_Param__Result=P_THIS->BuildGameOverData();
	P_NATIVE_END;
}
// ********** End Class UScoreManager Function BuildGameOverData ***********************************

// ********** Begin Class UScoreManager Function OnKill ********************************************
struct Z_Construct_UFunction_UScoreManager_OnKill_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xed\x82\xac \xeb\xb0\x9c\xec\x83\x9d \xec\x8b\x9c \xed\x98\xb8\xec\xb6\x9c \xe2\x80\x94 \xeb\xa7\x88\xec\x9d\xbc\xec\x8a\xa4\xed\x86\xa4 \xec\xb2\xb4\xed\x81\xac \xed\x8f\xac\xed\x95\xa8 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x82\xac \xeb\xb0\x9c\xec\x83\x9d \xec\x8b\x9c \xed\x98\xb8\xec\xb6\x9c \xe2\x80\x94 \xeb\xa7\x88\xec\x9d\xbc\xec\x8a\xa4\xed\x86\xa4 \xec\xb2\xb4\xed\x81\xac \xed\x8f\xac\xed\x95\xa8" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnKill constinit property declarations ********************************
// ********** End Function OnKill constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreManager_OnKill_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UScoreManager, nullptr, "OnKill", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreManager_OnKill_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreManager_OnKill_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UScoreManager_OnKill()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreManager_OnKill_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UScoreManager::execOnKill)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnKill();
	P_NATIVE_END;
}
// ********** End Class UScoreManager Function OnKill **********************************************

// ********** Begin Class UScoreManager Function OnWaveClear ***************************************
struct Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics
{
	struct ScoreManager_eventOnWaveClear_Parms
	{
		int32 WaveNumber;
		bool bFullHp;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xed\x81\xb4\xeb\xa6\xac\xec\x96\xb4 \xec\x8b\x9c \xed\x98\xb8\xec\xb6\x9c */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xed\x81\xb4\xeb\xa6\xac\xec\x96\xb4 \xec\x8b\x9c \xed\x98\xb8\xec\xb6\x9c" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWaveClear constinit property declarations ***************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_WaveNumber;
	static void NewProp_bFullHp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFullHp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWaveClear constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWaveClear Property Definitions **************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::NewProp_WaveNumber = { "WaveNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreManager_eventOnWaveClear_Parms, WaveNumber), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::NewProp_bFullHp_SetBit(void* Obj)
{
	((ScoreManager_eventOnWaveClear_Parms*)Obj)->bFullHp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::NewProp_bFullHp = { "bFullHp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ScoreManager_eventOnWaveClear_Parms), &Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::NewProp_bFullHp_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::NewProp_WaveNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::NewProp_bFullHp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::PropPointers) < 2048);
// ********** End Function OnWaveClear Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UScoreManager, nullptr, "OnWaveClear", 	Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::ScoreManager_eventOnWaveClear_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::ScoreManager_eventOnWaveClear_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UScoreManager_OnWaveClear()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreManager_OnWaveClear_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UScoreManager::execOnWaveClear)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_WaveNumber);
	P_GET_UBOOL(Z_Param_bFullHp);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWaveClear(Z_Param_WaveNumber,Z_Param_bFullHp);
	P_NATIVE_END;
}
// ********** End Class UScoreManager Function OnWaveClear *****************************************

// ********** Begin Class UScoreManager ************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UScoreManager;
UClass* UScoreManager::GetPrivateStaticClass()
{
	using TClass = UScoreManager;
	if (!Z_Registration_Info_UClass_UScoreManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ScoreManager"),
			Z_Registration_Info_UClass_UScoreManager.InnerSingleton,
			StaticRegisterNativesUScoreManager,
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
	return Z_Registration_Info_UClass_UScoreManager.InnerSingleton;
}
UClass* Z_Construct_UClass_UScoreManager_NoRegister()
{
	return UScoreManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UScoreManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xec\x8a\xa4\xec\xbd\x94\xec\x96\xb4 \xeb\xa7\xa4\xeb\x8b\x88\xec\xa0\x80 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\n *\n * - \xeb\xa7\x88\xec\x9d\xbc\xec\x8a\xa4\xed\x86\xa4 \xed\x82\xac \xec\x88\x98\xeb\xa7\x88\xeb\x8b\xa4 \xeb\xb3\xb4\xeb\x84\x88\xec\x8a\xa4 \xec\xa0\x90\xec\x88\x98\n * - \xea\xb2\x8c\xec\x9e\x84\xec\x98\xa4\xeb\xb2\x84 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 (\xeb\xb2\x84\xed\x8b\xb4 \xec\x8b\x9c\xea\xb0\x84 / \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c / \xed\x82\xac / \xec\xa0\x90\xec\x88\x98) \xec\x88\x98\xec\xa7\x91\n */" },
#endif
		{ "IncludePath", "Avoid_Zombie/ScoreManager.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x8a\xa4\xec\xbd\x94\xec\x96\xb4 \xeb\xa7\xa4\xeb\x8b\x88\xec\xa0\x80 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\n\n- \xeb\xa7\x88\xec\x9d\xbc\xec\x8a\xa4\xed\x86\xa4 \xed\x82\xac \xec\x88\x98\xeb\xa7\x88\xeb\x8b\xa4 \xeb\xb3\xb4\xeb\x84\x88\xec\x8a\xa4 \xec\xa0\x90\xec\x88\x98\n- \xea\xb2\x8c\xec\x9e\x84\xec\x98\xa4\xeb\xb2\x84 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 (\xeb\xb2\x84\xed\x8b\xb4 \xec\x8b\x9c\xea\xb0\x84 / \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c / \xed\x82\xac / \xec\xa0\x90\xec\x88\x98) \xec\x88\x98\xec\xa7\x91" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MilestoneThresholds_MetaData[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xa7\x88\xec\x9d\xbc\xec\x8a\xa4\xed\x86\xa4 \xed\x82\xac \xea\xb8\xb0\xec\xa4\x80 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xa7\x88\xec\x9d\xbc\xec\x8a\xa4\xed\x86\xa4 \xed\x82\xac \xea\xb8\xb0\xec\xa4\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MilestoneBonuses_MetaData[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xa7\x88\xec\x9d\xbc\xec\x8a\xa4\xed\x86\xa4 \xeb\xb3\xb4\xeb\x84\x88\xec\x8a\xa4 \xec\xa0\x90\xec\x88\x98 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ScoreManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xa7\x88\xec\x9d\xbc\xec\x8a\xa4\xed\x86\xa4 \xeb\xb3\xb4\xeb\x84\x88\xec\x8a\xa4 \xec\xa0\x90\xec\x88\x98" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UScoreManager constinit property declarations ****************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_MilestoneThresholds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MilestoneThresholds;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MilestoneBonuses_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MilestoneBonuses;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UScoreManager constinit property declarations ******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BuildGameOverData"), .Pointer = &UScoreManager::execBuildGameOverData },
		{ .NameUTF8 = UTF8TEXT("OnKill"), .Pointer = &UScoreManager::execOnKill },
		{ .NameUTF8 = UTF8TEXT("OnWaveClear"), .Pointer = &UScoreManager::execOnWaveClear },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UScoreManager_BuildGameOverData, "BuildGameOverData" }, // 3749466317
		{ &Z_Construct_UFunction_UScoreManager_OnKill, "OnKill" }, // 2148191626
		{ &Z_Construct_UFunction_UScoreManager_OnWaveClear, "OnWaveClear" }, // 1440635904
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UScoreManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UScoreManager_Statics

// ********** Begin Class UScoreManager Property Definitions ***************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreManager_Statics::NewProp_MilestoneThresholds_Inner = { "MilestoneThresholds", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UScoreManager_Statics::NewProp_MilestoneThresholds = { "MilestoneThresholds", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreManager, MilestoneThresholds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MilestoneThresholds_MetaData), NewProp_MilestoneThresholds_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreManager_Statics::NewProp_MilestoneBonuses_Inner = { "MilestoneBonuses", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UScoreManager_Statics::NewProp_MilestoneBonuses = { "MilestoneBonuses", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreManager, MilestoneBonuses), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MilestoneBonuses_MetaData), NewProp_MilestoneBonuses_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UScoreManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreManager_Statics::NewProp_MilestoneThresholds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreManager_Statics::NewProp_MilestoneThresholds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreManager_Statics::NewProp_MilestoneBonuses_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreManager_Statics::NewProp_MilestoneBonuses,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreManager_Statics::PropPointers) < 2048);
// ********** End Class UScoreManager Property Definitions *****************************************
UObject* (*const Z_Construct_UClass_UScoreManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UScoreManager_Statics::ClassParams = {
	&UScoreManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UScoreManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UScoreManager_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UScoreManager_Statics::Class_MetaDataParams)
};
void UScoreManager::StaticRegisterNativesUScoreManager()
{
	UClass* Class = UScoreManager::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UScoreManager_Statics::Funcs));
}
UClass* Z_Construct_UClass_UScoreManager()
{
	if (!Z_Registration_Info_UClass_UScoreManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UScoreManager.OuterSingleton, Z_Construct_UClass_UScoreManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UScoreManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UScoreManager);
UScoreManager::~UScoreManager() {}
// ********** End Class UScoreManager **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGameOverData::StaticStruct, Z_Construct_UScriptStruct_FGameOverData_Statics::NewStructOps, TEXT("GameOverData"),&Z_Registration_Info_UScriptStruct_FGameOverData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGameOverData), 1956661275U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UScoreManager, UScoreManager::StaticClass, TEXT("UScoreManager"), &Z_Registration_Info_UClass_UScoreManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UScoreManager), 1212068835U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h__Script_Avoid_Zombie_CPP_3445044124{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h__Script_Avoid_Zombie_CPP_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h__Script_Avoid_Zombie_CPP_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
