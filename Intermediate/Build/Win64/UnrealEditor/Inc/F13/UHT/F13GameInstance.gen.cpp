// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13GameInstance() {}

// Begin Cross Module References
F13_API UClass* Z_Construct_UClass_UF13GameInstance();
F13_API UClass* Z_Construct_UClass_UF13GameInstance_NoRegister();
F13_API UFunction* Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature();
F13_API UFunction* Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature();
F13_API UFunction* Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature();
HOSTMIGRATIONSYSTEM_API UClass* Z_Construct_UClass_UHMS_GameInstance();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Delegate FOnSessionJoined
struct Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics
{
	struct _Script_F13_eventOnSessionJoined_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ---------------- Blueprint-facing delegates ---------------- */" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
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
void Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((_Script_F13_eventOnSessionJoined_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_F13_eventOnSessionJoined_Parms), &Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_F13, nullptr, "OnSessionJoined__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::_Script_F13_eventOnSessionJoined_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::_Script_F13_eventOnSessionJoined_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSessionJoined_DelegateWrapper(const FMulticastScriptDelegate& OnSessionJoined, bool bWasSuccessful)
{
	struct _Script_F13_eventOnSessionJoined_Parms
	{
		bool bWasSuccessful;
	};
	_Script_F13_eventOnSessionJoined_Parms Parms;
	Parms.bWasSuccessful=bWasSuccessful ? true : false;
	OnSessionJoined.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnSessionJoined

// Begin Delegate FOnSessionCreated
struct Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics
{
	struct _Script_F13_eventOnSessionCreated_Parms
	{
		bool bWasSuccessful;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bWasSuccessful_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
{
	((_Script_F13_eventOnSessionCreated_Parms*)Obj)->bWasSuccessful = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_F13_eventOnSessionCreated_Parms), &Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::NewProp_bWasSuccessful,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_F13, nullptr, "OnSessionCreated__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::_Script_F13_eventOnSessionCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::_Script_F13_eventOnSessionCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSessionCreated_DelegateWrapper(const FMulticastScriptDelegate& OnSessionCreated, bool bWasSuccessful)
{
	struct _Script_F13_eventOnSessionCreated_Parms
	{
		bool bWasSuccessful;
	};
	_Script_F13_eventOnSessionCreated_Parms Parms;
	Parms.bWasSuccessful=bWasSuccessful ? true : false;
	OnSessionCreated.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnSessionCreated

// Begin Delegate FOnSessionListReady
struct Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics
{
	struct _Script_F13_eventOnSessionListReady_Parms
	{
		TArray<FString> FoundNames;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::NewProp_FoundNames_Inner = { "FoundNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::NewProp_FoundNames = { "FoundNames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_F13_eventOnSessionListReady_Parms, FoundNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FoundNames_MetaData), NewProp_FoundNames_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::NewProp_FoundNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::NewProp_FoundNames,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_F13, nullptr, "OnSessionListReady__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::_Script_F13_eventOnSessionListReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::_Script_F13_eventOnSessionListReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSessionListReady_DelegateWrapper(const FMulticastScriptDelegate& OnSessionListReady, TArray<FString> const& FoundNames)
{
	struct _Script_F13_eventOnSessionListReady_Parms
	{
		TArray<FString> FoundNames;
	};
	_Script_F13_eventOnSessionListReady_Parms Parms;
	Parms.FoundNames=FoundNames;
	OnSessionListReady.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnSessionListReady

// Begin Class UF13GameInstance Function FindSessions
struct Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UF13GameInstance, nullptr, "FindSessions", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UF13GameInstance_FindSessions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UF13GameInstance::execFindSessions)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FindSessions();
	P_NATIVE_END;
}
// End Class UF13GameInstance Function FindSessions

// Begin Class UF13GameInstance Function GetFoundSessionNames
struct Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics
{
	struct F13GameInstance_eventGetFoundSessionNames_Parms
	{
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13GameInstance_eventGetFoundSessionNames_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UF13GameInstance, nullptr, "GetFoundSessionNames", nullptr, nullptr, Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::PropPointers), sizeof(Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::F13GameInstance_eventGetFoundSessionNames_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::Function_MetaDataParams), Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::F13GameInstance_eventGetFoundSessionNames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UF13GameInstance::execGetFoundSessionNames)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=P_THIS->GetFoundSessionNames();
	P_NATIVE_END;
}
// End Class UF13GameInstance Function GetFoundSessionNames

// Begin Class UF13GameInstance Function HostAndStartSession
struct Z_Construct_UFunction_UF13GameInstance_HostAndStartSession_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ----------  UI entry-points ---------- */" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "----------  UI entry-points ----------" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UF13GameInstance_HostAndStartSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UF13GameInstance, nullptr, "HostAndStartSession", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_HostAndStartSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UF13GameInstance_HostAndStartSession_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UF13GameInstance_HostAndStartSession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UF13GameInstance_HostAndStartSession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UF13GameInstance::execHostAndStartSession)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HostAndStartSession();
	P_NATIVE_END;
}
// End Class UF13GameInstance Function HostAndStartSession

// Begin Class UF13GameInstance Function JoinFoundSession
struct Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics
{
	struct F13GameInstance_eventJoinFoundSession_Parms
	{
		int32 SessionIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_SessionIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::NewProp_SessionIndex = { "SessionIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13GameInstance_eventJoinFoundSession_Parms, SessionIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::NewProp_SessionIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UF13GameInstance, nullptr, "JoinFoundSession", nullptr, nullptr, Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::PropPointers), sizeof(Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::F13GameInstance_eventJoinFoundSession_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::F13GameInstance_eventJoinFoundSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UF13GameInstance_JoinFoundSession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UF13GameInstance_JoinFoundSession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UF13GameInstance::execJoinFoundSession)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SessionIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->JoinFoundSession(Z_Param_SessionIndex);
	P_NATIVE_END;
}
// End Class UF13GameInstance Function JoinFoundSession

// Begin Class UF13GameInstance
void UF13GameInstance::StaticRegisterNativesUF13GameInstance()
{
	UClass* Class = UF13GameInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FindSessions", &UF13GameInstance::execFindSessions },
		{ "GetFoundSessionNames", &UF13GameInstance::execGetFoundSessionNames },
		{ "HostAndStartSession", &UF13GameInstance::execHostAndStartSession },
		{ "JoinFoundSession", &UF13GameInstance::execJoinFoundSession },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UF13GameInstance);
UClass* Z_Construct_UClass_UF13GameInstance_NoRegister()
{
	return UF13GameInstance::StaticClass();
}
struct Z_Construct_UClass_UF13GameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "F13GameInstance.h" },
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSessionCreated_MetaData[] = {
		{ "Category", "Session" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ----------  Delegates exposed to Blueprints ---------- */" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "----------  Delegates exposed to Blueprints ----------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSessionJoined_MetaData[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSessionListReady_MetaData[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionCreated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionJoined;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionListReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UF13GameInstance_FindSessions, "FindSessions" }, // 2088473563
		{ &Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames, "GetFoundSessionNames" }, // 3043457142
		{ &Z_Construct_UFunction_UF13GameInstance_HostAndStartSession, "HostAndStartSession" }, // 1044260777
		{ &Z_Construct_UFunction_UF13GameInstance_JoinFoundSession, "JoinFoundSession" }, // 3392513280
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UF13GameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionCreated = { "OnSessionCreated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UF13GameInstance, OnSessionCreated), Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSessionCreated_MetaData), NewProp_OnSessionCreated_MetaData) }; // 175889299
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionJoined = { "OnSessionJoined", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UF13GameInstance, OnSessionJoined), Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSessionJoined_MetaData), NewProp_OnSessionJoined_MetaData) }; // 461676031
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionListReady = { "OnSessionListReady", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UF13GameInstance, OnSessionListReady), Z_Construct_UDelegateFunction_F13_OnSessionListReady__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSessionListReady_MetaData), NewProp_OnSessionListReady_MetaData) }; // 4068235461
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UF13GameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionCreated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionJoined,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionListReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UF13GameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UF13GameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UHMS_GameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UF13GameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UF13GameInstance_Statics::ClassParams = {
	&UF13GameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UF13GameInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UF13GameInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UF13GameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UF13GameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UF13GameInstance()
{
	if (!Z_Registration_Info_UClass_UF13GameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UF13GameInstance.OuterSingleton, Z_Construct_UClass_UF13GameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UF13GameInstance.OuterSingleton;
}
template<> F13_API UClass* StaticClass<UF13GameInstance>()
{
	return UF13GameInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UF13GameInstance);
UF13GameInstance::~UF13GameInstance() {}
// End Class UF13GameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UF13GameInstance, UF13GameInstance::StaticClass, TEXT("UF13GameInstance"), &Z_Registration_Info_UClass_UF13GameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UF13GameInstance), 1925869549U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameInstance_h_3956746003(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
