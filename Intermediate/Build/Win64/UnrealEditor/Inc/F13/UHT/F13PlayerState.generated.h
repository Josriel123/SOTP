// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "F13PlayerState.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
#ifdef F13_F13PlayerState_generated_h
#error "F13PlayerState.generated.h already included, missing '#pragma once' in F13PlayerState.h"
#endif
#define F13_F13PlayerState_generated_h

#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerSetCharacterSelection_Validate(const FString& , FName const& ); \
	virtual void ServerSetCharacterSelection_Implementation(const FString& NewRole, FName const& NewCharacterKey); \
	DECLARE_FUNCTION(execGetChosenPawnClass); \
	DECLARE_FUNCTION(execServerSetCharacterSelection);


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_16_CALLBACK_WRAPPERS
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAF13PlayerState(); \
	friend struct Z_Construct_UClass_AF13PlayerState_Statics; \
public: \
	DECLARE_CLASS(AF13PlayerState, APlayerState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/F13"), NO_API) \
	DECLARE_SERIALIZER(AF13PlayerState) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ChosenRole=NETFIELD_REP_START, \
		ChosenCharacterKey, \
		NETFIELD_REP_END=ChosenCharacterKey	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AF13PlayerState(AF13PlayerState&&); \
	AF13PlayerState(const AF13PlayerState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AF13PlayerState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AF13PlayerState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AF13PlayerState) \
	NO_API virtual ~AF13PlayerState();


#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_13_PROLOG
#define FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_16_CALLBACK_WRAPPERS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> F13_API UClass* StaticClass<class AF13PlayerState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
