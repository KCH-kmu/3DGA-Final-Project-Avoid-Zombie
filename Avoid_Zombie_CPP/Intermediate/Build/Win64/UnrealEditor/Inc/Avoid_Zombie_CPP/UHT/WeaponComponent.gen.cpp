// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeWeaponComponent() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UWeaponComponent();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UWeaponComponent_NoRegister();
AVOID_ZOMBIE_CPP_API UEnum* Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType();
AVOID_ZOMBIE_CPP_API UFunction* Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EItemType *****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EItemType;
static UEnum* EItemType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EItemType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EItemType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType, (UObject*)Z_Construct_UPackage__Script_Avoid_Zombie_CPP(), TEXT("EItemType"));
	}
	return Z_Registration_Info_UEnum_EItemType.OuterSingleton;
}
template<> AVOID_ZOMBIE_CPP_NON_ATTRIBUTED_API UEnum* StaticEnum<EItemType>()
{
	return EItemType_StaticEnum();
}
struct Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\xa2\x85\xeb\xa5\x98 */" },
#endif
		{ "FireRateUp.DisplayName", "\xeb\xb0\x9c\xec\x82\xac\xec\x86\x8d\xeb\x8f\x84 \xec\xa6\x9d\xea\xb0\x80 5\xec\xb4\x88" },
		{ "FireRateUp.Name", "EItemType::FireRateUp" },
		{ "HealSelf.DisplayName", "\xec\xb2\xb4\xeb\xa0\xa5 2 \xed\x9a\x8c\xeb\xb3\xb5" },
		{ "HealSelf.Name", "EItemType::HealSelf" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
		{ "None.DisplayName", "\xec\x97\x86\xec\x9d\x8c" },
		{ "None.Name", "EItemType::None" },
		{ "StunAll.DisplayName", "\xec\xa0\x84\xec\xb2\xb4 \xec\x8a\xa4\xed\x84\xb4 3\xec\xb4\x88" },
		{ "StunAll.Name", "EItemType::StunAll" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\xa2\x85\xeb\xa5\x98" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EItemType::None", (int64)EItemType::None },
		{ "EItemType::StunAll", (int64)EItemType::StunAll },
		{ "EItemType::FireRateUp", (int64)EItemType::FireRateUp },
		{ "EItemType::HealSelf", (int64)EItemType::HealSelf },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
	nullptr,
	"EItemType",
	"EItemType",
	Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType()
{
	if (!Z_Registration_Info_UEnum_EItemType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EItemType.InnerSingleton, Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EItemType.InnerSingleton;
}
// ********** End Enum EItemType *******************************************************************

// ********** Begin Delegate FOnAmmoChanged ********************************************************
struct Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics
{
	struct _Script_Avoid_Zombie_CPP_eventOnAmmoChanged_Parms
	{
		int32 CurrentAmmo;
		int32 MaxAmmo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xed\x83\x84\xec\x95\xbd \xeb\xb3\x80\xea\xb2\xbd \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8 (\xed\x98\x84\xec\x9e\xac \xed\x83\x84\xec\x95\xbd, \xec\xb5\x9c\xeb\x8c\x80 \xed\x83\x84\xec\x95\xbd) */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x83\x84\xec\x95\xbd \xeb\xb3\x80\xea\xb2\xbd \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8 (\xed\x98\x84\xec\x9e\xac \xed\x83\x84\xec\x95\xbd, \xec\xb5\x9c\xeb\x8c\x80 \xed\x83\x84\xec\x95\xbd)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnAmmoChanged constinit property declarations ************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentAmmo;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnAmmoChanged constinit property declarations **************************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnAmmoChanged Property Definitions ***********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::NewProp_CurrentAmmo = { "CurrentAmmo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Avoid_Zombie_CPP_eventOnAmmoChanged_Parms, CurrentAmmo), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::NewProp_MaxAmmo = { "MaxAmmo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Avoid_Zombie_CPP_eventOnAmmoChanged_Parms, MaxAmmo), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::NewProp_CurrentAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::NewProp_MaxAmmo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnAmmoChanged Property Definitions *************************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP, nullptr, "OnAmmoChanged__DelegateSignature", 	Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::_Script_Avoid_Zombie_CPP_eventOnAmmoChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::_Script_Avoid_Zombie_CPP_eventOnAmmoChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAmmoChanged_DelegateWrapper(const FMulticastScriptDelegate& OnAmmoChanged, int32 CurrentAmmo, int32 MaxAmmo)
{
	struct _Script_Avoid_Zombie_CPP_eventOnAmmoChanged_Parms
	{
		int32 CurrentAmmo;
		int32 MaxAmmo;
	};
	_Script_Avoid_Zombie_CPP_eventOnAmmoChanged_Parms Parms;
	Parms.CurrentAmmo=CurrentAmmo;
	Parms.MaxAmmo=MaxAmmo;
	OnAmmoChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnAmmoChanged **********************************************************

// ********** Begin Class UWeaponComponent Function GetCurrentReloadTime ***************************
struct Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics
{
	struct WeaponComponent_eventGetCurrentReloadTime_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentReloadTime constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentReloadTime constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentReloadTime Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponComponent_eventGetCurrentReloadTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentReloadTime Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWeaponComponent, nullptr, "GetCurrentReloadTime", 	Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::WeaponComponent_eventGetCurrentReloadTime_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::WeaponComponent_eventGetCurrentReloadTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponComponent::execGetCurrentReloadTime)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCurrentReloadTime();
	P_NATIVE_END;
}
// ********** End Class UWeaponComponent Function GetCurrentReloadTime *****************************

// ********** Begin Class UWeaponComponent Function GetCurrentRPS **********************************
struct Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics
{
	struct WeaponComponent_eventGetCurrentRPS_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentRPS constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentRPS constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentRPS Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponComponent_eventGetCurrentRPS_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentRPS Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWeaponComponent, nullptr, "GetCurrentRPS", 	Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::WeaponComponent_eventGetCurrentRPS_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::WeaponComponent_eventGetCurrentRPS_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponComponent::execGetCurrentRPS)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCurrentRPS();
	P_NATIVE_END;
}
// ********** End Class UWeaponComponent Function GetCurrentRPS ************************************

// ********** Begin Class UWeaponComponent Function ReceiveItem ************************************
struct Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics
{
	struct WeaponComponent_eventReceiveItem_Parms
	{
		EItemType ItemType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Item" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ReceiveItem constinit property declarations ***************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ItemType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ItemType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ReceiveItem constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ReceiveItem Property Definitions **************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::NewProp_ItemType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::NewProp_ItemType = { "ItemType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponComponent_eventReceiveItem_Parms, ItemType), Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType, METADATA_PARAMS(0, nullptr) }; // 2004411603
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::NewProp_ItemType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::NewProp_ItemType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::PropPointers) < 2048);
// ********** End Function ReceiveItem Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWeaponComponent, nullptr, "ReceiveItem", 	Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::WeaponComponent_eventReceiveItem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::WeaponComponent_eventReceiveItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWeaponComponent_ReceiveItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponComponent_ReceiveItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponComponent::execReceiveItem)
{
	P_GET_ENUM(EItemType,Z_Param_ItemType);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ReceiveItem(EItemType(Z_Param_ItemType));
	P_NATIVE_END;
}
// ********** End Class UWeaponComponent Function ReceiveItem **************************************

// ********** Begin Class UWeaponComponent Function StartFire **************************************
struct Z_Construct_UFunction_UWeaponComponent_StartFire_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xea\xb3\xb5\xea\xb0\x9c \xed\x95\xa8\xec\x88\x98 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xea\xb3\xb5\xea\xb0\x9c \xed\x95\xa8\xec\x88\x98 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StartFire constinit property declarations *****************************
// ********** End Function StartFire constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponComponent_StartFire_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWeaponComponent, nullptr, "StartFire", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_StartFire_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponComponent_StartFire_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UWeaponComponent_StartFire()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponComponent_StartFire_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponComponent::execStartFire)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartFire();
	P_NATIVE_END;
}
// ********** End Class UWeaponComponent Function StartFire ****************************************

// ********** Begin Class UWeaponComponent Function StartReload ************************************
struct Z_Construct_UFunction_UWeaponComponent_StartReload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartReload constinit property declarations ***************************
// ********** End Function StartReload constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponComponent_StartReload_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWeaponComponent, nullptr, "StartReload", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_StartReload_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponComponent_StartReload_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UWeaponComponent_StartReload()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponComponent_StartReload_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponComponent::execStartReload)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartReload();
	P_NATIVE_END;
}
// ********** End Class UWeaponComponent Function StartReload **************************************

// ********** Begin Class UWeaponComponent Function StopFire ***************************************
struct Z_Construct_UFunction_UWeaponComponent_StopFire_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopFire constinit property declarations ******************************
// ********** End Function StopFire constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponComponent_StopFire_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWeaponComponent, nullptr, "StopFire", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_StopFire_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponComponent_StopFire_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UWeaponComponent_StopFire()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponComponent_StopFire_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponComponent::execStopFire)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopFire();
	P_NATIVE_END;
}
// ********** End Class UWeaponComponent Function StopFire *****************************************

// ********** Begin Class UWeaponComponent Function UseHeldItem ************************************
struct Z_Construct_UFunction_UWeaponComponent_UseHeldItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Item" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UseHeldItem constinit property declarations ***************************
// ********** End Function UseHeldItem constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponComponent_UseHeldItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWeaponComponent, nullptr, "UseHeldItem", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponComponent_UseHeldItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponComponent_UseHeldItem_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UWeaponComponent_UseHeldItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponComponent_UseHeldItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponComponent::execUseHeldItem)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UseHeldItem();
	P_NATIVE_END;
}
// ********** End Class UWeaponComponent Function UseHeldItem **************************************

// ********** Begin Class UWeaponComponent *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UWeaponComponent;
UClass* UWeaponComponent::GetPrivateStaticClass()
{
	using TClass = UWeaponComponent;
	if (!Z_Registration_Info_UClass_UWeaponComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("WeaponComponent"),
			Z_Registration_Info_UClass_UWeaponComponent.InnerSingleton,
			StaticRegisterNativesUWeaponComponent,
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
	return Z_Registration_Info_UClass_UWeaponComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UWeaponComponent_NoRegister()
{
	return UWeaponComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWeaponComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xeb\xac\xb4\xea\xb8\xb0 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 (AR)\n *\n * \xec\x8a\xa4\xed\x8e\x99:\n * - \xed\x83\x84\xec\xb0\xbd 30\xeb\xb0\x9c / \xed\x83\x84\xec\x95\xbd \xeb\xac\xb4\xed\x95\x9c\n * - RPS 10\xeb\xb0\x9c/\xec\xb4\x88, \xeb\xb0\x9c\xeb\x8b\xb9 \xeb\x8d\xb0\xeb\xaf\xb8\xec\xa7\x80 2\n * - \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 2\xec\xb4\x88 (R \xeb\x98\x90\xeb\x8a\x94 0\xeb\xb0\x9c \xec\x8b\x9c \xec\x9e\x90\xeb\x8f\x99)\n * - \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 \xec\xa7\x84\xed\x96\x89\xeb\xa5\xa0(0~1) \xe2\x86\x92 \xed\x81\xac\xeb\xa1\x9c\xec\x8a\xa4\xed\x97\xa4\xec\x96\xb4 \xec\x9b\x90\xed\x98\x95 \xed\x83\x80\xec\x9d\xb4\xeb\xa8\xb8\xec\x97\x90 \xec\x82\xac\xec\x9a\xa9\n *\n * \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c FireRateUp \xeb\xb0\x9c\xeb\x8f\x99 \xec\x8b\x9c:\n * - RPS 15 / \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 1\xec\xb4\x88 / 5\xec\xb4\x88\xea\xb0\x84 \xec\x9c\xa0\xec\xa7\x80\n */" },
#endif
		{ "IncludePath", "Avoid_Zombie/WeaponComponent.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xac\xb4\xea\xb8\xb0 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 (AR)\n\n\xec\x8a\xa4\xed\x8e\x99:\n- \xed\x83\x84\xec\xb0\xbd 30\xeb\xb0\x9c / \xed\x83\x84\xec\x95\xbd \xeb\xac\xb4\xed\x95\x9c\n- RPS 10\xeb\xb0\x9c/\xec\xb4\x88, \xeb\xb0\x9c\xeb\x8b\xb9 \xeb\x8d\xb0\xeb\xaf\xb8\xec\xa7\x80 2\n- \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 2\xec\xb4\x88 (R \xeb\x98\x90\xeb\x8a\x94 0\xeb\xb0\x9c \xec\x8b\x9c \xec\x9e\x90\xeb\x8f\x99)\n- \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 \xec\xa7\x84\xed\x96\x89\xeb\xa5\xa0(0~1) \xe2\x86\x92 \xed\x81\xac\xeb\xa1\x9c\xec\x8a\xa4\xed\x97\xa4\xec\x96\xb4 \xec\x9b\x90\xed\x98\x95 \xed\x83\x80\xec\x9d\xb4\xeb\xa8\xb8\xec\x97\x90 \xec\x82\xac\xec\x9a\xa9\n\n\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c FireRateUp \xeb\xb0\x9c\xeb\x8f\x99 \xec\x8b\x9c:\n- RPS 15 / \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 1\xec\xb4\x88 / 5\xec\xb4\x88\xea\xb0\x84 \xec\x9c\xa0\xec\xa7\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAmmoChanged_MetaData[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xed\x83\x84\xec\x95\xbd \xec\x88\x98 \xeb\xb3\x80\xea\xb2\xbd \xec\x8b\x9c broadcast (HUD \xea\xb0\xb1\xec\x8b\xa0\xec\x9a\xa9) */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x83\x84\xec\x95\xbd \xec\x88\x98 \xeb\xb3\x80\xea\xb2\xbd \xec\x8b\x9c broadcast (HUD \xea\xb0\xb1\xec\x8b\xa0\xec\x9a\xa9)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAmmo_MetaData[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xed\x83\x84\xec\x95\xbd \xec\x83\x81\xed\x83\x9c \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xed\x83\x84\xec\x95\xbd \xec\x83\x81\xed\x83\x9c \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmmo_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsReloading_MetaData[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 \xec\x83\x81\xed\x83\x9c (UI\xec\x9a\xa9) \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 \xec\x83\x81\xed\x83\x9c (UI\xec\x9a\xa9) \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadProgress_MetaData[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 \xec\xa7\x84\xed\x96\x89\xeb\xa5\xa0 0.0~1.0 (\xed\x81\xac\xeb\xa1\x9c\xec\x8a\xa4\xed\x97\xa4\xec\x96\xb4 \xec\x9b\x90\xed\x98\x95 \xed\x83\x80\xec\x9d\xb4\xeb\xa8\xb8) */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84 \xec\xa7\x84\xed\x96\x89\xeb\xa5\xa0 0.0~1.0 (\xed\x81\xac\xeb\xa1\x9c\xec\x8a\xa4\xed\x97\xa4\xec\x96\xb4 \xec\x9b\x90\xed\x98\x95 \xed\x83\x80\xec\x9d\xb4\xeb\xa8\xb8)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeldItem_MetaData[] = {
		{ "Category", "Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDamagePerBullet_MetaData[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xea\xb8\xb0\xeb\xb3\xb8 \xeb\xac\xb4\xea\xb8\xb0 \xec\x8a\xa4\xed\x8e\x99 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xea\xb8\xb0\xeb\xb3\xb8 \xeb\xac\xb4\xea\xb8\xb0 \xec\x8a\xa4\xed\x8e\x99 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseRPS_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseReloadTime_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuffRPS_MetaData[] = {
		{ "Category", "Weapon|Buff" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xeb\xb2\x84\xed\x94\x84 \xec\x8a\xa4\xed\x8e\x99 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\n" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80 \xeb\xb2\x84\xed\x94\x84 \xec\x8a\xa4\xed\x8e\x99 \xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuffReloadTime_MetaData[] = {
		{ "Category", "Weapon|Buff" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuffDuration_MetaData[] = {
		{ "Category", "Weapon|Buff" },
		{ "ModuleRelativePath", "Avoid_Zombie/WeaponComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UWeaponComponent constinit property declarations *************************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAmmoChanged;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentAmmo;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmo;
	static void NewProp_bIsReloading_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsReloading;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReloadProgress;
	static const UECodeGen_Private::FBytePropertyParams NewProp_HeldItem_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_HeldItem;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseDamagePerBullet;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseRPS;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseReloadTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BuffRPS;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BuffReloadTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BuffDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UWeaponComponent constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetCurrentReloadTime"), .Pointer = &UWeaponComponent::execGetCurrentReloadTime },
		{ .NameUTF8 = UTF8TEXT("GetCurrentRPS"), .Pointer = &UWeaponComponent::execGetCurrentRPS },
		{ .NameUTF8 = UTF8TEXT("ReceiveItem"), .Pointer = &UWeaponComponent::execReceiveItem },
		{ .NameUTF8 = UTF8TEXT("StartFire"), .Pointer = &UWeaponComponent::execStartFire },
		{ .NameUTF8 = UTF8TEXT("StartReload"), .Pointer = &UWeaponComponent::execStartReload },
		{ .NameUTF8 = UTF8TEXT("StopFire"), .Pointer = &UWeaponComponent::execStopFire },
		{ .NameUTF8 = UTF8TEXT("UseHeldItem"), .Pointer = &UWeaponComponent::execUseHeldItem },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWeaponComponent_GetCurrentReloadTime, "GetCurrentReloadTime" }, // 2000636527
		{ &Z_Construct_UFunction_UWeaponComponent_GetCurrentRPS, "GetCurrentRPS" }, // 49646911
		{ &Z_Construct_UFunction_UWeaponComponent_ReceiveItem, "ReceiveItem" }, // 2980140346
		{ &Z_Construct_UFunction_UWeaponComponent_StartFire, "StartFire" }, // 2436939589
		{ &Z_Construct_UFunction_UWeaponComponent_StartReload, "StartReload" }, // 545705800
		{ &Z_Construct_UFunction_UWeaponComponent_StopFire, "StopFire" }, // 3697653364
		{ &Z_Construct_UFunction_UWeaponComponent_UseHeldItem, "UseHeldItem" }, // 4273089005
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWeaponComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UWeaponComponent_Statics

// ********** Begin Class UWeaponComponent Property Definitions ************************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_OnAmmoChanged = { "OnAmmoChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, OnAmmoChanged), Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnAmmoChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAmmoChanged_MetaData), NewProp_OnAmmoChanged_MetaData) }; // 3489060899
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_CurrentAmmo = { "CurrentAmmo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, CurrentAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAmmo_MetaData), NewProp_CurrentAmmo_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_MaxAmmo = { "MaxAmmo", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, MaxAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmmo_MetaData), NewProp_MaxAmmo_MetaData) };
void Z_Construct_UClass_UWeaponComponent_Statics::NewProp_bIsReloading_SetBit(void* Obj)
{
	((UWeaponComponent*)Obj)->bIsReloading = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_bIsReloading = { "bIsReloading", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UWeaponComponent), &Z_Construct_UClass_UWeaponComponent_Statics::NewProp_bIsReloading_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsReloading_MetaData), NewProp_bIsReloading_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_ReloadProgress = { "ReloadProgress", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, ReloadProgress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadProgress_MetaData), NewProp_ReloadProgress_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_HeldItem_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_HeldItem = { "HeldItem", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, HeldItem), Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeldItem_MetaData), NewProp_HeldItem_MetaData) }; // 2004411603
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BaseDamagePerBullet = { "BaseDamagePerBullet", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, BaseDamagePerBullet), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDamagePerBullet_MetaData), NewProp_BaseDamagePerBullet_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BaseRPS = { "BaseRPS", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, BaseRPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseRPS_MetaData), NewProp_BaseRPS_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BaseReloadTime = { "BaseReloadTime", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, BaseReloadTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseReloadTime_MetaData), NewProp_BaseReloadTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BuffRPS = { "BuffRPS", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, BuffRPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuffRPS_MetaData), NewProp_BuffRPS_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BuffReloadTime = { "BuffReloadTime", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, BuffReloadTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuffReloadTime_MetaData), NewProp_BuffReloadTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BuffDuration = { "BuffDuration", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponComponent, BuffDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuffDuration_MetaData), NewProp_BuffDuration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UWeaponComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_OnAmmoChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_CurrentAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_MaxAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_bIsReloading,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_ReloadProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_HeldItem_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_HeldItem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BaseDamagePerBullet,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BaseRPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BaseReloadTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BuffRPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BuffReloadTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponComponent_Statics::NewProp_BuffDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponComponent_Statics::PropPointers) < 2048);
// ********** End Class UWeaponComponent Property Definitions **************************************
UObject* (*const Z_Construct_UClass_UWeaponComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWeaponComponent_Statics::ClassParams = {
	&UWeaponComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UWeaponComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UWeaponComponent_Statics::Class_MetaDataParams)
};
void UWeaponComponent::StaticRegisterNativesUWeaponComponent()
{
	UClass* Class = UWeaponComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UWeaponComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UWeaponComponent()
{
	if (!Z_Registration_Info_UClass_UWeaponComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWeaponComponent.OuterSingleton, Z_Construct_UClass_UWeaponComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWeaponComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UWeaponComponent);
UWeaponComponent::~UWeaponComponent() {}
// ********** End Class UWeaponComponent ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WeaponComponent_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EItemType_StaticEnum, TEXT("EItemType"), &Z_Registration_Info_UEnum_EItemType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2004411603U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWeaponComponent, UWeaponComponent::StaticClass, TEXT("UWeaponComponent"), &Z_Registration_Info_UClass_UWeaponComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWeaponComponent), 2236142654U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WeaponComponent_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WeaponComponent_h__Script_Avoid_Zombie_CPP_3800971107{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WeaponComponent_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WeaponComponent_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WeaponComponent_h__Script_Avoid_Zombie_CPP_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WeaponComponent_h__Script_Avoid_Zombie_CPP_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
