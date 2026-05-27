// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZombieCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieCharacter() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieCharacter();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieCharacter_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZombieCharacter Function ApplyStun **************************************
struct Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics
{
	struct ZombieCharacter_eventApplyStun_Parms
	{
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Zombie" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyStun constinit property declarations *****************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyStun constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyStun Property Definitions ****************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieCharacter_eventApplyStun_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::PropPointers) < 2048);
// ********** End Function ApplyStun Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieCharacter, nullptr, "ApplyStun", 	Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::ZombieCharacter_eventApplyStun_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::ZombieCharacter_eventApplyStun_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombieCharacter_ApplyStun()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieCharacter_ApplyStun_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieCharacter::execApplyStun)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Duration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyStun(Z_Param_Duration);
	P_NATIVE_END;
}
// ********** End Class AZombieCharacter Function ApplyStun ****************************************

// ********** Begin Class AZombieCharacter Function IsDead *****************************************
struct Z_Construct_UFunction_AZombieCharacter_IsDead_Statics
{
	struct ZombieCharacter_eventIsDead_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Zombie" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDead constinit property declarations ********************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDead constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDead Property Definitions *******************************************
void Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ZombieCharacter_eventIsDead_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ZombieCharacter_eventIsDead_Parms), &Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::PropPointers) < 2048);
// ********** End Function IsDead Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieCharacter, nullptr, "IsDead", 	Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::ZombieCharacter_eventIsDead_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::ZombieCharacter_eventIsDead_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombieCharacter_IsDead()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieCharacter_IsDead_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieCharacter::execIsDead)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDead();
	P_NATIVE_END;
}
// ********** End Class AZombieCharacter Function IsDead *******************************************

// ********** Begin Class AZombieCharacter Function IsPlayerInAttackRange **************************
struct Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics
{
	struct ZombieCharacter_eventIsPlayerInAttackRange_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Zombie" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPlayerInAttackRange constinit property declarations *****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPlayerInAttackRange constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPlayerInAttackRange Property Definitions ****************************
void Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ZombieCharacter_eventIsPlayerInAttackRange_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ZombieCharacter_eventIsPlayerInAttackRange_Parms), &Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::PropPointers) < 2048);
// ********** End Function IsPlayerInAttackRange Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieCharacter, nullptr, "IsPlayerInAttackRange", 	Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::ZombieCharacter_eventIsPlayerInAttackRange_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::ZombieCharacter_eventIsPlayerInAttackRange_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieCharacter::execIsPlayerInAttackRange)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayerInAttackRange();
	P_NATIVE_END;
}
// ********** End Class AZombieCharacter Function IsPlayerInAttackRange ****************************

// ********** Begin Class AZombieCharacter Function OnAttackEnd ************************************
struct Z_Construct_UFunction_AZombieCharacter_OnAttackEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Zombie" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc \xec\xa2\x85\xeb\xa3\x8c \xed\x9b\x84 \xed\x98\xb8\xec\xb6\x9c */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc \xec\xa2\x85\xeb\xa3\x8c \xed\x9b\x84 \xed\x98\xb8\xec\xb6\x9c" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnAttackEnd constinit property declarations ***************************
// ********** End Function OnAttackEnd constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieCharacter_OnAttackEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieCharacter, nullptr, "OnAttackEnd", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_OnAttackEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieCharacter_OnAttackEnd_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AZombieCharacter_OnAttackEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieCharacter_OnAttackEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieCharacter::execOnAttackEnd)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAttackEnd();
	P_NATIVE_END;
}
// ********** End Class AZombieCharacter Function OnAttackEnd **************************************

// ********** Begin Class AZombieCharacter Function OnAttackHit ************************************
struct Z_Construct_UFunction_AZombieCharacter_OnAttackHit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Zombie" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** AnimNotify(21\xed\x94\x84\xeb\xa0\x88\xec\x9e\x84)\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AnimNotify(21\xed\x94\x84\xeb\xa0\x88\xec\x9e\x84)\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnAttackHit constinit property declarations ***************************
// ********** End Function OnAttackHit constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieCharacter_OnAttackHit_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieCharacter, nullptr, "OnAttackHit", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_OnAttackHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieCharacter_OnAttackHit_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AZombieCharacter_OnAttackHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieCharacter_OnAttackHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieCharacter::execOnAttackHit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAttackHit();
	P_NATIVE_END;
}
// ********** End Class AZombieCharacter Function OnAttackHit **************************************

// ********** Begin Class AZombieCharacter Function OnDeath ****************************************
static FName NAME_AZombieCharacter_OnDeath = FName(TEXT("OnDeath"));
void AZombieCharacter::OnDeath()
{
	UFunction* Func = FindFunctionChecked(NAME_AZombieCharacter_OnDeath);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnDeath_Implementation();
	}
}
struct Z_Construct_UFunction_AZombieCharacter_OnDeath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Zombie" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnDeath constinit property declarations *******************************
// ********** End Function OnDeath constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieCharacter_OnDeath_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieCharacter, nullptr, "OnDeath", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_OnDeath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieCharacter_OnDeath_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AZombieCharacter_OnDeath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieCharacter_OnDeath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieCharacter::execOnDeath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDeath_Implementation();
	P_NATIVE_END;
}
// ********** End Class AZombieCharacter Function OnDeath ******************************************

// ********** Begin Class AZombieCharacter Function StartAttack ************************************
struct Z_Construct_UFunction_AZombieCharacter_StartAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Zombie" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartAttack constinit property declarations ***************************
// ********** End Function StartAttack constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieCharacter_StartAttack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieCharacter, nullptr, "StartAttack", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_StartAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieCharacter_StartAttack_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AZombieCharacter_StartAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieCharacter_StartAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieCharacter::execStartAttack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartAttack();
	P_NATIVE_END;
}
// ********** End Class AZombieCharacter Function StartAttack **************************************

// ********** Begin Class AZombieCharacter Function TakeDamageAmount *******************************
struct Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics
{
	struct ZombieCharacter_eventTakeDamageAmount_Parms
	{
		float Amount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Zombie" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xea\xb3\xb5\xea\xb0\x9c \xed\x95\xa8\xec\x88\x98 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xea\xb3\xb5\xea\xb0\x9c \xed\x95\xa8\xec\x88\x98 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function TakeDamageAmount constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TakeDamageAmount constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TakeDamageAmount Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieCharacter_eventTakeDamageAmount_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::NewProp_Amount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::PropPointers) < 2048);
// ********** End Function TakeDamageAmount Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieCharacter, nullptr, "TakeDamageAmount", 	Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::ZombieCharacter_eventTakeDamageAmount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::ZombieCharacter_eventTakeDamageAmount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieCharacter::execTakeDamageAmount)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TakeDamageAmount(Z_Param_Amount);
	P_NATIVE_END;
}
// ********** End Class AZombieCharacter Function TakeDamageAmount *********************************

// ********** Begin Class AZombieCharacter *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZombieCharacter;
UClass* AZombieCharacter::GetPrivateStaticClass()
{
	using TClass = AZombieCharacter;
	if (!Z_Registration_Info_UClass_AZombieCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieCharacter"),
			Z_Registration_Info_UClass_AZombieCharacter.InnerSingleton,
			StaticRegisterNativesAZombieCharacter,
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
	return Z_Registration_Info_UClass_AZombieCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_AZombieCharacter_NoRegister()
{
	return AZombieCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZombieCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xec\xa2\x80\xeb\xb9\x84 \xec\xba\x90\xeb\xa6\xad\xed\x84\xb0\n * - \xec\x9d\xb4\xeb\x8f\x99\xec\x86\x8d\xeb\x8f\x84 1m/s (WaveManager\xea\xb0\x80 \xec\x8a\xa4\xed\x8f\xb0 \xed\x9b\x84 \xec\x84\xa4\xec\xa0\x95)\n * - \xec\xb2\xb4\xeb\xa0\xa5 6 (WaveManager\xea\xb0\x80 \xec\x8a\xa4\xed\x8f\xb0 \xed\x9b\x84 \xec\x84\xa4\xec\xa0\x95)\n * - \xea\xb7\xbc\xec\xa0\x91 \xea\xb3\xb5\xea\xb2\xa9 \xeb\x8d\xb0\xeb\xaf\xb8\xec\xa7\x80 1, Attack2 \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc 21\xed\x94\x84\xeb\xa0\x88\xec\x9e\x84\xec\x97\x90 \xed\x9e\x88\xed\x8a\xb8\n * - \xec\x8a\xa4\xed\x84\xb4 \xec\xa7\x80\xec\x9b\x90\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Avoid_Zombie/ZombieCharacter.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa2\x80\xeb\xb9\x84 \xec\xba\x90\xeb\xa6\xad\xed\x84\xb0\n- \xec\x9d\xb4\xeb\x8f\x99\xec\x86\x8d\xeb\x8f\x84 1m/s (WaveManager\xea\xb0\x80 \xec\x8a\xa4\xed\x8f\xb0 \xed\x9b\x84 \xec\x84\xa4\xec\xa0\x95)\n- \xec\xb2\xb4\xeb\xa0\xa5 6 (WaveManager\xea\xb0\x80 \xec\x8a\xa4\xed\x8f\xb0 \xed\x9b\x84 \xec\x84\xa4\xec\xa0\x95)\n- \xea\xb7\xbc\xec\xa0\x91 \xea\xb3\xb5\xea\xb2\xa9 \xeb\x8d\xb0\xeb\xaf\xb8\xec\xa7\x80 1, Attack2 \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc 21\xed\x94\x84\xeb\xa0\x88\xec\x9e\x84\xec\x97\x90 \xed\x9e\x88\xed\x8a\xb8\n- \xec\x8a\xa4\xed\x84\xb4 \xec\xa7\x80\xec\x9b\x90" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[] = {
		{ "Category", "Zombie" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x8a\xa4\xed\x83\xaf (WaveManager\xec\x97\x90\xec\x84\x9c \xec\x8a\xa4\xed\x8f\xb0 \xed\x9b\x84 \xec\x84\xa4\xec\xa0\x95) \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x8a\xa4\xed\x83\xaf (WaveManager\xec\x97\x90\xec\x84\x9c \xec\x8a\xa4\xed\x8f\xb0 \xed\x9b\x84 \xec\x84\xa4\xec\xa0\x95) \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Zombie" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 1m/s\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1m/s" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[] = {
		{ "Category", "Zombie" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackDamage_MetaData[] = {
		{ "Category", "Zombie" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[] = {
		{ "Category", "Zombie" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackMontage_MetaData[] = {
		{ "Category", "Zombie|Anim" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Attack2 \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc \xe2\x80\x94 21\xed\x94\x84\xeb\xa0\x88\xec\x9e\x84\xec\x97\x90 ZombieAttackNotify \xeb\xb0\xb0\xec\xb9\x98 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attack2 \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc \xe2\x80\x94 21\xed\x94\x84\xeb\xa0\x88\xec\x9e\x84\xec\x97\x90 ZombieAttackNotify \xeb\xb0\xb0\xec\xb9\x98" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAttacking_MetaData[] = {
		{ "Category", "Zombie" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x83\x81\xed\x83\x9c \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x83\x81\xed\x83\x9c \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsStunned_MetaData[] = {
		{ "Category", "Zombie" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AZombieCharacter constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackMontage;
	static void NewProp_bIsAttacking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAttacking;
	static void NewProp_bIsStunned_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsStunned;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AZombieCharacter constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyStun"), .Pointer = &AZombieCharacter::execApplyStun },
		{ .NameUTF8 = UTF8TEXT("IsDead"), .Pointer = &AZombieCharacter::execIsDead },
		{ .NameUTF8 = UTF8TEXT("IsPlayerInAttackRange"), .Pointer = &AZombieCharacter::execIsPlayerInAttackRange },
		{ .NameUTF8 = UTF8TEXT("OnAttackEnd"), .Pointer = &AZombieCharacter::execOnAttackEnd },
		{ .NameUTF8 = UTF8TEXT("OnAttackHit"), .Pointer = &AZombieCharacter::execOnAttackHit },
		{ .NameUTF8 = UTF8TEXT("OnDeath"), .Pointer = &AZombieCharacter::execOnDeath },
		{ .NameUTF8 = UTF8TEXT("StartAttack"), .Pointer = &AZombieCharacter::execStartAttack },
		{ .NameUTF8 = UTF8TEXT("TakeDamageAmount"), .Pointer = &AZombieCharacter::execTakeDamageAmount },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AZombieCharacter_ApplyStun, "ApplyStun" }, // 2918892946
		{ &Z_Construct_UFunction_AZombieCharacter_IsDead, "IsDead" }, // 3551418089
		{ &Z_Construct_UFunction_AZombieCharacter_IsPlayerInAttackRange, "IsPlayerInAttackRange" }, // 1235393593
		{ &Z_Construct_UFunction_AZombieCharacter_OnAttackEnd, "OnAttackEnd" }, // 700724023
		{ &Z_Construct_UFunction_AZombieCharacter_OnAttackHit, "OnAttackHit" }, // 2318986084
		{ &Z_Construct_UFunction_AZombieCharacter_OnDeath, "OnDeath" }, // 1581880780
		{ &Z_Construct_UFunction_AZombieCharacter_StartAttack, "StartAttack" }, // 4042239291
		{ &Z_Construct_UFunction_AZombieCharacter_TakeDamageAmount, "TakeDamageAmount" }, // 3044515269
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombieCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZombieCharacter_Statics

// ********** Begin Class AZombieCharacter Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombieCharacter_Statics::NewProp_MoveSpeed = { "MoveSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieCharacter, MoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveSpeed_MetaData), NewProp_MoveSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombieCharacter_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieCharacter, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombieCharacter_Statics::NewProp_CurrentHealth = { "CurrentHealth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieCharacter, CurrentHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHealth_MetaData), NewProp_CurrentHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombieCharacter_Statics::NewProp_AttackDamage = { "AttackDamage", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieCharacter, AttackDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackDamage_MetaData), NewProp_AttackDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombieCharacter_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieCharacter, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRange_MetaData), NewProp_AttackRange_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombieCharacter_Statics::NewProp_AttackMontage = { "AttackMontage", nullptr, (EPropertyFlags)0x0114000000010015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieCharacter, AttackMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackMontage_MetaData), NewProp_AttackMontage_MetaData) };
void Z_Construct_UClass_AZombieCharacter_Statics::NewProp_bIsAttacking_SetBit(void* Obj)
{
	((AZombieCharacter*)Obj)->bIsAttacking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZombieCharacter_Statics::NewProp_bIsAttacking = { "bIsAttacking", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AZombieCharacter), &Z_Construct_UClass_AZombieCharacter_Statics::NewProp_bIsAttacking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAttacking_MetaData), NewProp_bIsAttacking_MetaData) };
void Z_Construct_UClass_AZombieCharacter_Statics::NewProp_bIsStunned_SetBit(void* Obj)
{
	((AZombieCharacter*)Obj)->bIsStunned = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZombieCharacter_Statics::NewProp_bIsStunned = { "bIsStunned", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AZombieCharacter), &Z_Construct_UClass_AZombieCharacter_Statics::NewProp_bIsStunned_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsStunned_MetaData), NewProp_bIsStunned_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZombieCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieCharacter_Statics::NewProp_MoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieCharacter_Statics::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieCharacter_Statics::NewProp_CurrentHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieCharacter_Statics::NewProp_AttackDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieCharacter_Statics::NewProp_AttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieCharacter_Statics::NewProp_AttackMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieCharacter_Statics::NewProp_bIsAttacking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieCharacter_Statics::NewProp_bIsStunned,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieCharacter_Statics::PropPointers) < 2048);
// ********** End Class AZombieCharacter Property Definitions **************************************
UObject* (*const Z_Construct_UClass_AZombieCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZombieCharacter_Statics::ClassParams = {
	&AZombieCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AZombieCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AZombieCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AZombieCharacter_Statics::Class_MetaDataParams)
};
void AZombieCharacter::StaticRegisterNativesAZombieCharacter()
{
	UClass* Class = AZombieCharacter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AZombieCharacter_Statics::Funcs));
}
UClass* Z_Construct_UClass_AZombieCharacter()
{
	if (!Z_Registration_Info_UClass_AZombieCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZombieCharacter.OuterSingleton, Z_Construct_UClass_AZombieCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZombieCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZombieCharacter);
AZombieCharacter::~AZombieCharacter() {}
// ********** End Class AZombieCharacter ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZombieCharacter, AZombieCharacter::StaticClass, TEXT("AZombieCharacter"), &Z_Registration_Info_UClass_AZombieCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZombieCharacter), 2682249488U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h__Script_Avoid_Zombie_CPP_234030781{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
