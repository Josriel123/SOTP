// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FPlayerProfileData;
#ifdef F13_PantheonPlayerController_generated_h
#error "PantheonPlayerController.generated.h already included, missing '#pragma once' in PantheonPlayerController.h"
#endif
#define F13_PantheonPlayerController_generated_h

#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Client_SaveLocalProfile_Implementation(FPlayerProfileData const& InProfile); \
	virtual bool ServerSetCharacterPreference_Validate(FName , const FString& ); \
	virtual void ServerSetCharacterPreference_Implementation(FName RowKey, const FString& InRole); \
	virtual bool ServerSetReady_Validate(bool ); \
	virtual void ServerSetReady_Implementation(bool bNewReady); \
	DECLARE_FUNCTION(execClient_SaveLocalProfile); \
	DECLARE_FUNCTION(execServerSetCharacterPreference); \
	DECLARE_FUNCTION(execServerSetReady);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_18_CALLBACK_WRAPPERS
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPantheonPlayerController(); \
	friend struct Z_Construct_UClass_APantheonPlayerController_Statics; \
public: \
	DECLARE_CLASS(APantheonPlayerController, AHMS_PlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/F13"), NO_API) \
	DECLARE_SERIALIZER(APantheonPlayerController)


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APantheonPlayerController(APantheonPlayerController&&); \
	APantheonPlayerController(const APantheonPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APantheonPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APantheonPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APantheonPlayerController) \
	NO_API virtual ~APantheonPlayerController();


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_15_PROLOG
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_18_CALLBACK_WRAPPERS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> F13_API UClass* StaticClass<class APantheonPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
