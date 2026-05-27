// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Avoid_Zombie/ScoreManager.h"

#ifdef AVOID_ZOMBIE_CPP_ScoreManager_generated_h
#error "ScoreManager.generated.h already included, missing '#pragma once' in ScoreManager.h"
#endif
#define AVOID_ZOMBIE_CPP_ScoreManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameOverData;

// ********** Begin ScriptStruct FGameOverData *****************************************************
struct Z_Construct_UScriptStruct_FGameOverData_Statics;
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h_12_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGameOverData_Statics; \
	AVOID_ZOMBIE_CPP_API static class UScriptStruct* StaticStruct();


struct FGameOverData;
// ********** End ScriptStruct FGameOverData *******************************************************

// ********** Begin Class UScoreManager ************************************************************
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execBuildGameOverData); \
	DECLARE_FUNCTION(execOnWaveClear); \
	DECLARE_FUNCTION(execOnKill);


struct Z_Construct_UClass_UScoreManager_Statics;
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_UScoreManager_NoRegister();

#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUScoreManager(); \
	friend struct ::Z_Construct_UClass_UScoreManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AVOID_ZOMBIE_CPP_API UClass* ::Z_Construct_UClass_UScoreManager_NoRegister(); \
public: \
	DECLARE_CLASS2(UScoreManager, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Avoid_Zombie_CPP"), Z_Construct_UClass_UScoreManager_NoRegister) \
	DECLARE_SERIALIZER(UScoreManager)


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h_29_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UScoreManager(UScoreManager&&) = delete; \
	UScoreManager(const UScoreManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UScoreManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UScoreManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UScoreManager) \
	NO_API virtual ~UScoreManager();


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h_26_PROLOG
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h_29_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UScoreManager;

// ********** End Class UScoreManager **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ScoreManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
