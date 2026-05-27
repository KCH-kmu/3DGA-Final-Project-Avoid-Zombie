// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Avoid_Zombie/WaveManager.h"

#ifdef AVOID_ZOMBIE_CPP_WaveManager_generated_h
#error "WaveManager.generated.h already included, missing '#pragma once' in WaveManager.h"
#endif
#define AVOID_ZOMBIE_CPP_WaveManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AWaveManager *************************************************************
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnZombieDead); \
	DECLARE_FUNCTION(execStopWave);


struct Z_Construct_UClass_AWaveManager_Statics;
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AWaveManager_NoRegister();

#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWaveManager(); \
	friend struct ::Z_Construct_UClass_AWaveManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AVOID_ZOMBIE_CPP_API UClass* ::Z_Construct_UClass_AWaveManager_NoRegister(); \
public: \
	DECLARE_CLASS2(AWaveManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Avoid_Zombie_CPP"), Z_Construct_UClass_AWaveManager_NoRegister) \
	DECLARE_SERIALIZER(AWaveManager)


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h_23_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AWaveManager(AWaveManager&&) = delete; \
	AWaveManager(const AWaveManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWaveManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWaveManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWaveManager) \
	NO_API virtual ~AWaveManager();


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h_20_PROLOG
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h_23_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AWaveManager;

// ********** End Class AWaveManager ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_WaveManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
