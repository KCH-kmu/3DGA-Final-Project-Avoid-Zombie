// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZombieGameState.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieGameState() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieGameState();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieGameState_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZombieGameState Function AddBonusScore **********************************
struct Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics
{
	struct ZombieGameState_eventAddBonusScore_Parms
	{
		int32 Bonus;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xb3\xb4\xeb\x84\x88\xec\x8a\xa4 \xec\xa0\x90\xec\x88\x98 \xec\xa7\x81\xec\xa0\x91 \xec\xb6\x94\xea\xb0\x80 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb3\xb4\xeb\x84\x88\xec\x8a\xa4 \xec\xa0\x90\xec\x88\x98 \xec\xa7\x81\xec\xa0\x91 \xec\xb6\x94\xea\xb0\x80" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddBonusScore constinit property declarations *************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Bonus;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddBonusScore constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddBonusScore Property Definitions ************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::NewProp_Bonus = { "Bonus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieGameState_eventAddBonusScore_Parms, Bonus), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::NewProp_Bonus,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::PropPointers) < 2048);
// ********** End Function AddBonusScore Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieGameState, nullptr, "AddBonusScore", 	Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::ZombieGameState_eventAddBonusScore_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::ZombieGameState_eventAddBonusScore_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombieGameState_AddBonusScore()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieGameState_AddBonusScore_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieGameState::execAddBonusScore)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Bonus);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddBonusScore(Z_Param_Bonus);
	P_NATIVE_END;
}
// ********** End Class AZombieGameState Function AddBonusScore ************************************

// ********** Begin Class AZombieGameState Function AddKillScore ***********************************
struct Z_Construct_UFunction_AZombieGameState_AddKillScore_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xed\x82\xac 1\xed\x9a\x8c \xec\xb6\x94\xea\xb0\x80 + \xed\x82\xac*10 \xec\xa0\x90\xec\x88\x98 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x82\xac 1\xed\x9a\x8c \xec\xb6\x94\xea\xb0\x80 + \xed\x82\xac*10 \xec\xa0\x90\xec\x88\x98" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddKillScore constinit property declarations **************************
// ********** End Function AddKillScore constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieGameState_AddKillScore_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieGameState, nullptr, "AddKillScore", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieGameState_AddKillScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieGameState_AddKillScore_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AZombieGameState_AddKillScore()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieGameState_AddKillScore_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieGameState::execAddKillScore)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddKillScore();
	P_NATIVE_END;
}
// ********** End Class AZombieGameState Function AddKillScore *************************************

// ********** Begin Class AZombieGameState Function AddWaveClearScore ******************************
struct Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics
{
	struct ZombieGameState_eventAddWaveClearScore_Parms
	{
		int32 WaveNumber;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xed\x81\xb4\xeb\xa6\xac\xec\x96\xb4 \xec\xa0\x90\xec\x88\x98 \xec\xb6\x94\xea\xb0\x80 (\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c * 100) */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xed\x81\xb4\xeb\xa6\xac\xec\x96\xb4 \xec\xa0\x90\xec\x88\x98 \xec\xb6\x94\xea\xb0\x80 (\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c * 100)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddWaveClearScore constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_WaveNumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddWaveClearScore constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddWaveClearScore Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::NewProp_WaveNumber = { "WaveNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieGameState_eventAddWaveClearScore_Parms, WaveNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::NewProp_WaveNumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::PropPointers) < 2048);
// ********** End Function AddWaveClearScore Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieGameState, nullptr, "AddWaveClearScore", 	Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::ZombieGameState_eventAddWaveClearScore_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::ZombieGameState_eventAddWaveClearScore_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombieGameState_AddWaveClearScore()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieGameState_AddWaveClearScore_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieGameState::execAddWaveClearScore)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_WaveNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddWaveClearScore(Z_Param_WaveNumber);
	P_NATIVE_END;
}
// ********** End Class AZombieGameState Function AddWaveClearScore ********************************

// ********** Begin Class AZombieGameState Function TriggerGameOver ********************************
struct Z_Construct_UFunction_AZombieGameState_TriggerGameOver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Game" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xea\xb2\x8c\xec\x9e\x84 \xec\x98\xa4\xeb\xb2\x84 \xec\xb2\x98\xeb\xa6\xac */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb2\x8c\xec\x9e\x84 \xec\x98\xa4\xeb\xb2\x84 \xec\xb2\x98\xeb\xa6\xac" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function TriggerGameOver constinit property declarations ***********************
// ********** End Function TriggerGameOver constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieGameState_TriggerGameOver_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieGameState, nullptr, "TriggerGameOver", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieGameState_TriggerGameOver_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieGameState_TriggerGameOver_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AZombieGameState_TriggerGameOver()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieGameState_TriggerGameOver_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieGameState::execTriggerGameOver)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TriggerGameOver();
	P_NATIVE_END;
}
// ********** End Class AZombieGameState Function TriggerGameOver **********************************

// ********** Begin Class AZombieGameState *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZombieGameState;
UClass* AZombieGameState::GetPrivateStaticClass()
{
	using TClass = AZombieGameState;
	if (!Z_Registration_Info_UClass_AZombieGameState.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieGameState"),
			Z_Registration_Info_UClass_AZombieGameState.InnerSingleton,
			StaticRegisterNativesAZombieGameState,
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
	return Z_Registration_Info_UClass_AZombieGameState.InnerSingleton;
}
UClass* Z_Construct_UClass_AZombieGameState_NoRegister()
{
	return AZombieGameState::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZombieGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xea\xb2\x8c\xec\x9e\x84 \xec\xa0\x84\xec\x97\xad \xec\x83\x81\xed\x83\x9c\n * \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xeb\xb2\x88\xed\x98\xb8, \xed\x82\xac \xec\x88\x98, \xec\xa0\x90\xec\x88\x98, \xea\xb2\xbd\xea\xb3\xbc \xec\x8b\x9c\xea\xb0\x84\xec\x9d\x84 \xeb\xb3\xb4\xea\xb4\x80\xed\x95\x9c\xeb\x8b\xa4.\n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Avoid_Zombie/ZombieGameState.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb2\x8c\xec\x9e\x84 \xec\xa0\x84\xec\x97\xad \xec\x83\x81\xed\x83\x9c\n\xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xeb\xb2\x88\xed\x98\xb8, \xed\x82\xac \xec\x88\x98, \xec\xa0\x90\xec\x88\x98, \xea\xb2\xbd\xea\xb3\xbc \xec\x8b\x9c\xea\xb0\x84\xec\x9d\x84 \xeb\xb3\xb4\xea\xb4\x80\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWave_MetaData[] = {
		{ "Category", "Wave" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x9b\xa8\xec\x9d\xb4\xeb\xb8\x8c \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalScore_MetaData[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\xa0\x90\xec\x88\x98 / \xed\x82\xac \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\xa0\x90\xec\x88\x98 / \xed\x82\xac \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalKills_MetaData[] = {
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ElapsedTime_MetaData[] = {
		{ "Category", "Time" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4 \xec\x8b\x9c\xea\xb0\x84 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4 \xec\x8b\x9c\xea\xb0\x84 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsGameOver_MetaData[] = {
		{ "Category", "Game" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xea\xb2\x8c\xec\x9e\x84 \xec\x98\xa4\xeb\xb2\x84 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xea\xb2\x8c\xec\x9e\x84 \xec\x98\xa4\xeb\xb2\x84 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AZombieGameState constinit property declarations *************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentWave;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalScore;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalKills;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ElapsedTime;
	static void NewProp_bIsGameOver_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsGameOver;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AZombieGameState constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddBonusScore"), .Pointer = &AZombieGameState::execAddBonusScore },
		{ .NameUTF8 = UTF8TEXT("AddKillScore"), .Pointer = &AZombieGameState::execAddKillScore },
		{ .NameUTF8 = UTF8TEXT("AddWaveClearScore"), .Pointer = &AZombieGameState::execAddWaveClearScore },
		{ .NameUTF8 = UTF8TEXT("TriggerGameOver"), .Pointer = &AZombieGameState::execTriggerGameOver },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AZombieGameState_AddBonusScore, "AddBonusScore" }, // 3279985926
		{ &Z_Construct_UFunction_AZombieGameState_AddKillScore, "AddKillScore" }, // 2750584581
		{ &Z_Construct_UFunction_AZombieGameState_AddWaveClearScore, "AddWaveClearScore" }, // 2707620055
		{ &Z_Construct_UFunction_AZombieGameState_TriggerGameOver, "TriggerGameOver" }, // 3734943131
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombieGameState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZombieGameState_Statics

// ********** Begin Class AZombieGameState Property Definitions ************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AZombieGameState_Statics::NewProp_CurrentWave = { "CurrentWave", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieGameState, CurrentWave), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWave_MetaData), NewProp_CurrentWave_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AZombieGameState_Statics::NewProp_TotalScore = { "TotalScore", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieGameState, TotalScore), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalScore_MetaData), NewProp_TotalScore_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AZombieGameState_Statics::NewProp_TotalKills = { "TotalKills", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieGameState, TotalKills), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalKills_MetaData), NewProp_TotalKills_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombieGameState_Statics::NewProp_ElapsedTime = { "ElapsedTime", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieGameState, ElapsedTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ElapsedTime_MetaData), NewProp_ElapsedTime_MetaData) };
void Z_Construct_UClass_AZombieGameState_Statics::NewProp_bIsGameOver_SetBit(void* Obj)
{
	((AZombieGameState*)Obj)->bIsGameOver = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZombieGameState_Statics::NewProp_bIsGameOver = { "bIsGameOver", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AZombieGameState), &Z_Construct_UClass_AZombieGameState_Statics::NewProp_bIsGameOver_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsGameOver_MetaData), NewProp_bIsGameOver_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZombieGameState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieGameState_Statics::NewProp_CurrentWave,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieGameState_Statics::NewProp_TotalScore,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieGameState_Statics::NewProp_TotalKills,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieGameState_Statics::NewProp_ElapsedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieGameState_Statics::NewProp_bIsGameOver,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieGameState_Statics::PropPointers) < 2048);
// ********** End Class AZombieGameState Property Definitions **************************************
UObject* (*const Z_Construct_UClass_AZombieGameState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameStateBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieGameState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZombieGameState_Statics::ClassParams = {
	&AZombieGameState::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AZombieGameState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AZombieGameState_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieGameState_Statics::Class_MetaDataParams), Z_Construct_UClass_AZombieGameState_Statics::Class_MetaDataParams)
};
void AZombieGameState::StaticRegisterNativesAZombieGameState()
{
	UClass* Class = AZombieGameState::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AZombieGameState_Statics::Funcs));
}
UClass* Z_Construct_UClass_AZombieGameState()
{
	if (!Z_Registration_Info_UClass_AZombieGameState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZombieGameState.OuterSingleton, Z_Construct_UClass_AZombieGameState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZombieGameState.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZombieGameState);
AZombieGameState::~AZombieGameState() {}
// ********** End Class AZombieGameState ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZombieGameState, AZombieGameState::StaticClass, TEXT("AZombieGameState"), &Z_Registration_Info_UClass_AZombieGameState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZombieGameState), 697829692U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h__Script_Avoid_Zombie_CPP_1323876976{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
