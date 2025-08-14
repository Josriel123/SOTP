// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Pantheon/Public/PantheonGameInstance.h"
#include "Pantheon/Public/PantheonPlayerProfileSave.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheonGameInstance() {}

// Begin Cross Module References
HOSTMIGRATIONSYSTEM_API UClass* Z_Construct_UClass_UHMS_GameInstance();
PANTHEON_API UClass* Z_Construct_UClass_UPantheonGameInstance();
PANTHEON_API UClass* Z_Construct_UClass_UPantheonGameInstance_NoRegister();
PANTHEON_API UFunction* Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature();
PANTHEON_API UFunction* Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature();
PANTHEON_API UFunction* Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature();
PANTHEON_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerProfileData();
UPackage* Z_Construct_UPackage__Script_Pantheon();
// End Cross Module References

// Begin Delegate FOnSessionJoined
struct Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics
{
	struct _Script_Pantheon_eventOnSessionJoined_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ---------------- Blueprint-facing delegates ---------------- */" },
#endif
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---------------- Blueprint-facing delegates ----------------" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((_Script_Pantheon_eventOnSessionJoined_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_Pantheon_eventOnSessionJoined_Parms), &Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Pantheon, nullptr, "OnSessionJoined__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::_Script_Pantheon_eventOnSessionJoined_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::_Script_Pantheon_eventOnSessionJoined_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSessionJoined_DelegateWrapper(const FMulticastScriptDelegate& OnSessionJoined, bool bWasSuccessful)
{
	struct _Script_Pantheon_eventOnSessionJoined_Parms
	{
		bool bWasSuccessful;
	};
	_Script_Pantheon_eventOnSessionJoined_Parms Parms;
	Parms.bWasSuccessful=bWasSuccessful ? true : false;
	OnSessionJoined.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnSessionJoined

// Begin Delegate FOnSessionCreated
struct Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics
{
	struct _Script_Pantheon_eventOnSessionCreated_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((_Script_Pantheon_eventOnSessionCreated_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_Pantheon_eventOnSessionCreated_Parms), &Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Pantheon, nullptr, "OnSessionCreated__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::_Script_Pantheon_eventOnSessionCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::_Script_Pantheon_eventOnSessionCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSessionCreated_DelegateWrapper(const FMulticastScriptDelegate& OnSessionCreated, bool bWasSuccessful)
{
	struct _Script_Pantheon_eventOnSessionCreated_Parms
	{
		bool bWasSuccessful;
	};
	_Script_Pantheon_eventOnSessionCreated_Parms Parms;
	Parms.bWasSuccessful=bWasSuccessful ? true : false;
	OnSessionCreated.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnSessionCreated

// Begin Delegate FOnSessionListReady
struct Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics
{
	struct _Script_Pantheon_eventOnSessionListReady_Parms
	{
		TArray<FString> FoundNames;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FoundNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FoundNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FoundNames;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::NewProp_FoundNames_Inner = { "FoundNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::NewProp_FoundNames = { "FoundNames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Pantheon_eventOnSessionListReady_Parms, FoundNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FoundNames_MetaData), NewProp_FoundNames_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::NewProp_FoundNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::NewProp_FoundNames,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Pantheon, nullptr, "OnSessionListReady__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::_Script_Pantheon_eventOnSessionListReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::_Script_Pantheon_eventOnSessionListReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSessionListReady_DelegateWrapper(const FMulticastScriptDelegate& OnSessionListReady, TArray<FString> const& FoundNames)
{
	struct _Script_Pantheon_eventOnSessionListReady_Parms
	{
		TArray<FString> FoundNames;
	};
	_Script_Pantheon_eventOnSessionListReady_Parms Parms;
	Parms.FoundNames=FoundNames;
	OnSessionListReady.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnSessionListReady

// Begin Class UPantheonGameInstance Function FindSessions
struct Z_Construct_UFunction_UPantheonGameInstance_FindSessions_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPantheonGameInstance_FindSessions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPantheonGameInstance, nullptr, "FindSessions", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPantheonGameInstance_FindSessions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPantheonGameInstance_FindSessions_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UPantheonGameInstance_FindSessions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPantheonGameInstance_FindSessions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPantheonGameInstance::execFindSessions)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FindSessions();
	P_NATIVE_END;
}
// End Class UPantheonGameInstance Function FindSessions

// Begin Class UPantheonGameInstance Function GetFoundSessionNames
struct Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics
{
	struct PantheonGameInstance_eventGetFoundSessionNames_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PantheonGameInstance_eventGetFoundSessionNames_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPantheonGameInstance, nullptr, "GetFoundSessionNames", nullptr, nullptr, Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::PantheonGameInstance_eventGetFoundSessionNames_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::PantheonGameInstance_eventGetFoundSessionNames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPantheonGameInstance::execGetFoundSessionNames)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=P_THIS->GetFoundSessionNames();
	P_NATIVE_END;
}
// End Class UPantheonGameInstance Function GetFoundSessionNames

// Begin Class UPantheonGameInstance Function JoinFoundSession
struct Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics
{
	struct PantheonGameInstance_eventJoinFoundSession_Parms
	{
		int32 SessionIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_SessionIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::NewProp_SessionIndex = { "SessionIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PantheonGameInstance_eventJoinFoundSession_Parms, SessionIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::NewProp_SessionIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPantheonGameInstance, nullptr, "JoinFoundSession", nullptr, nullptr, Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::PantheonGameInstance_eventJoinFoundSession_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::PantheonGameInstance_eventJoinFoundSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPantheonGameInstance::execJoinFoundSession)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SessionIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->JoinFoundSession(Z_Param_SessionIndex);
	P_NATIVE_END;
}
// End Class UPantheonGameInstance Function JoinFoundSession

// Begin Class UPantheonGameInstance
void UPantheonGameInstance::StaticRegisterNativesUPantheonGameInstance()
{
	UClass* Class = UPantheonGameInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FindSessions", &UPantheonGameInstance::execFindSessions },
		{ "GetFoundSessionNames", &UPantheonGameInstance::execGetFoundSessionNames },
		{ "JoinFoundSession", &UPantheonGameInstance::execJoinFoundSession },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPantheonGameInstance);
UClass* Z_Construct_UClass_UPantheonGameInstance_NoRegister()
{
	return UPantheonGameInstance::StaticClass();
}
struct Z_Construct_UClass_UPantheonGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PantheonGameInstance.h" },
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedStartupProfile_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Accessible at runtime \xef\xbf\xbd holds what we loaded on startup */" },
#endif
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Accessible at runtime \xef\xbf\xbd holds what we loaded on startup" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSessionCreated_MetaData[] = {
		{ "Category", "Session" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ----------  Delegates exposed to Blueprints ---------- */" },
#endif
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "----------  Delegates exposed to Blueprints ----------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSessionJoined_MetaData[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSessionListReady_MetaData[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/PantheonGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedStartupProfile;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionCreated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionJoined;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionListReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPantheonGameInstance_FindSessions, "FindSessions" }, // 1953536788
		{ &Z_Construct_UFunction_UPantheonGameInstance_GetFoundSessionNames, "GetFoundSessionNames" }, // 329364117
		{ &Z_Construct_UFunction_UPantheonGameInstance_JoinFoundSession, "JoinFoundSession" }, // 2094059798
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPantheonGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPantheonGameInstance_Statics::NewProp_CachedStartupProfile = { "CachedStartupProfile", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPantheonGameInstance, CachedStartupProfile), Z_Construct_UScriptStruct_FPlayerProfileData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedStartupProfile_MetaData), NewProp_CachedStartupProfile_MetaData) }; // 3532099325
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPantheonGameInstance_Statics::NewProp_OnSessionCreated = { "OnSessionCreated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPantheonGameInstance, OnSessionCreated), Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSessionCreated_MetaData), NewProp_OnSessionCreated_MetaData) }; // 3986863906
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPantheonGameInstance_Statics::NewProp_OnSessionJoined = { "OnSessionJoined", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPantheonGameInstance, OnSessionJoined), Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSessionJoined_MetaData), NewProp_OnSessionJoined_MetaData) }; // 3225686265
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPantheonGameInstance_Statics::NewProp_OnSessionListReady = { "OnSessionListReady", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPantheonGameInstance, OnSessionListReady), Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSessionListReady_MetaData), NewProp_OnSessionListReady_MetaData) }; // 1426903721
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPantheonGameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPantheonGameInstance_Statics::NewProp_CachedStartupProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPantheonGameInstance_Statics::NewProp_OnSessionCreated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPantheonGameInstance_Statics::NewProp_OnSessionJoined,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPantheonGameInstance_Statics::NewProp_OnSessionListReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPantheonGameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPantheonGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UHMS_GameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_Pantheon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPantheonGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPantheonGameInstance_Statics::ClassParams = {
	&UPantheonGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPantheonGameInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPantheonGameInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPantheonGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UPantheonGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPantheonGameInstance()
{
	if (!Z_Registration_Info_UClass_UPantheonGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPantheonGameInstance.OuterSingleton, Z_Construct_UClass_UPantheonGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPantheonGameInstance.OuterSingleton;
}
template<> PANTHEON_API UClass* StaticClass<UPantheonGameInstance>()
{
	return UPantheonGameInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPantheonGameInstance);
UPantheonGameInstance::~UPantheonGameInstance() {}
// End Class UPantheonGameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonGameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPantheonGameInstance, UPantheonGameInstance::StaticClass, TEXT("UPantheonGameInstance"), &Z_Registration_Info_UClass_UPantheonGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPantheonGameInstance), 193337798U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonGameInstance_h_237164391(TEXT("/Script/Pantheon"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonGameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
