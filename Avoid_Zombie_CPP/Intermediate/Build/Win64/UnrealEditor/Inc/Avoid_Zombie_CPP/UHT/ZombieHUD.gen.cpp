// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/ZombieHUD.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieHUD() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieHUD();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieHUD_NoRegister();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UZombieHUDWidget_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AHUD();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZombieHUD Function OnAmmoChanged ****************************************
struct Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics
{
	struct ZombieHUD_eventOnAmmoChanged_Parms
	{
		int32 Current;
		int32 Max;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xed\x83\x84\xec\x95\xbd HUD \xea\xb0\xb1\xec\x8b\xa0 \xe2\x80\x94 WeaponComponent.OnAmmoChanged\xec\x97\x90 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/UI/ZombieHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x83\x84\xec\x95\xbd HUD \xea\xb0\xb1\xec\x8b\xa0 \xe2\x80\x94 WeaponComponent.OnAmmoChanged\xec\x97\x90 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnAmmoChanged constinit property declarations *************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Current;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnAmmoChanged constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnAmmoChanged Property Definitions ************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::NewProp_Current = { "Current", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieHUD_eventOnAmmoChanged_Parms, Current), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieHUD_eventOnAmmoChanged_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::NewProp_Current,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::PropPointers) < 2048);
// ********** End Function OnAmmoChanged Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AZombieHUD, nullptr, "OnAmmoChanged", 	Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::ZombieHUD_eventOnAmmoChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::ZombieHUD_eventOnAmmoChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AZombieHUD_OnAmmoChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZombieHUD_OnAmmoChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AZombieHUD::execOnAmmoChanged)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Current);
	P_GET_PROPERTY(FIntProperty,Z_Param_Max);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAmmoChanged(Z_Param_Current,Z_Param_Max);
	P_NATIVE_END;
}
// ********** End Class AZombieHUD Function OnAmmoChanged ******************************************

// ********** Begin Class AZombieHUD ***************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZombieHUD;
UClass* AZombieHUD::GetPrivateStaticClass()
{
	using TClass = AZombieHUD;
	if (!Z_Registration_Info_UClass_AZombieHUD.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieHUD"),
			Z_Registration_Info_UClass_AZombieHUD.InnerSingleton,
			StaticRegisterNativesAZombieHUD,
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
	return Z_Registration_Info_UClass_AZombieHUD.InnerSingleton;
}
UClass* Z_Construct_UClass_AZombieHUD_NoRegister()
{
	return AZombieHUD::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZombieHUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Avoid Zombie HUD\n *\n * BeginPlay\xec\x97\x90\xec\x84\x9c HUDWidgetClass\xeb\xa1\x9c \xec\x9c\x84\xec\xa0\xaf\xec\x9d\x84 \xec\x83\x9d\xec\x84\xb1\xc2\xb7\xeb\xb7\xb0\xed\x8f\xac\xed\x8a\xb8 \xec\xb6\x94\xea\xb0\x80\xed\x95\x98\xea\xb3\xa0\n * WeaponComponent.OnAmmoChanged \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\xec\x97\x90 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n *\n * \xec\x97\x90\xeb\x94\x94\xed\x84\xb0 \xec\x84\xa4\xec\xa0\x95:\n * 1. BP_ZombieHUD(\xec\x9d\xb4 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xec\x9d\x98 \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8)\xeb\xa5\xbc \xec\x83\x9d\xec\x84\xb1\xed\x95\x98\xea\xb3\xa0\n *    HUDWidgetClass\xec\x97\x90 WBP_ZombieHUD\xeb\xa5\xbc \xed\x95\xa0\xeb\x8b\xb9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n * 2. ZombieGameMode\xec\x9d\x98 HUD Class\xeb\xa5\xbc BP_ZombieHUD\xeb\xa1\x9c \xec\xa7\x80\xec\xa0\x95\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n */" },
#endif
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Avoid_Zombie/UI/ZombieHUD.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/UI/ZombieHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Avoid Zombie HUD\n\nBeginPlay\xec\x97\x90\xec\x84\x9c HUDWidgetClass\xeb\xa1\x9c \xec\x9c\x84\xec\xa0\xaf\xec\x9d\x84 \xec\x83\x9d\xec\x84\xb1\xc2\xb7\xeb\xb7\xb0\xed\x8f\xac\xed\x8a\xb8 \xec\xb6\x94\xea\xb0\x80\xed\x95\x98\xea\xb3\xa0\nWeaponComponent.OnAmmoChanged \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\xec\x97\x90 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n\n\xec\x97\x90\xeb\x94\x94\xed\x84\xb0 \xec\x84\xa4\xec\xa0\x95:\n1. BP_ZombieHUD(\xec\x9d\xb4 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xec\x9d\x98 \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8)\xeb\xa5\xbc \xec\x83\x9d\xec\x84\xb1\xed\x95\x98\xea\xb3\xa0\n   HUDWidgetClass\xec\x97\x90 WBP_ZombieHUD\xeb\xa5\xbc \xed\x95\xa0\xeb\x8b\xb9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n2. ZombieGameMode\xec\x9d\x98 HUD Class\xeb\xa5\xbc BP_ZombieHUD\xeb\xa1\x9c \xec\xa7\x80\xec\xa0\x95\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetClass_MetaData[] = {
		{ "Category", "HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c WBP_ZombieHUD \xed\x95\xa0\xeb\x8b\xb9 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/UI/ZombieHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c WBP_ZombieHUD \xed\x95\xa0\xeb\x8b\xb9" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Avoid_Zombie/UI/ZombieHUD.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AZombieHUD constinit property declarations *******************************
	static const UECodeGen_Private::FClassPropertyParams NewProp_HUDWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HUDWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AZombieHUD constinit property declarations *********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnAmmoChanged"), .Pointer = &AZombieHUD::execOnAmmoChanged },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AZombieHUD_OnAmmoChanged, "OnAmmoChanged" }, // 905043353
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombieHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZombieHUD_Statics

// ********** Begin Class AZombieHUD Property Definitions ******************************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AZombieHUD_Statics::NewProp_HUDWidgetClass = { "HUDWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieHUD, HUDWidgetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UZombieHUDWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidgetClass_MetaData), NewProp_HUDWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZombieHUD_Statics::NewProp_HUDWidget = { "HUDWidget", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AZombieHUD, HUDWidget), Z_Construct_UClass_UZombieHUDWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidget_MetaData), NewProp_HUDWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZombieHUD_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieHUD_Statics::NewProp_HUDWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZombieHUD_Statics::NewProp_HUDWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieHUD_Statics::PropPointers) < 2048);
// ********** End Class AZombieHUD Property Definitions ********************************************
UObject* (*const Z_Construct_UClass_AZombieHUD_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHUD,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieHUD_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZombieHUD_Statics::ClassParams = {
	&AZombieHUD::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AZombieHUD_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AZombieHUD_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZombieHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_AZombieHUD_Statics::Class_MetaDataParams)
};
void AZombieHUD::StaticRegisterNativesAZombieHUD()
{
	UClass* Class = AZombieHUD::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AZombieHUD_Statics::Funcs));
}
UClass* Z_Construct_UClass_AZombieHUD()
{
	if (!Z_Registration_Info_UClass_AZombieHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZombieHUD.OuterSingleton, Z_Construct_UClass_AZombieHUD_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZombieHUD.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZombieHUD);
AZombieHUD::~AZombieHUD() {}
// ********** End Class AZombieHUD *****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZombieHUD, AZombieHUD::StaticClass, TEXT("AZombieHUD"), &Z_Registration_Info_UClass_AZombieHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZombieHUD), 3890636499U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h__Script_Avoid_Zombie_CPP_574112117{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
