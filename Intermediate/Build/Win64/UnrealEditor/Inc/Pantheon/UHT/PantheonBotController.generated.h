// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonBotController.h"

#ifdef PANTHEON_PantheonBotController_generated_h
#error "PantheonBotController.generated.h already included, missing '#pragma once' in PantheonBotController.h"
#endif
#define PANTHEON_PantheonBotController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APantheonBotController ***************************************************
PANTHEON_API UClass* Z_Construct_UClass_APantheonBotController_NoRegister();

#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPantheonBotController(); \
	friend struct Z_Construct_UClass_APantheonBotController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PANTHEON_API UClass* Z_Construct_UClass_APantheonBotController_NoRegister(); \
public: \
	DECLARE_CLASS2(APantheonBotController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Pantheon"), Z_Construct_UClass_APantheonBotController_NoRegister) \
	DECLARE_SERIALIZER(APantheonBotController)


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	APantheonBotController(APantheonBotController&&) = delete; \
	APantheonBotController(const APantheonBotController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APantheonBotController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APantheonBotController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APantheonBotController) \
	NO_API virtual ~APantheonBotController();


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h_12_PROLOG
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APantheonBotController;

// ********** End Class APantheonBotController *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
