// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/ZombieHUDWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieHUDWidget() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UZombieHUDWidget();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UZombieHUDWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UZombieHUDWidget Function SetAmmo ****************************************
struct ZombieHUDWidget_eventSetAmmo_Parms
{
	int32 Current;
	int32 Max;
};
static FName NAME_UZombieHUDWidget_SetAmmo = FName(TEXT("SetAmmo"));
void UZombieHUDWidget::SetAmmo(int32 Current, int32 Max)
{
	UFunction* Func = FindFunctionChecked(NAME_UZombieHUDWidget_SetAmmo);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ZombieHUDWidget_eventSetAmmo_Parms Parms;
		Parms.Current=Current;
		Parms.Max=Max;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		SetAmmo_Implementation(Current, Max);
	}
}
struct Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "HUD|Ammo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xed\x83\x84\xec\x95\xbd \xec\x88\x98 \xea\xb0\xb1\xec\x8b\xa0 \xe2\x80\x94 AZombieHUD\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c\n\x09 * Blueprint\xec\x97\x90\xec\x84\x9c \xec\x98\xa4\xeb\xb2\x84\xeb\x9d\xbc\xec\x9d\xb4\xeb\x93\x9c\xed\x95\xb4 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98 \xeb\x93\xb1 \xec\xb6\x94\xea\xb0\x80 \xea\xb0\x80\xeb\x8a\xa5\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/UI/ZombieHUDWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x83\x84\xec\x95\xbd \xec\x88\x98 \xea\xb0\xb1\xec\x8b\xa0 \xe2\x80\x94 AZombieHUD\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c\nBlueprint\xec\x97\x90\xec\x84\x9c \xec\x98\xa4\xeb\xb2\x84\xeb\x9d\xbc\xec\x9d\xb4\xeb\x93\x9c\xed\x95\xb4 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98 \xeb\x93\xb1 \xec\xb6\x94\xea\xb0\x80 \xea\xb0\x80\xeb\x8a\xa5" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetAmmo constinit property declarations *******************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Current;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAmmo constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAmmo Property Definitions ******************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::NewProp_Current = { "Current", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieHUDWidget_eventSetAmmo_Parms, Current), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ZombieHUDWidget_eventSetAmmo_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::NewProp_Current,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::PropPointers) < 2048);
// ********** End Function SetAmmo Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UZombieHUDWidget, nullptr, "SetAmmo", 	Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::PropPointers), 
sizeof(ZombieHUDWidget_eventSetAmmo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ZombieHUDWidget_eventSetAmmo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UZombieHUDWidget_SetAmmo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZombieHUDWidget_SetAmmo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UZombieHUDWidget::execSetAmmo)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Current);
	P_GET_PROPERTY(FIntProperty,Z_Param_Max);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAmmo_Implementation(Z_Param_Current,Z_Param_Max);
	P_NATIVE_END;
}
// ********** End Class UZombieHUDWidget Function SetAmmo ******************************************

// ********** Begin Class UZombieHUDWidget *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UZombieHUDWidget;
UClass* UZombieHUDWidget::GetPrivateStaticClass()
{
	using TClass = UZombieHUDWidget;
	if (!Z_Registration_Info_UClass_UZombieHUDWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieHUDWidget"),
			Z_Registration_Info_UClass_UZombieHUDWidget.InnerSingleton,
			StaticRegisterNativesUZombieHUDWidget,
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
	return Z_Registration_Info_UClass_UZombieHUDWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UZombieHUDWidget_NoRegister()
{
	return UZombieHUDWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UZombieHUDWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Avoid Zombie \xeb\xa9\x94\xec\x9d\xb8 HUD \xec\x9c\x84\xec\xa0\xaf\n *\n * \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8(WBP_ZombieHUD)\xec\x97\x90\xec\x84\x9c \xec\x9d\xb4 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\xa5\xbc \xeb\xb6\x80\xeb\xaa\xa8\xeb\xa1\x9c \xec\x84\xa4\xec\xa0\x95\xed\x95\x9c \xeb\x92\xa4\n * \xed\x85\x8d\xec\x8a\xa4\xed\x8a\xb8 \xeb\xb8\x94\xeb\xa1\x9d\xec\x9d\x84 CurrentAmmo / MaxAmmo \xeb\xb3\x80\xec\x88\x98\xec\x97\x90 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xed\x95\x98\xec\x84\xb8\xec\x9a\x94.\n *\n * \xed\x83\x84\xec\x95\xbd \xed\x91\x9c\xea\xb8\xb0 \xec\x98\x88: \"{CurrentAmmo} / {MaxAmmo}\"\n */" },
#endif
		{ "IncludePath", "Avoid_Zombie/UI/ZombieHUDWidget.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/UI/ZombieHUDWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Avoid Zombie \xeb\xa9\x94\xec\x9d\xb8 HUD \xec\x9c\x84\xec\xa0\xaf\n\n\xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8(WBP_ZombieHUD)\xec\x97\x90\xec\x84\x9c \xec\x9d\xb4 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\xa5\xbc \xeb\xb6\x80\xeb\xaa\xa8\xeb\xa1\x9c \xec\x84\xa4\xec\xa0\x95\xed\x95\x9c \xeb\x92\xa4\n\xed\x85\x8d\xec\x8a\xa4\xed\x8a\xb8 \xeb\xb8\x94\xeb\xa1\x9d\xec\x9d\x84 CurrentAmmo / MaxAmmo \xeb\xb3\x80\xec\x88\x98\xec\x97\x90 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xed\x95\x98\xec\x84\xb8\xec\x9a\x94.\n\n\xed\x83\x84\xec\x95\xbd \xed\x91\x9c\xea\xb8\xb0 \xec\x98\x88: \"{CurrentAmmo} / {MaxAmmo}\"" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAmmo_MetaData[] = {
		{ "Category", "HUD|Ammo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xed\x98\x84\xec\x9e\xac \xec\x9e\xa5\xed\x83\x84\xeb\x9f\x89 (Blueprint \xed\x85\x8d\xec\x8a\xa4\xed\x8a\xb8 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xec\x9a\xa9) */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/UI/ZombieHUDWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xec\x9e\xa5\xed\x83\x84\xeb\x9f\x89 (Blueprint \xed\x85\x8d\xec\x8a\xa4\xed\x8a\xb8 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xec\x9a\xa9)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmmo_MetaData[] = {
		{ "Category", "HUD|Ammo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\xb5\x9c\xeb\x8c\x80 \xed\x83\x84\xec\xb0\xbd (Blueprint \xed\x85\x8d\xec\x8a\xa4\xed\x8a\xb8 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xec\x9a\xa9) */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/UI/ZombieHUDWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb5\x9c\xeb\x8c\x80 \xed\x83\x84\xec\xb0\xbd (Blueprint \xed\x85\x8d\xec\x8a\xa4\xed\x8a\xb8 \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xec\x9a\xa9)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UZombieHUDWidget constinit property declarations *************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentAmmo;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UZombieHUDWidget constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SetAmmo"), .Pointer = &UZombieHUDWidget::execSetAmmo },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UZombieHUDWidget_SetAmmo, "SetAmmo" }, // 2942654008
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZombieHUDWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UZombieHUDWidget_Statics

// ********** Begin Class UZombieHUDWidget Property Definitions ************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UZombieHUDWidget_Statics::NewProp_CurrentAmmo = { "CurrentAmmo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UZombieHUDWidget, CurrentAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAmmo_MetaData), NewProp_CurrentAmmo_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UZombieHUDWidget_Statics::NewProp_MaxAmmo = { "MaxAmmo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UZombieHUDWidget, MaxAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmmo_MetaData), NewProp_MaxAmmo_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UZombieHUDWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZombieHUDWidget_Statics::NewProp_CurrentAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZombieHUDWidget_Statics::NewProp_MaxAmmo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieHUDWidget_Statics::PropPointers) < 2048);
// ********** End Class UZombieHUDWidget Property Definitions **************************************
UObject* (*const Z_Construct_UClass_UZombieHUDWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieHUDWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UZombieHUDWidget_Statics::ClassParams = {
	&UZombieHUDWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UZombieHUDWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UZombieHUDWidget_Statics::PropPointers),
	0,
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieHUDWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UZombieHUDWidget_Statics::Class_MetaDataParams)
};
void UZombieHUDWidget::StaticRegisterNativesUZombieHUDWidget()
{
	UClass* Class = UZombieHUDWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UZombieHUDWidget_Statics::Funcs));
}
UClass* Z_Construct_UClass_UZombieHUDWidget()
{
	if (!Z_Registration_Info_UClass_UZombieHUDWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZombieHUDWidget.OuterSingleton, Z_Construct_UClass_UZombieHUDWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UZombieHUDWidget.OuterSingleton;
}
UZombieHUDWidget::UZombieHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UZombieHUDWidget);
UZombieHUDWidget::~UZombieHUDWidget() {}
// ********** End Class UZombieHUDWidget ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUDWidget_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UZombieHUDWidget, UZombieHUDWidget::StaticClass, TEXT("UZombieHUDWidget"), &Z_Registration_Info_UClass_UZombieHUDWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZombieHUDWidget), 3756258933U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUDWidget_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUDWidget_h__Script_Avoid_Zombie_CPP_608103332{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUDWidget_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUDWidget_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
