// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonGameSession.h"

#ifdef PANTHEON_PantheonGameSession_generated_h
#error "PantheonGameSession.generated.h already included, missing '#pragma once' in PantheonGameSession.h"
#endif
#define PANTHEON_PantheonGameSession_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APantheonGameSession *****************************************************
PANTHEON_API UClass* Z_Construct_UClass_APantheonGameSession_NoRegister();

#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPantheonGameSession(); \
	friend struct Z_Construct_UClass_APantheonGameSession_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PANTHEON_API UClass* Z_Construct_UClass_APantheonGameSession_NoRegister(); \
public: \
	DECLARE_CLASS2(APantheonGameSession, AGameSession, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Pantheon"), Z_Construct_UClass_APantheonGameSession_NoRegister) \
	DECLARE_SERIALIZER(APantheonGameSession)


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APantheonGameSession(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	APantheonGameSession(APantheonGameSession&&) = delete; \
	APantheonGameSession(const APantheonGameSession&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APantheonGameSession); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APantheonGameSession); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APantheonGameSession) \
	NO_API virtual ~APantheonGameSession();


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h_9_PROLOG
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APantheonGameSession;

// ********** End Class APantheonGameSession *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
