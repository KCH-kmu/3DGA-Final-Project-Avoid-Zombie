// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Avoid_Zombie/ZombieCharacter.h"

#ifdef AVOID_ZOMBIE_CPP_ZombieCharacter_generated_h
#error "ZombieCharacter.generated.h already included, missing '#pragma once' in ZombieCharacter.h"
#endif
#define AVOID_ZOMBIE_CPP_ZombieCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZombieCharacter *********************************************************
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnDeath); \
	DECLARE_FUNCTION(execIsDead); \
	DECLARE_FUNCTION(execIsPlayerInAttackRange); \
	DECLARE_FUNCTION(execApplyStun); \
	DECLARE_FUNCTION(execOnAttackEnd); \
	DECLARE_FUNCTION(execOnAttackHit); \
	DECLARE_FUNCTION(execStartAttack); \
	DECLARE_FUNCTION(execTakeDamageAmount);


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_20_CALLBACK_WRAPPERS
struct Z_Construct_UClass_AZombieCharacter_Statics;
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombieCharacter_NoRegister();

#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombieCharacter(); \
	friend struct ::Z_Construct_UClass_AZombieCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AVOID_ZOMBIE_CPP_API UClass* ::Z_Construct_UClass_AZombieCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AZombieCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Avoid_Zombie_CPP"), Z_Construct_UClass_AZombieCharacter_NoRegister) \
	DECLARE_SERIALIZER(AZombieCharacter)


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZombieCharacter(AZombieCharacter&&) = delete; \
	AZombieCharacter(const AZombieCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZombieCharacter) \
	NO_API virtual ~AZombieCharacter();


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_17_PROLOG
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_20_CALLBACK_WRAPPERS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_20_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZombieCharacter;

// ********** End Class AZombieCharacter ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombieCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
