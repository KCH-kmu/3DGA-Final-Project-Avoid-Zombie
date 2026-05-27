// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Avoid_Zombie/ZombieGameState.h"

#ifdef AVOID_ZOMBIE_CPP_ZombieGameState_generated_h
#error "ZombieGameState.generated.h already included, missing '#pragma once' in ZombieGameState.h"
#endif
#define AVOID_ZOMBIE_CPP_ZombieGameState_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZombieGameState *********************************************************
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execTriggerGameOver); \
	DECLARE_FUNCTION(execAddBonusScore); \
	DECLARE_FUNCTION(execAddWaveClearScore); \
	DECLARE_FUNCTION(execAddKillScore);


struct Z_Construct_UClass_AZombieGameState_Statics;
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieGameState_NoRegister();

#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombieGameState(); \
	friend struct ::Z_Construct_UClass_AZombieGameState_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AVOID_ZOMBIE_CPP_API UClass* ::Z_Construct_UClass_AZombieGameState_NoRegister(); \
public: \
	DECLARE_CLASS2(AZombieGameState, AGameStateBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Avoid_Zombie_CPP"), Z_Construct_UClass_AZombieGameState_NoRegister) \
	DECLARE_SERIALIZER(AZombieGameState)


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZombieGameState(AZombieGameState&&) = delete; \
	AZombieGameState(const AZombieGameState&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieGameState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieGameState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZombieGameState) \
	NO_API virtual ~AZombieGameState();


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h_12_PROLOG
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h_15_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZombieGameState;

// ********** End Class AZombieGameState ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieGameState_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
