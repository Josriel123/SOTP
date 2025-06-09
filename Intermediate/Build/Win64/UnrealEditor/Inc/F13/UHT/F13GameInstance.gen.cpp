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
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
F13_API UClass* Z_Construct_UClass_UF13GameInstance();
F13_API UClass* Z_Construct_UClass_UF13GameInstance_NoRegister();
F13_API UFunction* Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature();
F13_API UFunction* Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature();
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
		{ "Comment", "// name of the new delegate type\n// type of the single parameter\n// name of the parameter in callbacks\n" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "name of the new delegate type\ntype of the single parameter\nname of the parameter in callbacks" },
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "// name of the new delegate type\n// type of the single parameter\n// name of the parameter in callbacks\n" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "name of the new delegate type\ntype of the single parameter\nname of the parameter in callbacks" },
#endif
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

// Begin Class UF13GameInstance Function FindSessions
struct Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics
{
	struct F13GameInstance_eventFindSessions_Parms
	{
		bool bIsLAN;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Search for available sessions */" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Search for available sessions" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bIsLAN_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsLAN;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::NewProp_bIsLAN_SetBit(void* Obj)
{
	((F13GameInstance_eventFindSessions_Parms*)Obj)->bIsLAN = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::NewProp_bIsLAN = { "bIsLAN", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(F13GameInstance_eventFindSessions_Parms), &Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::NewProp_bIsLAN_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::NewProp_bIsLAN,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UF13GameInstance, nullptr, "FindSessions", nullptr, nullptr, Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::F13GameInstance_eventFindSessions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UF13GameInstance_FindSessions_Statics::F13GameInstance_eventFindSessions_Parms) < MAX_uint16);
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
	P_GET_UBOOL(Z_Param_bIsLAN);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FindSessions(Z_Param_bIsLAN);
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get session names from last search */" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get session names from last search" },
#endif
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

// Begin Class UF13GameInstance Function HostSession
struct Z_Construct_UFunction_UF13GameInstance_HostSession_Statics
{
	struct F13GameInstance_eventHostSession_Parms
	{
		FName SessionName;
		bool bIsLAN;
		int32 MaxPlayers;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Start hosting a session */" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Start hosting a session" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SessionName;
	static void NewProp_bIsLAN_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsLAN;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxPlayers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::NewProp_SessionName = { "SessionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13GameInstance_eventHostSession_Parms, SessionName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::NewProp_bIsLAN_SetBit(void* Obj)
{
	((F13GameInstance_eventHostSession_Parms*)Obj)->bIsLAN = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::NewProp_bIsLAN = { "bIsLAN", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(F13GameInstance_eventHostSession_Parms), &Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::NewProp_bIsLAN_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::NewProp_MaxPlayers = { "MaxPlayers", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13GameInstance_eventHostSession_Parms, MaxPlayers), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::NewProp_SessionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::NewProp_bIsLAN,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::NewProp_MaxPlayers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UF13GameInstance, nullptr, "HostSession", nullptr, nullptr, Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::PropPointers), sizeof(Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::F13GameInstance_eventHostSession_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::F13GameInstance_eventHostSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UF13GameInstance_HostSession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UF13GameInstance_HostSession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UF13GameInstance::execHostSession)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_SessionName);
	P_GET_UBOOL(Z_Param_bIsLAN);
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxPlayers);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HostSession(Z_Param_SessionName,Z_Param_bIsLAN,Z_Param_MaxPlayers);
	P_NATIVE_END;
}
// End Class UF13GameInstance Function HostSession

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
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Join one of the found sessions by index */" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Join one of the found sessions by index" },
#endif
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

// Begin Class UF13GameInstance Function StartGameSession
struct Z_Construct_UFunction_UF13GameInstance_StartGameSession_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Session" },
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UF13GameInstance_StartGameSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UF13GameInstance, nullptr, "StartGameSession", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UF13GameInstance_StartGameSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UF13GameInstance_StartGameSession_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UF13GameInstance_StartGameSession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UF13GameInstance_StartGameSession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UF13GameInstance::execStartGameSession)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartGameSession();
	P_NATIVE_END;
}
// End Class UF13GameInstance Function StartGameSession

// Begin Class UF13GameInstance
void UF13GameInstance::StaticRegisterNativesUF13GameInstance()
{
	UClass* Class = UF13GameInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FindSessions", &UF13GameInstance::execFindSessions },
		{ "GetFoundSessionNames", &UF13GameInstance::execGetFoundSessionNames },
		{ "HostSession", &UF13GameInstance::execHostSession },
		{ "JoinFoundSession", &UF13GameInstance::execJoinFoundSession },
		{ "StartGameSession", &UF13GameInstance::execStartGameSession },
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
		{ "Comment", "/** Triggered when a session is created */" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Triggered when a session is created" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSessionJoined_MetaData[] = {
		{ "Category", "Session" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Triggered when a session is joined */" },
#endif
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Triggered when a session is joined" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSessionCreated_MetaData[] = {
		{ "ModuleRelativePath", "Public/F13GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionCreated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSessionJoined;
	static void NewProp_bSessionCreated_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSessionCreated;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UF13GameInstance_FindSessions, "FindSessions" }, // 4151081956
		{ &Z_Construct_UFunction_UF13GameInstance_GetFoundSessionNames, "GetFoundSessionNames" }, // 3846831208
		{ &Z_Construct_UFunction_UF13GameInstance_HostSession, "HostSession" }, // 762945610
		{ &Z_Construct_UFunction_UF13GameInstance_JoinFoundSession, "JoinFoundSession" }, // 277463511
		{ &Z_Construct_UFunction_UF13GameInstance_StartGameSession, "StartGameSession" }, // 589505344
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UF13GameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionCreated = { "OnSessionCreated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UF13GameInstance, OnSessionCreated), Z_Construct_UDelegateFunction_F13_OnSessionCreated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSessionCreated_MetaData), NewProp_OnSessionCreated_MetaData) }; // 3240551563
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionJoined = { "OnSessionJoined", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UF13GameInstance, OnSessionJoined), Z_Construct_UDelegateFunction_F13_OnSessionJoined__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSessionJoined_MetaData), NewProp_OnSessionJoined_MetaData) }; // 1539544734
void Z_Construct_UClass_UF13GameInstance_Statics::NewProp_bSessionCreated_SetBit(void* Obj)
{
	((UF13GameInstance*)Obj)->bSessionCreated = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UF13GameInstance_Statics::NewProp_bSessionCreated = { "bSessionCreated", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UF13GameInstance), &Z_Construct_UClass_UF13GameInstance_Statics::NewProp_bSessionCreated_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSessionCreated_MetaData), NewProp_bSessionCreated_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UF13GameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionCreated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UF13GameInstance_Statics::NewProp_OnSessionJoined,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UF13GameInstance_Statics::NewProp_bSessionCreated,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UF13GameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UF13GameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
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
		{ Z_Construct_UClass_UF13GameInstance, UF13GameInstance::StaticClass, TEXT("UF13GameInstance"), &Z_Registration_Info_UClass_UF13GameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UF13GameInstance), 4224501149U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameInstance_h_2772574820(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
