// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonCharacterBase.h"

#ifdef PANTHEON_PantheonCharacterBase_generated_h
#error "PantheonCharacterBase.generated.h already included, missing '#pragma once' in PantheonCharacterBase.h"
#endif
#define PANTHEON_PantheonCharacterBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class APantheonCharacterBase ***************************************************
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerSetSprinting_Validate(bool ); \
	virtual void ServerSetSprinting_Implementation(bool bNewSprinting); \
	DECLARE_FUNCTION(execServerSetSprinting); \
	DECLARE_FUNCTION(execOnRep_IsSprinting);


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_24_CALLBACK_WRAPPERS
PANTHEON_API UClass* Z_Construct_UClass_APantheonCharacterBase_NoRegister();

#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPantheonCharacterBase(); \
	friend struct Z_Construct_UClass_APantheonCharacterBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PANTHEON_API UClass* Z_Construct_UClass_APantheonCharacterBase_NoRegister(); \
public: \
	DECLARE_CLASS2(APantheonCharacterBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Pantheon"), Z_Construct_UClass_APantheonCharacterBase_NoRegister) \
	DECLARE_SERIALIZER(APantheonCharacterBase) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		LastHumanUniqueId=NETFIELD_REP_START, \
		bIsSprinting, \
		NETFIELD_REP_END=bIsSprinting	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	APantheonCharacterBase(APantheonCharacterBase&&) = delete; \
	APantheonCharacterBase(const APantheonCharacterBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APantheonCharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APantheonCharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APantheonCharacterBase) \
	NO_API virtual ~APantheonCharacterBase();


#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_21_PROLOG
#define FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_24_CALLBACK_WRAPPERS \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_24_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APantheonCharacterBase;

// ********** End Class APantheonCharacterBase *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonCharacterBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
