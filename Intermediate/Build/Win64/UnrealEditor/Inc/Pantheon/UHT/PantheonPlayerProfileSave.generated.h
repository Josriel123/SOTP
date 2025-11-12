// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonPlayerProfileSave.h"

#ifdef PANTHEON_PantheonPlayerProfileSave_generated_h
#error "PantheonPlayerProfileSave.generated.h already included, missing '#pragma once' in PantheonPlayerProfileSave.h"
#endif
#define PANTHEON_PantheonPlayerProfileSave_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FPlayerProfileData ************************************************
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h_11_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlayerProfileData_Statics; \
	PANTHEON_API static class UScriptStruct* StaticStruct();


struct FPlayerProfileData;
// ********** End ScriptStruct FPlayerProfileData **************************************************

// ********** Begin Class UPantheonPlayerProfileSave ***********************************************
PANTHEON_API UClass* Z_Construct_UClass_UPantheonPlayerProfileSave_NoRegister();

#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPantheonPlayerProfileSave(); \
	friend struct Z_Construct_UClass_UPantheonPlayerProfileSave_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PANTHEON_API UClass* Z_Construct_UClass_UPantheonPlayerProfileSave_NoRegister(); \
public: \
	DECLARE_CLASS2(UPantheonPlayerProfileSave, USaveGame, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Pantheon"), Z_Construct_UClass_UPantheonPlayerProfileSave_NoRegister) \
	DECLARE_SERIALIZER(UPantheonPlayerProfileSave)


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPantheonPlayerProfileSave(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPantheonPlayerProfileSave(UPantheonPlayerProfileSave&&) = delete; \
	UPantheonPlayerProfileSave(const UPantheonPlayerProfileSave&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPantheonPlayerProfileSave); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPantheonPlayerProfileSave); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPantheonPlayerProfileSave) \
	NO_API virtual ~UPantheonPlayerProfileSave();


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h_17_PROLOG
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h_20_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPantheonPlayerProfileSave;

// ********** End Class UPantheonPlayerProfileSave *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
