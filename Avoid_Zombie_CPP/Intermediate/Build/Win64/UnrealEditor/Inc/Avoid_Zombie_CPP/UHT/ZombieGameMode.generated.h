// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Avoid_Zombie/ZombieGameMode.h"

#ifdef AVOID_ZOMBIE_CPP_ZombieGameMode_generated_h
#error "ZombieGameMode.generated.h already included, missing '#pragma once' in ZombieGameMode.h"
#endif
#define AVOID_ZOMBIE_CPP_ZombieGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZombieGameMode **********************************************************
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnPlayerDead);


struct Z_Construct_UClass_AZombieGameMode_Statics;
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieGameMode_NoRegister();

#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombieGameMode(); \
	friend struct ::Z_Construct_UClass_AZombieGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AVOID_ZOMBIE_CPP_API UClass* ::Z_Construct_UClass_AZombieGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AZombieGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Avoid_Zombie_CPP"), Z_Construct_UClass_AZombieGameMode_NoRegister) \
	DECLARE_SERIALIZER(AZombieGameMode)


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h_19_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZombieGameMode(AZombieGameMode&&) = delete; \
	AZombieGameMode(const AZombieGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZombieGameMode) \
	NO_API virtual ~AZombieGameMode();


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h_16_PROLOG
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h_19_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZombieGameMode;

// ********** End Class AZombieGameMode ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
