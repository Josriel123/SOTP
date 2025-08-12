// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PantheonCharacterBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef F13_PantheonCharacterBase_generated_h
#error "PantheonCharacterBase.generated.h already included, missing '#pragma once' in PantheonCharacterBase.h"
#endif
#define F13_PantheonCharacterBase_generated_h

#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerSetSprinting_Validate(bool ); \
	virtual void ServerSetSprinting_Implementation(bool bNewSprinting); \
	DECLARE_FUNCTION(execServerSetSprinting); \
	DECLARE_FUNCTION(execOnRep_IsSprinting);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_24_CALLBACK_WRAPPERS
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPantheonCharacterBase(); \
	friend struct Z_Construct_UClass_APantheonCharacterBase_Statics; \
public: \
	DECLARE_CLASS(APantheonCharacterBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/F13"), NO_API) \
	DECLARE_SERIALIZER(APantheonCharacterBase) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		LastHumanUniqueId=NETFIELD_REP_START, \
		bIsSprinting, \
		NETFIELD_REP_END=bIsSprinting	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APantheonCharacterBase(APantheonCharacterBase&&); \
	APantheonCharacterBase(const APantheonCharacterBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APantheonCharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APantheonCharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APantheonCharacterBase) \
	NO_API virtual ~APantheonCharacterBase();


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_21_PROLOG
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_24_CALLBACK_WRAPPERS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_24_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> F13_API UClass* StaticClass<class APantheonCharacterBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonCharacterBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
