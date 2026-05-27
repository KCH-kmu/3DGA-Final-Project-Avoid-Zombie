// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ItemBox.h"
#include "Engine/HitResult.h"
#include "UObject/Class.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeItemBox() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AItemBox();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AItemBox_NoRegister();
AVOID_ZOMBIE_CPP_API UEnum* Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AItemBox Function OnOverlapBegin *****************************************
struct Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics
{
	struct ItemBox_eventOnOverlapBegin_Parms
	{
		UPrimitiveComponent* OverlappedComp;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Avoid_Zombie/ItemBox.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnOverlapBegin constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnOverlapBegin constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnOverlapBegin Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemBox_eventOnOverlapBegin_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComp_MetaData), NewProp_OverlappedComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemBox_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemBox_eventOnOverlapBegin_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemBox_eventOnOverlapBegin_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((ItemBox_eventOnOverlapBegin_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ItemBox_eventOnOverlapBegin_Parms), &Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemBox_eventOnOverlapBegin_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 222120718
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_OverlappedComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::PropPointers) < 2048);
// ********** End Function OnOverlapBegin Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AItemBox, nullptr, "OnOverlapBegin", 	Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::ItemBox_eventOnOverlapBegin_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::ItemBox_eventOnOverlapBegin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AItemBox_OnOverlapBegin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AItemBox_OnOverlapBegin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AItemBox::execOnOverlapBegin)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class AItemBox Function OnOverlapBegin *******************************************

// ********** Begin Class AItemBox Function SpawnItemBox *******************************************
struct Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics
{
	struct ItemBox_eventSpawnItemBox_Parms
	{
		UObject* WorldContextObject;
		TSubclassOf<AItemBox> BoxClass;
		TArray<AActor*> SpawnPoints;
		AItemBox* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ItemBox" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\x9e\x9c\xeb\x8d\xa4 \xec\x9c\x84\xec\xb9\x98\xec\x97\x90 ItemBox \xec\x8a\xa4\xed\x8f\xb0 (\xec\x9d\xb4\xeb\xaf\xb8 \xec\x9e\x88\xec\x9c\xbc\xeb\xa9\xb4 \xec\x8a\xa4\xed\x82\xb5) */" },
#endif
		{ "ModuleRelativePath", "Avoid_Zombie/ItemBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x9e\x9c\xeb\x8d\xa4 \xec\x9c\x84\xec\xb9\x98\xec\x97\x90 ItemBox \xec\x8a\xa4\xed\x8f\xb0 (\xec\x9d\xb4\xeb\xaf\xb8 \xec\x9e\x88\xec\x9c\xbc\xeb\xa9\xb4 \xec\x8a\xa4\xed\x82\xb5)" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnPoints_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SpawnItemBox constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_BoxClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnPoints_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpawnPoints;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SpawnItemBox constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SpawnItemBox Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemBox_eventSpawnItemBox_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_BoxClass = { "BoxClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemBox_eventSpawnItemBox_Parms, BoxClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AItemBox_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_SpawnPoints_Inner = { "SpawnPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_SpawnPoints = { "SpawnPoints", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemBox_eventSpawnItemBox_Parms, SpawnPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnPoints_MetaData), NewProp_SpawnPoints_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ItemBox_eventSpawnItemBox_Parms, ReturnValue), Z_Construct_UClass_AItemBox_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_BoxClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_SpawnPoints_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_SpawnPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::PropPointers) < 2048);
// ********** End Function SpawnItemBox Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AItemBox, nullptr, "SpawnItemBox", 	Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::ItemBox_eventSpawnItemBox_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::ItemBox_eventSpawnItemBox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AItemBox_SpawnItemBox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AItemBox_SpawnItemBox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AItemBox::execSpawnItemBox)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_BoxClass);
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_SpawnPoints);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AItemBox**)Z_Param__Result=AItemBox::SpawnItemBox(Z_Param_WorldContextObject,Z_Param_BoxClass,Z_Param_Out_SpawnPoints);
	P_NATIVE_END;
}
// ********** End Class AItemBox Function SpawnItemBox *********************************************

// ********** Begin Class AItemBox *****************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AItemBox;
UClass* AItemBox::GetPrivateStaticClass()
{
	using TClass = AItemBox;
	if (!Z_Registration_Info_UClass_AItemBox.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ItemBox"),
			Z_Registration_Info_UClass_AItemBox.InnerSingleton,
			StaticRegisterNativesAItemBox,
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
	return Z_Registration_Info_UClass_AItemBox.InnerSingleton;
}
UClass* Z_Construct_UClass_AItemBox_NoRegister()
{
	return AItemBox::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AItemBox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xeb\xb0\x95\xec\x8a\xa4 (?\xec\x83\x81\xec\x9e\x90)\n * - \xeb\xa7\xb5\xec\x97\x90 \xed\x95\x98\xeb\x82\x98\xeb\xa7\x8c \xec\xa1\xb4\xec\x9e\xac\n * - \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x98\xa4\xeb\xb2\x84\xeb\x9e\xa9 \xec\x8b\x9c \xec\x88\x98\xeb\xa0\xb9\n * - \xec\x9d\xb4\xeb\xaf\xb8 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xeb\xb3\xb4\xec\x9c\xa0 \xec\xa4\x91\xec\x9d\xb4\xeb\xa9\xb4 \xeb\xac\xb4\xec\x8b\x9c\n * - 3\xec\xa2\x85\xeb\xa5\x98 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xeb\x9e\x9c\xeb\x8d\xa4 \xec\xa7\x80\xea\xb8\x89\n */" },
#endif
		{ "IncludePath", "Avoid_Zombie/ItemBox.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/ItemBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xeb\xb0\x95\xec\x8a\xa4 (?\xec\x83\x81\xec\x9e\x90)\n- \xeb\xa7\xb5\xec\x97\x90 \xed\x95\x98\xeb\x82\x98\xeb\xa7\x8c \xec\xa1\xb4\xec\x9e\xac\n- \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x98\xa4\xeb\xb2\x84\xeb\x9e\xa9 \xec\x8b\x9c \xec\x88\x98\xeb\xa0\xb9\n- \xec\x9d\xb4\xeb\xaf\xb8 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xeb\xb3\xb4\xec\x9c\xa0 \xec\xa4\x91\xec\x9d\xb4\xeb\xa9\xb4 \xeb\xac\xb4\xec\x8b\x9c\n- 3\xec\xa2\x85\xeb\xa5\x98 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xeb\x9e\x9c\xeb\x8d\xa4 \xec\xa7\x80\xea\xb8\x89" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoxMesh_MetaData[] = {
		{ "Category", "ItemBox" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Avoid_Zombie/ItemBox.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlapSphere_MetaData[] = {
		{ "Category", "ItemBox" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Avoid_Zombie/ItemBox.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContainedItem_MetaData[] = {
		{ "Category", "ItemBox" },
		{ "ModuleRelativePath", "Avoid_Zombie/ItemBox.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AItemBox constinit property declarations *********************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoxMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlapSphere;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ContainedItem_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ContainedItem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AItemBox constinit property declarations ***********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnOverlapBegin"), .Pointer = &AItemBox::execOnOverlapBegin },
		{ .NameUTF8 = UTF8TEXT("SpawnItemBox"), .Pointer = &AItemBox::execSpawnItemBox },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AItemBox_OnOverlapBegin, "OnOverlapBegin" }, // 1830184203
		{ &Z_Construct_UFunction_AItemBox_SpawnItemBox, "SpawnItemBox" }, // 2120658214
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AItemBox>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AItemBox_Statics

// ********** Begin Class AItemBox Property Definitions ********************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItemBox_Statics::NewProp_BoxMesh = { "BoxMesh", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AItemBox, BoxMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoxMesh_MetaData), NewProp_BoxMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItemBox_Statics::NewProp_OverlapSphere = { "OverlapSphere", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AItemBox, OverlapSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlapSphere_MetaData), NewProp_OverlapSphere_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AItemBox_Statics::NewProp_ContainedItem_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AItemBox_Statics::NewProp_ContainedItem = { "ContainedItem", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AItemBox, ContainedItem), Z_Construct_UEnum_Avoid_Zombie_CPP_EItemType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContainedItem_MetaData), NewProp_ContainedItem_MetaData) }; // 2004411603
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AItemBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemBox_Statics::NewProp_BoxMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemBox_Statics::NewProp_OverlapSphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemBox_Statics::NewProp_ContainedItem_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemBox_Statics::NewProp_ContainedItem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AItemBox_Statics::PropPointers) < 2048);
// ********** End Class AItemBox Property Definitions **********************************************
UObject* (*const Z_Construct_UClass_AItemBox_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AItemBox_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AItemBox_Statics::ClassParams = {
	&AItemBox::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AItemBox_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AItemBox_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AItemBox_Statics::Class_MetaDataParams), Z_Construct_UClass_AItemBox_Statics::Class_MetaDataParams)
};
void AItemBox::StaticRegisterNativesAItemBox()
{
	UClass* Class = AItemBox::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AItemBox_Statics::Funcs));
}
UClass* Z_Construct_UClass_AItemBox()
{
	if (!Z_Registration_Info_UClass_AItemBox.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AItemBox.OuterSingleton, Z_Construct_UClass_AItemBox_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AItemBox.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AItemBox);
AItemBox::~AItemBox() {}
// ********** End Class AItemBox *******************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AItemBox, AItemBox::StaticClass, TEXT("AItemBox"), &Z_Registration_Info_UClass_AItemBox, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AItemBox), 20660267U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h__Script_Avoid_Zombie_CPP_1358701515{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
