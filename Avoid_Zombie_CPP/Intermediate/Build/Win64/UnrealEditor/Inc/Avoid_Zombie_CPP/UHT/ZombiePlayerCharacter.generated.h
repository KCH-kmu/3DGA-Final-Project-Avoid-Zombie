// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Avoid_Zombie/ZombiePlayerCharacter.h"

#ifdef AVOID_ZOMBIE_CPP_ZombiePlayerCharacter_generated_h
#error "ZombiePlayerCharacter.generated.h already included, missing '#pragma once' in ZombiePlayerCharacter.h"
#endif
#define AVOID_ZOMBIE_CPP_ZombiePlayerCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZombiePlayerCharacter ***************************************************
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnDeath); \
	DECLARE_FUNCTION(execIsDead); \
	DECLARE_FUNCTION(execHealHealth); \
	DECLARE_FUNCTION(execTakeDamageAmount);


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_28_CALLBACK_WRAPPERS
struct Z_Construct_UClass_AZombiePlayerCharacter_Statics;
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AZombiePlayerCharacter_NoRegister();

#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombiePlayerCharacter(); \
	friend struct ::Z_Construct_UClass_AZombiePlayerCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AVOID_ZOMBIE_CPP_API UClass* ::Z_Construct_UClass_AZombiePlayerCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AZombiePlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Avoid_Zombie_CPP"), Z_Construct_UClass_AZombiePlayerCharacter_NoRegister) \
	DECLARE_SERIALIZER(AZombiePlayerCharacter)


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_28_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZombiePlayerCharacter(AZombiePlayerCharacter&&) = delete; \
	AZombiePlayerCharacter(const AZombiePlayerCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombiePlayerCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombiePlayerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZombiePlayerCharacter) \
	NO_API virtual ~AZombiePlayerCharacter();


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_25_PROLOG
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_28_CALLBACK_WRAPPERS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_28_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZombiePlayerCharacter;

// ********** End Class AZombiePlayerCharacter *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ZombiePlayerCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
