// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Avoid_Zombie/UI/ZombieHUD.h"

#ifdef AVOID_ZOMBIE_CPP_ZombieHUD_generated_h
#error "ZombieHUD.generated.h already included, missing '#pragma once' in ZombieHUD.h"
#endif
#define AVOID_ZOMBIE_CPP_ZombieHUD_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZombieHUD ***************************************************************
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnAmmoChanged);


struct Z_Construct_UClass_AZombieHUD_Statics;
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieHUD_NoRegister();

#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombieHUD(); \
	friend struct ::Z_Construct_UClass_AZombieHUD_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AVOID_ZOMBIE_CPP_API UClass* ::Z_Construct_UClass_AZombieHUD_NoRegister(); \
public: \
	DECLARE_CLASS2(AZombieHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Avoid_Zombie_CPP"), Z_Construct_UClass_AZombieHUD_NoRegister) \
	DECLARE_SERIALIZER(AZombieHUD)


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZombieHUD(AZombieHUD&&) = delete; \
	AZombieHUD(const AZombieHUD&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZombieHUD) \
	NO_API virtual ~AZombieHUD();


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h_21_PROLOG
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h_24_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZombieHUD;

// ********** End Class AZombieHUD *****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_UI_ZombieHUD_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
