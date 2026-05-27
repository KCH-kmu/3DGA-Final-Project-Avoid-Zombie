// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Avoid_Zombie/ItemBox.h"

#ifdef AVOID_ZOMBIE_CPP_ItemBox_generated_h
#error "ItemBox.generated.h already included, missing '#pragma once' in ItemBox.h"
#endif
#define AVOID_ZOMBIE_CPP_ItemBox_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AItemBox;
class UClass;
class UObject;
class UPrimitiveComponent;
struct FHitResult;

// ********** Begin Class AItemBox *****************************************************************
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnOverlapBegin); \
	DECLARE_FUNCTION(execSpawnItemBox);


struct Z_Construct_UClass_AItemBox_Statics;
AVOID_ZOMBIE_CPP_API UClass* Z_Construct_UClass_AItemBox_NoRegister();

#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAItemBox(); \
	friend struct ::Z_Construct_UClass_AItemBox_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AVOID_ZOMBIE_CPP_API UClass* ::Z_Construct_UClass_AItemBox_NoRegister(); \
public: \
	DECLARE_CLASS2(AItemBox, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Avoid_Zombie_CPP"), Z_Construct_UClass_AItemBox_NoRegister) \
	DECLARE_SERIALIZER(AItemBox)


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h_22_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AItemBox(AItemBox&&) = delete; \
	AItemBox(const AItemBox&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItemBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItemBox); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AItemBox) \
	NO_API virtual ~AItemBox();


#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h_19_PROLOG
#define FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h_22_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AItemBox;

// ********** End Class AItemBox *******************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Cpp_Project_Avoid_Zombie_CPP_Source_Avoid_Zombie_CPP_Avoid_Zombie_ItemBox_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
