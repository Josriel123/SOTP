// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonLobbyGameMode.h"

#ifdef PANTHEON_PantheonLobbyGameMode_generated_h
#error "PantheonLobbyGameMode.generated.h already included, missing '#pragma once' in PantheonLobbyGameMode.h"
#endif
#define PANTHEON_PantheonLobbyGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APantheonLobbyGameMode ***************************************************
PANTHEON_API UClass* Z_Construct_UClass_APantheonLobbyGameMode_NoRegister();

#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonLobbyGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPantheonLobbyGameMode(); \
	friend struct Z_Construct_UClass_APantheonLobbyGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PANTHEON_API UClass* Z_Construct_UClass_APantheonLobbyGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(APantheonLobbyGameMode, AHMS_GameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Pantheon"), Z_Construct_UClass_APantheonLobbyGameMode_NoRegister) \
	DECLARE_SERIALIZER(APantheonLobbyGameMode)


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonLobbyGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	APantheonLobbyGameMode(APantheonLobbyGameMode&&) = delete; \
	APantheonLobbyGameMode(const APantheonLobbyGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APantheonLobbyGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APantheonLobbyGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APantheonLobbyGameMode) \
	NO_API virtual ~APantheonLobbyGameMode();


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonLobbyGameMode_h_12_PROLOG
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonLobbyGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonLobbyGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonLobbyGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APantheonLobbyGameMode;

// ********** End Class APantheonLobbyGameMode *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonLobbyGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
