// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/PantheonPlayerState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheonPlayerState() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
F13_API UClass* Z_Construct_UClass_APantheonPlayerState();
F13_API UClass* Z_Construct_UClass_APantheonPlayerState_NoRegister();
F13_API UFunction* Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature();
F13_API UFunction* Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Delegate FOnCharacterSelectedSignature
struct Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics
{
	struct _Script_F13_eventOnCharacterSelectedSignature_Parms
	{
		APlayerController* SelectingPC;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectingPC;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::NewProp_SelectingPC = { "SelectingPC", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_F13_eventOnCharacterSelectedSignature_Parms, SelectingPC), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::NewProp_SelectingPC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_F13, nullptr, "OnCharacterSelectedSignature__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::_Script_F13_eventOnCharacterSelectedSignature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::_Script_F13_eventOnCharacterSelectedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterSelectedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterSelectedSignature, APlayerController* SelectingPC)
{
	struct _Script_F13_eventOnCharacterSelectedSignature_Parms
	{
		APlayerController* SelectingPC;
	};
	_Script_F13_eventOnCharacterSelectedSignature_Parms Parms;
	Parms.SelectingPC=SelectingPC;
	OnCharacterSelectedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnCharacterSelectedSignature

// Begin Delegate FOnReadyChanged
struct Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics
{
	struct _Script_F13_eventOnReadyChanged_Parms
	{
		APantheonPlayerState* PlayerState;
		bool bNowReady;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerState;
	static void NewProp_bNowReady_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNowReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::NewProp_PlayerState = { "PlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_F13_eventOnReadyChanged_Parms, PlayerState), Z_Construct_UClass_APantheonPlayerState_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::NewProp_bNowReady_SetBit(void* Obj)
{
	((_Script_F13_eventOnReadyChanged_Parms*)Obj)->bNowReady = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::NewProp_bNowReady = { "bNowReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_F13_eventOnReadyChanged_Parms), &Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::NewProp_bNowReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::NewProp_PlayerState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::NewProp_bNowReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_F13, nullptr, "OnReadyChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::_Script_F13_eventOnReadyChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::_Script_F13_eventOnReadyChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnReadyChanged_DelegateWrapper(const FMulticastScriptDelegate& OnReadyChanged, APantheonPlayerState* PlayerState, bool bNowReady)
{
	struct _Script_F13_eventOnReadyChanged_Parms
	{
		APantheonPlayerState* PlayerState;
		bool bNowReady;
	};
	_Script_F13_eventOnReadyChanged_Parms Parms;
	Parms.PlayerState=PlayerState;
	Parms.bNowReady=bNowReady ? true : false;
	OnReadyChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnReadyChanged

// Begin Class APantheonPlayerState Function GetChosenPawnClassForRole
struct Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics
{
	struct PantheonPlayerState_eventGetChosenPawnClassForRole_Parms
	{
		FString InRole;
		TSubclassOf<APawn> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CharacterSelection" },
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InRole_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InRole;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::NewProp_InRole = { "InRole", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PantheonPlayerState_eventGetChosenPawnClassForRole_Parms, InRole), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InRole_MetaData), NewProp_InRole_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PantheonPlayerState_eventGetChosenPawnClassForRole_Parms, ReturnValue), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::NewProp_InRole,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APantheonPlayerState, nullptr, "GetChosenPawnClassForRole", nullptr, nullptr, Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::PropPointers), sizeof(Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::PantheonPlayerState_eventGetChosenPawnClassForRole_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::Function_MetaDataParams), Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::PantheonPlayerState_eventGetChosenPawnClassForRole_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APantheonPlayerState::execGetChosenPawnClassForRole)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InRole);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TSubclassOf<APawn>*)Z_Param__Result=P_THIS->GetChosenPawnClassForRole(Z_Param_InRole);
	P_NATIVE_END;
}
// End Class APantheonPlayerState Function GetChosenPawnClassForRole

// Begin Class APantheonPlayerState Function IsReady
struct Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics
{
	struct PantheonPlayerState_eventIsReady_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Lobby" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current ready state (replicated). */" },
#endif
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current ready state (replicated)." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PantheonPlayerState_eventIsReady_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PantheonPlayerState_eventIsReady_Parms), &Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APantheonPlayerState, nullptr, "IsReady", nullptr, nullptr, Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::PropPointers), sizeof(Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::PantheonPlayerState_eventIsReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::Function_MetaDataParams), Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::PantheonPlayerState_eventIsReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APantheonPlayerState_IsReady()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APantheonPlayerState_IsReady_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APantheonPlayerState::execIsReady)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsReady();
	P_NATIVE_END;
}
// End Class APantheonPlayerState Function IsReady

// Begin Class APantheonPlayerState Function OnRep_IsReady
struct Z_Construct_UFunction_APantheonPlayerState_OnRep_IsReady_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APantheonPlayerState_OnRep_IsReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APantheonPlayerState, nullptr, "OnRep_IsReady", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_OnRep_IsReady_Statics::Function_MetaDataParams), Z_Construct_UFunction_APantheonPlayerState_OnRep_IsReady_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APantheonPlayerState_OnRep_IsReady()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APantheonPlayerState_OnRep_IsReady_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APantheonPlayerState::execOnRep_IsReady)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_IsReady();
	P_NATIVE_END;
}
// End Class APantheonPlayerState Function OnRep_IsReady

// Begin Class APantheonPlayerState Function SetReady
struct Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics
{
	struct PantheonPlayerState_eventSetReady_Parms
	{
		bool bNewReady;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Lobby" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Call from UI to toggle ready. */" },
#endif
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Call from UI to toggle ready." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bNewReady_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::NewProp_bNewReady_SetBit(void* Obj)
{
	((PantheonPlayerState_eventSetReady_Parms*)Obj)->bNewReady = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::NewProp_bNewReady = { "bNewReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PantheonPlayerState_eventSetReady_Parms), &Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::NewProp_bNewReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::NewProp_bNewReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APantheonPlayerState, nullptr, "SetReady", nullptr, nullptr, Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::PropPointers), sizeof(Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::PantheonPlayerState_eventSetReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::Function_MetaDataParams), Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::PantheonPlayerState_eventSetReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APantheonPlayerState_SetReady()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APantheonPlayerState_SetReady_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APantheonPlayerState::execSetReady)
{
	P_GET_UBOOL(Z_Param_bNewReady);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetReady(Z_Param_bNewReady);
	P_NATIVE_END;
}
// End Class APantheonPlayerState Function SetReady

// Begin Class APantheonPlayerState
void APantheonPlayerState::StaticRegisterNativesAPantheonPlayerState()
{
	UClass* Class = APantheonPlayerState::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetChosenPawnClassForRole", &APantheonPlayerState::execGetChosenPawnClassForRole },
		{ "IsReady", &APantheonPlayerState::execIsReady },
		{ "OnRep_IsReady", &APantheonPlayerState::execOnRep_IsReady },
		{ "SetReady", &APantheonPlayerState::execSetReady },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APantheonPlayerState);
UClass* Z_Construct_UClass_APantheonPlayerState_NoRegister()
{
	return APantheonPlayerState::StaticClass();
}
struct Z_Construct_UClass_APantheonPlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PantheonPlayerState.h" },
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnReadyChanged_MetaData[] = {
		{ "Category", "Lobby" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired on both server & clients whenever ready changes. */" },
#endif
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired on both server & clients whenever ready changes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedPawnClass_MetaData[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChosenRole_MetaData[] = {
		{ "Category", "CharacterSelection" },
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterSelected_MetaData[] = {
		{ "Category", "CharacterSelection" },
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsBot_MetaData[] = {
		{ "Category", "PantheonPlayerState" },
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurvivorRowKey_MetaData[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KillerRowKey_MetaData[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterOptionsTable_MetaData[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsReady_MetaData[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnReadyChanged;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SelectedPawnClass;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ChosenRole;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterSelected;
	static void NewProp_bIsBot_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsBot;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SurvivorRowKey;
	static const UECodeGen_Private::FNamePropertyParams NewProp_KillerRowKey;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterOptionsTable;
	static void NewProp_bIsReady_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APantheonPlayerState_GetChosenPawnClassForRole, "GetChosenPawnClassForRole" }, // 47963111
		{ &Z_Construct_UFunction_APantheonPlayerState_IsReady, "IsReady" }, // 3392498803
		{ &Z_Construct_UFunction_APantheonPlayerState_OnRep_IsReady, "OnRep_IsReady" }, // 2891582922
		{ &Z_Construct_UFunction_APantheonPlayerState_SetReady, "SetReady" }, // 713270098
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APantheonPlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_OnReadyChanged = { "OnReadyChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APantheonPlayerState, OnReadyChanged), Z_Construct_UDelegateFunction_F13_OnReadyChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnReadyChanged_MetaData), NewProp_OnReadyChanged_MetaData) }; // 88106267
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_SelectedPawnClass = { "SelectedPawnClass", nullptr, (EPropertyFlags)0x0014000000000020, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APantheonPlayerState, SelectedPawnClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedPawnClass_MetaData), NewProp_SelectedPawnClass_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_ChosenRole = { "ChosenRole", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APantheonPlayerState, ChosenRole), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChosenRole_MetaData), NewProp_ChosenRole_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_OnCharacterSelected = { "OnCharacterSelected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APantheonPlayerState, OnCharacterSelected), Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterSelected_MetaData), NewProp_OnCharacterSelected_MetaData) }; // 2640832691
void Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_bIsBot_SetBit(void* Obj)
{
	((APantheonPlayerState*)Obj)->bIsBot = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_bIsBot = { "bIsBot", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APantheonPlayerState), &Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_bIsBot_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsBot_MetaData), NewProp_bIsBot_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_SurvivorRowKey = { "SurvivorRowKey", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APantheonPlayerState, SurvivorRowKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurvivorRowKey_MetaData), NewProp_SurvivorRowKey_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_KillerRowKey = { "KillerRowKey", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APantheonPlayerState, KillerRowKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KillerRowKey_MetaData), NewProp_KillerRowKey_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_CharacterOptionsTable = { "CharacterOptionsTable", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APantheonPlayerState, CharacterOptionsTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterOptionsTable_MetaData), NewProp_CharacterOptionsTable_MetaData) };
void Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_bIsReady_SetBit(void* Obj)
{
	((APantheonPlayerState*)Obj)->bIsReady = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_bIsReady = { "bIsReady", "OnRep_IsReady", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APantheonPlayerState), &Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_bIsReady_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsReady_MetaData), NewProp_bIsReady_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APantheonPlayerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_OnReadyChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_SelectedPawnClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_ChosenRole,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_OnCharacterSelected,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_bIsBot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_SurvivorRowKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_KillerRowKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_CharacterOptionsTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonPlayerState_Statics::NewProp_bIsReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonPlayerState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APantheonPlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonPlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APantheonPlayerState_Statics::ClassParams = {
	&APantheonPlayerState::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_APantheonPlayerState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_APantheonPlayerState_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonPlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_APantheonPlayerState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APantheonPlayerState()
{
	if (!Z_Registration_Info_UClass_APantheonPlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APantheonPlayerState.OuterSingleton, Z_Construct_UClass_APantheonPlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APantheonPlayerState.OuterSingleton;
}
template<> F13_API UClass* StaticClass<APantheonPlayerState>()
{
	return APantheonPlayerState::StaticClass();
}
void APantheonPlayerState::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_SelectedPawnClass(TEXT("SelectedPawnClass"));
	static const FName Name_ChosenRole(TEXT("ChosenRole"));
	static const FName Name_bIsBot(TEXT("bIsBot"));
	static const FName Name_SurvivorRowKey(TEXT("SurvivorRowKey"));
	static const FName Name_KillerRowKey(TEXT("KillerRowKey"));
	static const FName Name_bIsReady(TEXT("bIsReady"));
	const bool bIsValid = true
		&& Name_SelectedPawnClass == ClassReps[(int32)ENetFields_Private::SelectedPawnClass].Property->GetFName()
		&& Name_ChosenRole == ClassReps[(int32)ENetFields_Private::ChosenRole].Property->GetFName()
		&& Name_bIsBot == ClassReps[(int32)ENetFields_Private::bIsBot].Property->GetFName()
		&& Name_SurvivorRowKey == ClassReps[(int32)ENetFields_Private::SurvivorRowKey].Property->GetFName()
		&& Name_KillerRowKey == ClassReps[(int32)ENetFields_Private::KillerRowKey].Property->GetFName()
		&& Name_bIsReady == ClassReps[(int32)ENetFields_Private::bIsReady].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in APantheonPlayerState"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonPlayerState);
APantheonPlayerState::~APantheonPlayerState() {}
// End Class APantheonPlayerState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonPlayerState, APantheonPlayerState::StaticClass, TEXT("APantheonPlayerState"), &Z_Registration_Info_UClass_APantheonPlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonPlayerState), 296693799U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerState_h_3984503375(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
