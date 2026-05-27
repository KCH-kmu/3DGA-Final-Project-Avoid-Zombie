// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZombiePlayerCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombiePlayerCharacter() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombiePlayerCharacter();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombiePlayerCharacter_NoRegister();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UWeaponComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZombiePlayerCharacter Function HealHealth *******************************
struct Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics
{
	struct ZombiePlayerCharacter_eventHealHealth_Parms
	{
		float Amount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HealHealth constinit property declarations ****************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HealHealth constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HealHealth Property Definitions ***************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombiePlayerCharacter_eventHealHealth_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::NewProp_Amount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::PropPointers) < 2048);
// ********** End Function HealHealth Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombiePlayerCharacter, nullptr, "HealHealth", 	Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::ZombiePlayerCharacter_eventHealHealth_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::ZombiePlayerCharacter_eventHealHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombiePlayerCharacter::execHealHealth)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HealHealth(Z_Param_Amount);
	P_NATIVE_END;
}
// ********** End Class AZombiePlayerCharacter Function HealHealth *********************************

// ********** Begin Class AZombiePlayerCharacter Function IsDead ***********************************
struct Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics
{
	struct ZombiePlayerCharacter_eventIsDead_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
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
void Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ZombiePlayerCharacter_eventIsDead_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ZombiePlayerCharacter_eventIsDead_Parms), &Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::PropPointers) < 2048);
// ********** End Function IsDead Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombiePlayerCharacter, nullptr, "IsDead", 	Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::ZombiePlayerCharacter_eventIsDead_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::ZombiePlayerCharacter_eventIsDead_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombiePlayerCharacter_IsDead()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombiePlayerCharacter_IsDead_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombiePlayerCharacter::execIsDead)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDead();
	P_NATIVE_END;
}
// ********** End Class AZombiePlayerCharacter Function IsDead *************************************

// ********** Begin Class AZombiePlayerCharacter Function OnDeath **********************************
static FName NAME_AZombiePlayerCharacter_OnDeath = FName(TEXT("OnDeath"));
void AZombiePlayerCharacter::OnDeath()
{
	UFunction* Func = FindFunctionChecked(NAME_AZombiePlayerCharacter_OnDeath);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnDeath_Implementation();
	}
}
struct Z_Construct_UFunction_AZombiePlayerCharacter_OnDeath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnDeath constinit property declarations *******************************
// ********** End Function OnDeath constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombiePlayerCharacter_OnDeath_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombiePlayerCharacter, nullptr, "OnDeath", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_OnDeath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombiePlayerCharacter_OnDeath_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AZombiePlayerCharacter_OnDeath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombiePlayerCharacter_OnDeath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombiePlayerCharacter::execOnDeath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDeath_Implementation();
	P_NATIVE_END;
}
// ********** End Class AZombiePlayerCharacter Function OnDeath ************************************

// ********** Begin Class AZombiePlayerCharacter Function TakeDamageAmount *************************
struct Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics
{
	struct ZombiePlayerCharacter_eventTakeDamageAmount_Parms
	{
		float Amount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TakeDamageAmount constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TakeDamageAmount constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TakeDamageAmount Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombiePlayerCharacter_eventTakeDamageAmount_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::NewProp_Amount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::PropPointers) < 2048);
// ********** End Function TakeDamageAmount Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombiePlayerCharacter, nullptr, "TakeDamageAmount", 	Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::ZombiePlayerCharacter_eventTakeDamageAmount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::ZombiePlayerCharacter_eventTakeDamageAmount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombiePlayerCharacter::execTakeDamageAmount)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TakeDamageAmount(Z_Param_Amount);
	P_NATIVE_END;
}
// ********** End Class AZombiePlayerCharacter Function TakeDamageAmount ***************************

// ********** Begin Class AZombiePlayerCharacter ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZombiePlayerCharacter;
UClass* AZombiePlayerCharacter::GetPrivateStaticClass()
{
	using TClass = AZombiePlayerCharacter;
	if (!Z_Registration_Info_UClass_AZombiePlayerCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombiePlayerCharacter"),
			Z_Registration_Info_UClass_AZombiePlayerCharacter.InnerSingleton,
			StaticRegisterNativesAZombiePlayerCharacter,
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
	return Z_Registration_Info_UClass_AZombiePlayerCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_AZombiePlayerCharacter_NoRegister()
{
	return AZombiePlayerCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZombiePlayerCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Avoid Zombie \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\xba\x90\xeb\xa6\xad\xed\x84\xb0\n *\n * - WASD \xec\x9d\xb4\xeb\x8f\x99 (2m/s), Shift \xeb\x8b\xac\xeb\xa6\xac\xea\xb8\xb0 (4m/s)\n * - \xeb\x8b\xac\xeb\xa6\xac\xea\xb8\xb0 \xec\xa4\x91 \xea\xb3\xb5\xea\xb2\xa9 \xeb\xb6\x88\xea\xb0\x80\n * - \xec\xb2\xb4\xeb\xa0\xa5 \xec\xb5\x9c\xeb\x8c\x80 10\n * - WeaponComponent (AR) \xeb\xb6\x80\xec\xb0\xa9\n * - \xec\xa2\x8c\xed\x81\xb4\xeb\xa6\xad \xec\x82\xac\xea\xb2\xa9, R \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84, \xec\x9a\xb0\xed\x81\xb4\xeb\xa6\xad \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x82\xac\xec\x9a\xa9\n * - \xeb\xa7\x88\xec\x9a\xb0\xec\x8a\xa4\xeb\xa1\x9c \xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc & \xea\xb3\xb5\xea\xb2\xa9 \xeb\xb0\xa9\xed\x96\xa5 \xec\xa0\x9c\xec\x96\xb4\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Avoid Zombie \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\xba\x90\xeb\xa6\xad\xed\x84\xb0\n\n- WASD \xec\x9d\xb4\xeb\x8f\x99 (2m/s), Shift \xeb\x8b\xac\xeb\xa6\xac\xea\xb8\xb0 (4m/s)\n- \xeb\x8b\xac\xeb\xa6\xac\xea\xb8\xb0 \xec\xa4\x91 \xea\xb3\xb5\xea\xb2\xa9 \xeb\xb6\x88\xea\xb0\x80\n- \xec\xb2\xb4\xeb\xa0\xa5 \xec\xb5\x9c\xeb\x8c\x80 10\n- WeaponComponent (AR) \xeb\xb6\x80\xec\xb0\xa9\n- \xec\xa2\x8c\xed\x81\xb4\xeb\xa6\xad \xec\x82\xac\xea\xb2\xa9, R \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84, \xec\x9a\xb0\xed\x81\xb4\xeb\xa6\xad \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x82\xac\xec\x9a\xa9\n- \xeb\xa7\x88\xec\x9a\xb0\xec\x8a\xa4\xeb\xa1\x9c \xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc & \xea\xb3\xb5\xea\xb2\xa9 \xeb\xb0\xa9\xed\x96\xa5 \xec\xa0\x9c\xec\x96\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponComp_MetaData[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xeb\xac\xb4\xea\xb8\xb0 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xeb\xac\xb4\xea\xb8\xb0 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Health" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\xb2\xb4\xeb\xa0\xa5 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\xb2\xb4\xeb\xa0\xa5 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSprinting_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x9d\xb4\xeb\x8f\x99 \xec\x83\x81\xed\x83\x9c \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x9d\xb4\xeb\x8f\x99 \xec\x83\x81\xed\x83\x9c \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MappingContext_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x9e\x85\xeb\xa0\xa5 \xec\x95\xa1\xec\x85\x98 (\xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c \xed\x95\xa0\xeb\x8b\xb9) \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x9e\x85\xeb\xa0\xa5 \xec\x95\xa1\xec\x85\x98 (\xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c \xed\x95\xa0\xeb\x8b\xb9) \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UseItemAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombiePlayerCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AZombiePlayerCharacter constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponComp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth;
	static void NewProp_bIsSprinting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSprinting;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SprintAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UseItemAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AZombiePlayerCharacter constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HealHealth"), .Pointer = &AZombiePlayerCharacter::execHealHealth },
		{ .NameUTF8 = UTF8TEXT("IsDead"), .Pointer = &AZombiePlayerCharacter::execIsDead },
		{ .NameUTF8 = UTF8TEXT("OnDeath"), .Pointer = &AZombiePlayerCharacter::execOnDeath },
		{ .NameUTF8 = UTF8TEXT("TakeDamageAmount"), .Pointer = &AZombiePlayerCharacter::execTakeDamageAmount },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AZombiePlayerCharacter_HealHealth, "HealHealth" }, // 3746044775
		{ &Z_Construct_UFunction_AZombiePlayerCharacter_IsDead, "IsDead" }, // 3167564452
		{ &Z_Construct_UFunction_AZombiePlayerCharacter_OnDeath, "OnDeath" }, // 608268507
		{ &Z_Construct_UFunction_AZombiePlayerCharacter_TakeDamageAmount, "TakeDamageAmount" }, // 249634133
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombiePlayerCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZombiePlayerCharacter_Statics

// ********** Begin Class AZombiePlayerCharacter Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_WeaponComp = { "WeaponComp", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, WeaponComp), Z_Construct_UClass_UWeaponComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponComp_MetaData), NewProp_WeaponComp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_CurrentHealth = { "CurrentHealth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, CurrentHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHealth_MetaData), NewProp_CurrentHealth_MetaData) };
void Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_bIsSprinting_SetBit(void* Obj)
{
	((AZombiePlayerCharacter*)Obj)->bIsSprinting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_bIsSprinting = { "bIsSprinting", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AZombiePlayerCharacter), &Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_bIsSprinting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSprinting_MetaData), NewProp_bIsSprinting_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_MappingContext = { "MappingContext", nullptr, (EPropertyFlags)0x0114000000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, MappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MappingContext_MetaData), NewProp_MappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0114000000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0114000000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_SprintAction = { "SprintAction", nullptr, (EPropertyFlags)0x0114000000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, SprintAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAction_MetaData), NewProp_SprintAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_FireAction = { "FireAction", nullptr, (EPropertyFlags)0x0114000000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, FireAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireAction_MetaData), NewProp_FireAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_ReloadAction = { "ReloadAction", nullptr, (EPropertyFlags)0x0114000000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, ReloadAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadAction_MetaData), NewProp_ReloadAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_UseItemAction = { "UseItemAction", nullptr, (EPropertyFlags)0x0114000000010001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, UseItemAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UseItemAction_MetaData), NewProp_UseItemAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombiePlayerCharacter, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSpeed_MetaData), NewProp_SprintSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZombiePlayerCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_WeaponComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_CurrentHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_bIsSprinting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_MappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_SprintAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_FireAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_ReloadAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_UseItemAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombiePlayerCharacter_Statics::NewProp_SprintSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombiePlayerCharacter_Statics::PropPointers) < 2048);
// ********** End Class AZombiePlayerCharacter Property Definitions ********************************
UObject* (*const Z_Construct_UClass_AZombiePlayerCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombiePlayerCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZombiePlayerCharacter_Statics::ClassParams = {
	&AZombiePlayerCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AZombiePlayerCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AZombiePlayerCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZombiePlayerCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AZombiePlayerCharacter_Statics::Class_MetaDataParams)
};
void AZombiePlayerCharacter::StaticRegisterNativesAZombiePlayerCharacter()
{
	UClass* Class = AZombiePlayerCharacter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AZombiePlayerCharacter_Statics::Funcs));
}
UClass* Z_Construct_UClass_AZombiePlayerCharacter()
{
	if (!Z_Registration_Info_UClass_AZombiePlayerCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZombiePlayerCharacter.OuterSingleton, Z_Construct_UClass_AZombiePlayerCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZombiePlayerCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZombiePlayerCharacter);
AZombiePlayerCharacter::~AZombiePlayerCharacter() {}
// ********** End Class AZombiePlayerCharacter *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZombiePlayerCharacter, AZombiePlayerCharacter::StaticClass, TEXT("AZombiePlayerCharacter"), &Z_Registration_Info_UClass_AZombiePlayerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZombiePlayerCharacter), 3475377049U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h__Script_Avoid_Zombie_CPP_3565440092{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
