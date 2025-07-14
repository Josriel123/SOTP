// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "F13PlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
#ifdef F13_F13PlayerController_generated_h
#error "F13PlayerController.generated.h already included, missing '#pragma once' in F13PlayerController.h"
#endif
#define F13_F13PlayerController_generated_h

#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerSetReady_Validate(bool ); \
	virtual void ServerSetReady_Implementation(bool bNewReady); \
	virtual bool ServerSelectPawnClass_Validate(TSubclassOf<APawn> ); \
	virtual void ServerSelectPawnClass_Implementation(TSubclassOf<APawn> PawnClass); \
	DECLARE_FUNCTION(execServerSetReady); \
	DECLARE_FUNCTION(execServerSelectPawnClass);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_17_CALLBACK_WRAPPERS
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAF13PlayerController(); \
	friend struct Z_Construct_UClass_AF13PlayerController_Statics; \
public: \
	DECLARE_CLASS(AF13PlayerController, AHMS_PlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/F13"), NO_API) \
	DECLARE_SERIALIZER(AF13PlayerController)


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AF13PlayerController(AF13PlayerController&&); \
	AF13PlayerController(const AF13PlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AF13PlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AF13PlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AF13PlayerController) \
	NO_API virtual ~AF13PlayerController();


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_14_PROLOG
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_17_CALLBACK_WRAPPERS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_17_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> F13_API UClass* StaticClass<class AF13PlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
