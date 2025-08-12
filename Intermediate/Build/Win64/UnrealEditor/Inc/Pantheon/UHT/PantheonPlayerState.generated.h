// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonPlayerState.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APantheonPlayerState;
class APawn;
class APlayerController;
#ifdef PANTHEON_PantheonPlayerState_generated_h
#error "PantheonPlayerState.generated.h already included, missing '#pragma once' in PantheonPlayerState.h"
#endif
#define PANTHEON_PantheonPlayerState_generated_h

#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_15_DELEGATE \
PANTHEON_API void FOnCharacterSelectedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterSelectedSignature, APlayerController* SelectingPC);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_20_DELEGATE \
PANTHEON_API void FOnReadyChanged_DelegateWrapper(const FMulticastScriptDelegate& OnReadyChanged, APantheonPlayerState* PlayerState, bool bNowReady);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_IsReady); \
	DECLARE_FUNCTION(execGetChosenPawnClassForRole); \
	DECLARE_FUNCTION(execSetReady); \
	DECLARE_FUNCTION(execIsReady);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPantheonPlayerState(); \
	friend struct Z_Construct_UClass_APantheonPlayerState_Statics; \
public: \
	DECLARE_CLASS(APantheonPlayerState, APlayerState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Pantheon"), NO_API) \
	DECLARE_SERIALIZER(APantheonPlayerState) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		SelectedPawnClass=NETFIELD_REP_START, \
		ChosenRole, \
		bIsBot, \
		SurvivorRowKey, \
		KillerRowKey, \
		bIsReady, \
		NETFIELD_REP_END=bIsReady	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APantheonPlayerState(APantheonPlayerState&&); \
	APantheonPlayerState(const APantheonPlayerState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APantheonPlayerState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APantheonPlayerState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APantheonPlayerState) \
	NO_API virtual ~APantheonPlayerState();


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_23_PROLOG
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_26_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PANTHEON_API UClass* StaticClass<class APantheonPlayerState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonPlayerState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
