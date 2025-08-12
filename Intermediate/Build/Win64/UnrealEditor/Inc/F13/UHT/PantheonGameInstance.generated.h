// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonGameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef F13_PantheonGameInstance_generated_h
#error "PantheonGameInstance.generated.h already included, missing '#pragma once' in PantheonGameInstance.h"
#endif
#define F13_PantheonGameInstance_generated_h

#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_14_DELEGATE \
F13_API void FOnSessionJoined_DelegateWrapper(const FMulticastScriptDelegate& OnSessionJoined, bool bWasSuccessful);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_15_DELEGATE \
F13_API void FOnSessionCreated_DelegateWrapper(const FMulticastScriptDelegate& OnSessionCreated, bool bWasSuccessful);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_16_DELEGATE \
F13_API void FOnSessionListReady_DelegateWrapper(const FMulticastScriptDelegate& OnSessionListReady, TArray<FString> const& FoundNames);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetFoundSessionNames); \
	DECLARE_FUNCTION(execJoinFoundSession); \
	DECLARE_FUNCTION(execFindSessions); \
	DECLARE_FUNCTION(execHostAndStartSession);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPantheonGameInstance(); \
	friend struct Z_Construct_UClass_UPantheonGameInstance_Statics; \
public: \
	DECLARE_CLASS(UPantheonGameInstance, UHMS_GameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/F13"), NO_API) \
	DECLARE_SERIALIZER(UPantheonGameInstance)


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UPantheonGameInstance(UPantheonGameInstance&&); \
	UPantheonGameInstance(const UPantheonGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPantheonGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPantheonGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPantheonGameInstance) \
	NO_API virtual ~UPantheonGameInstance();


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_18_PROLOG
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_21_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> F13_API UClass* StaticClass<class UPantheonGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
