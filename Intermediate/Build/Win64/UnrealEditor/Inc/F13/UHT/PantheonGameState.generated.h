// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonGameState.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef F13_PantheonGameState_generated_h
#error "PantheonGameState.generated.h already included, missing '#pragma once' in PantheonGameState.h"
#endif
#define F13_PantheonGameState_generated_h

#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_9_DELEGATE \
F13_API void FOnPlayersChanged_DelegateWrapper(const FMulticastScriptDelegate& OnPlayersChanged);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPantheonGameState(); \
	friend struct Z_Construct_UClass_APantheonGameState_Statics; \
public: \
	DECLARE_CLASS(APantheonGameState, AGameState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/F13"), NO_API) \
	DECLARE_SERIALIZER(APantheonGameState)


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APantheonGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APantheonGameState(APantheonGameState&&); \
	APantheonGameState(const APantheonGameState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APantheonGameState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APantheonGameState); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APantheonGameState) \
	NO_API virtual ~APantheonGameState();


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_11_PROLOG
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> F13_API UClass* StaticClass<class APantheonGameState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
