// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAvoid_Zombie_CPP_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	AVOID_ZOMBIE_CPP_API UFunction* Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Avoid_Zombie_CPP;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Avoid_Zombie_CPP()
	{
		if (!Z_Registration_Info_UPackage__Script_Avoid_Zombie_CPP.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_Avoid_Zombie_CPP_OnEnemyDied__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/Avoid_Zombie_CPP",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x60133512,
			0x19BCECAA,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Avoid_Zombie_CPP.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_Avoid_Zombie_CPP.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Avoid_Zombie_CPP(Z_Construct_UPackage__Script_Avoid_Zombie_CPP, TEXT("/Script/Avoid_Zombie_CPP"), Z_Registration_Info_UPackage__Script_Avoid_Zombie_CPP, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x60133512, 0x19BCECAA));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
