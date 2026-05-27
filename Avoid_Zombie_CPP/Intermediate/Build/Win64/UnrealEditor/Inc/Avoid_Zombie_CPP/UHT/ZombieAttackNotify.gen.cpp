// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZombieAttackNotify.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZombieAttackNotify() {}

// ********** Begin Cross Module References ********************************************************
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UZombieAttackNotify();
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UZombieAttackNotify_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UZombieAttackNotify ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UZombieAttackNotify;
UClass* UZombieAttackNotify::GetPrivateStaticClass()
{
	using TClass = UZombieAttackNotify;
	if (!Z_Registration_Info_UClass_UZombieAttackNotify.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZombieAttackNotify"),
			Z_Registration_Info_UClass_UZombieAttackNotify.InnerSingleton,
			StaticRegisterNativesUZombieAttackNotify,
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
	return Z_Registration_Info_UClass_UZombieAttackNotify.InnerSingleton;
}
UClass* Z_Construct_UClass_UZombieAttackNotify_NoRegister()
{
	return UZombieAttackNotify::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UZombieAttackNotify_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xec\xa2\x80\xeb\xb9\x84 \xea\xb3\xb5\xea\xb2\xa9 \xed\x9e\x88\xed\x8a\xb8 \xed\x8c\x90\xec\xa0\x95 AnimNotify\n * Attack2 \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc\xec\x9d\x98 21\xed\x94\x84\xeb\xa0\x88\xec\x9e\x84 \xec\x9c\x84\xec\xb9\x98\xec\x97\x90 \xeb\xb0\xb0\xec\xb9\x98.\n * \xe2\x86\x92 ZombieCharacter::OnAttackHit() \xed\x98\xb8\xec\xb6\x9c\n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "Avoid_Zombie/ZombieAttackNotify.h" },
		{ "ModuleRelativePath", "Avoid_Zombie/ZombieAttackNotify.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa2\x80\xeb\xb9\x84 \xea\xb3\xb5\xea\xb2\xa9 \xed\x9e\x88\xed\x8a\xb8 \xed\x8c\x90\xec\xa0\x95 AnimNotify\nAttack2 \xeb\xaa\xbd\xed\x83\x80\xec\xa3\xbc\xec\x9d\x98 21\xed\x94\x84\xeb\xa0\x88\xec\x9e\x84 \xec\x9c\x84\xec\xb9\x98\xec\x97\x90 \xeb\xb0\xb0\xec\xb9\x98.\n\xe2\x86\x92 ZombieCharacter::OnAttackHit() \xed\x98\xb8\xec\xb6\x9c" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UZombieAttackNotify constinit property declarations **********************
// ********** End Class UZombieAttackNotify constinit property declarations ************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZombieAttackNotify>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UZombieAttackNotify_Statics
UObject* (*const Z_Construct_UClass_UZombieAttackNotify_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimNotify,
	(UObject* (*)())Z_Construct_UPackage__Script_Avoid_Zombie_CPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAttackNotify_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UZombieAttackNotify_Statics::ClassParams = {
	&UZombieAttackNotify::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001120A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UZombieAttackNotify_Statics::Class_MetaDataParams), Z_Construct_UClass_UZombieAttackNotify_Statics::Class_MetaDataParams)
};
void UZombieAttackNotify::StaticRegisterNativesUZombieAttackNotify()
{
}
UClass* Z_Construct_UClass_UZombieAttackNotify()
{
	if (!Z_Registration_Info_UClass_UZombieAttackNotify.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZombieAttackNotify.OuterSingleton, Z_Construct_UClass_UZombieAttackNotify_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UZombieAttackNotify.OuterSingleton;
}
UZombieAttackNotify::UZombieAttackNotify(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UZombieAttackNotify);
UZombieAttackNotify::~UZombieAttackNotify() {}
// ********** End Class UZombieAttackNotify ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAttackNotify_h__Script_Avoid_Zombie_CPP_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UZombieAttackNotify, UZombieAttackNotify::StaticClass, TEXT("UZombieAttackNotify"), &Z_Registration_Info_UClass_UZombieAttackNotify, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZombieAttackNotify), 802903646U) },
	};
}; // Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAttackNotify_h__Script_Avoid_Zombie_CPP_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAttackNotify_h__Script_Avoid_Zombie_CPP_1799282222{
	TEXT("/Script/Avoid_Zombie_CPP"),
	Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAttackNotify_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieAttackNotify_h__Script_Avoid_Zombie_CPP_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
