// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "F13CharacterBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef F13_F13CharacterBase_generated_h
#error "F13CharacterBase.generated.h already included, missing '#pragma once' in F13CharacterBase.h"
#endif
#define F13_F13CharacterBase_generated_h

#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerSetSprinting_Validate(bool ); \
	virtual void ServerSetSprinting_Implementation(bool bNewSprinting); \
	DECLARE_FUNCTION(execServerSetSprinting); \
	DECLARE_FUNCTION(execOnRep_IsSprinting);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_22_CALLBACK_WRAPPERS
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAF13CharacterBase(); \
	friend struct Z_Construct_UClass_AF13CharacterBase_Statics; \
public: \
	DECLARE_CLASS(AF13CharacterBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/F13"), NO_API) \
	DECLARE_SERIALIZER(AF13CharacterBase) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsSprinting=NETFIELD_REP_START, \
		NETFIELD_REP_END=bIsSprinting	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AF13CharacterBase(AF13CharacterBase&&); \
	AF13CharacterBase(const AF13CharacterBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AF13CharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AF13CharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AF13CharacterBase) \
	NO_API virtual ~AF13CharacterBase();


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_19_PROLOG
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_22_CALLBACK_WRAPPERS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_22_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> F13_API UClass* StaticClass<class AF13CharacterBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
