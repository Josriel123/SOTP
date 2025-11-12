// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonGameInstance.h"

#ifdef PANTHEON_PantheonGameInstance_generated_h
#error "PantheonGameInstance.generated.h already included, missing '#pragma once' in PantheonGameInstance.h"
#endif
#define PANTHEON_PantheonGameInstance_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Delegate FOnSessionJoined ******************************************************
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_14_DELEGATE \
PANTHEON_API void FOnSessionJoined_DelegateWrapper(const FMulticastScriptDelegate& OnSessionJoined, bool bWasSuccessful);


// ********** End Delegate FOnSessionJoined ********************************************************

// ********** Begin Delegate FOnSessionCreated *****************************************************
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_15_DELEGATE \
PANTHEON_API void FOnSessionCreated_DelegateWrapper(const FMulticastScriptDelegate& OnSessionCreated, bool bWasSuccessful);


// ********** End Delegate FOnSessionCreated *******************************************************

// ********** Begin Delegate FOnSessionListReady ***************************************************
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_16_DELEGATE \
PANTHEON_API void FOnSessionListReady_DelegateWrapper(const FMulticastScriptDelegate& OnSessionListReady, TArray<FString> const& FoundNames);


// ********** End Delegate FOnSessionListReady *****************************************************

// ********** Begin Class UPantheonGameInstance ****************************************************
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetFoundSessionNames); \
	DECLARE_FUNCTION(execJoinFoundSession); \
	DECLARE_FUNCTION(execFindSessions);


PANTHEON_API UClass* Z_Construct_UClass_UPantheonGameInstance_NoRegister();

#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPantheonGameInstance(); \
	friend struct Z_Construct_UClass_UPantheonGameInstance_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PANTHEON_API UClass* Z_Construct_UClass_UPantheonGameInstance_NoRegister(); \
public: \
	DECLARE_CLASS2(UPantheonGameInstance, UHMS_GameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Pantheon"), Z_Construct_UClass_UPantheonGameInstance_NoRegister) \
	DECLARE_SERIALIZER(UPantheonGameInstance)


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_21_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPantheonGameInstance(UPantheonGameInstance&&) = delete; \
	UPantheonGameInstance(const UPantheonGameInstance&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPantheonGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPantheonGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPantheonGameInstance) \
	NO_API virtual ~UPantheonGameInstance();


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_18_PROLOG
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_21_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPantheonGameInstance;

// ********** End Class UPantheonGameInstance ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameInstance_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
