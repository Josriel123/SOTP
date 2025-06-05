// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/F13PlayerState.h"
#include "UObject/CoreNet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13PlayerState() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
F13_API UClass* Z_Construct_UClass_AF13PlayerState();
F13_API UClass* Z_Construct_UClass_AF13PlayerState_NoRegister();
F13_API UFunction* Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature();
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegate signature: when the server has accepted a character choice,\n// broadcast to anyone (e.g. GameMode) so they can spawn the Pawn.\n" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate signature: when the server has accepted a character choice,\nbroadcast to anyone (e.g. GameMode) so they can spawn the Pawn." },
#endif
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

// Begin Class AF13PlayerState Function GetChosenPawnClass
struct Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics
{
	struct F13PlayerState_eventGetChosenPawnClass_Parms
	{
		TSubclassOf<APawn> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 *  Given the already\xe2\x80\x90loaded DataTable and the replicated RowKey,\n\x09 *  return the Pawn subclass that corresponds to ChosenCharacterKey.\n\x09 *  Only valid on the server; clients will simply get nullptr.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Given the already\xe2\x80\x90loaded DataTable and the replicated RowKey,\nreturn the Pawn subclass that corresponds to ChosenCharacterKey.\nOnly valid on the server; clients will simply get nullptr." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13PlayerState_eventGetChosenPawnClass_Parms, ReturnValue), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AF13PlayerState, nullptr, "GetChosenPawnClass", nullptr, nullptr, Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::F13PlayerState_eventGetChosenPawnClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::F13PlayerState_eventGetChosenPawnClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AF13PlayerState::execGetChosenPawnClass)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TSubclassOf<APawn>*)Z_Param__Result=P_THIS->GetChosenPawnClass();
	P_NATIVE_END;
}
// End Class AF13PlayerState Function GetChosenPawnClass

// Begin Class AF13PlayerState Function ServerSetCharacterSelection
struct F13PlayerState_eventServerSetCharacterSelection_Parms
{
	FString NewRole;
	FName NewCharacterKey;
};
static const FName NAME_AF13PlayerState_ServerSetCharacterSelection = FName(TEXT("ServerSetCharacterSelection"));
void AF13PlayerState::ServerSetCharacterSelection(const FString& NewRole, FName const& NewCharacterKey)
{
	F13PlayerState_eventServerSetCharacterSelection_Parms Parms;
	Parms.NewRole=NewRole;
	Parms.NewCharacterKey=NewCharacterKey;
	UFunction* Func = FindFunctionChecked(NAME_AF13PlayerState_ServerSetCharacterSelection);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 *  Called on the client when the player picks something in the UI.\n\x09 *  This RPC is executed on the server, which caches the new values and\n\x09 *  broadcasts OnCharacterSelected so that GameMode (or whoever) can react.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called on the client when the player picks something in the UI.\nThis RPC is executed on the server, which caches the new values and\nbroadcasts OnCharacterSelected so that GameMode (or whoever) can react." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewRole_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewCharacterKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_NewRole;
	static const UECodeGen_Private::FNamePropertyParams NewProp_NewCharacterKey;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::NewProp_NewRole = { "NewRole", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13PlayerState_eventServerSetCharacterSelection_Parms, NewRole), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewRole_MetaData), NewProp_NewRole_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::NewProp_NewCharacterKey = { "NewCharacterKey", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13PlayerState_eventServerSetCharacterSelection_Parms, NewCharacterKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewCharacterKey_MetaData), NewProp_NewCharacterKey_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::NewProp_NewRole,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::NewProp_NewCharacterKey,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AF13PlayerState, nullptr, "ServerSetCharacterSelection", nullptr, nullptr, Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::PropPointers), sizeof(F13PlayerState_eventServerSetCharacterSelection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::Function_MetaDataParams), Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::Function_MetaDataParams) };
static_assert(sizeof(F13PlayerState_eventServerSetCharacterSelection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AF13PlayerState::execServerSetCharacterSelection)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_NewRole);
	P_GET_PROPERTY(FNameProperty,Z_Param_NewCharacterKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ServerSetCharacterSelection_Validate(Z_Param_NewRole,Z_Param_NewCharacterKey))
	{
		RPC_ValidateFailed(TEXT("ServerSetCharacterSelection_Validate"));
		return;
	}
	P_THIS->ServerSetCharacterSelection_Implementation(Z_Param_NewRole,Z_Param_NewCharacterKey);
	P_NATIVE_END;
}
// End Class AF13PlayerState Function ServerSetCharacterSelection

// Begin Class AF13PlayerState
void AF13PlayerState::StaticRegisterNativesAF13PlayerState()
{
	UClass* Class = AF13PlayerState::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetChosenPawnClass", &AF13PlayerState::execGetChosenPawnClass },
		{ "ServerSetCharacterSelection", &AF13PlayerState::execServerSetCharacterSelection },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AF13PlayerState);
UClass* Z_Construct_UClass_AF13PlayerState_NoRegister()
{
	return AF13PlayerState::StaticClass();
}
struct Z_Construct_UClass_AF13PlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Custom PlayerState: stores Role + DataTable row key,\n *  and publishes an event when the server \xe2\x80\x9clocks in\xe2\x80\x9d the character choice.\n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "F13PlayerState.h" },
		{ "ModuleRelativePath", "F13PlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom PlayerState: stores Role + DataTable row key,\nand publishes an event when the server \xe2\x80\x9clocks in\xe2\x80\x9d the character choice." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChosenRole_MetaData[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 *  The \xe2\x80\x9crole\xe2\x80\x9d string the player chose (e.g. \xe2\x80\x9cKiller\xe2\x80\x9d or \xe2\x80\x9cSurvivor\xe2\x80\x9d).\n\x09 */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The \xe2\x80\x9crole\xe2\x80\x9d string the player chose (e.g. \xe2\x80\x9cKiller\xe2\x80\x9d or \xe2\x80\x9cSurvivor\xe2\x80\x9d)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChosenCharacterKey_MetaData[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 *  The DataTable row name/key for the character this player picked.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The DataTable row name/key for the character this player picked." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterSelected_MetaData[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 *  Fired on the server once ServerSetCharacterSelection is accepted.  Passes\n\x09 *  the APlayerController* that owns this PlayerState as the single argument.\n\x09 *  GameMode can bind to this event and then call SpawnChosenPawnForController(SelectingPC).\n\x09 */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired on the server once ServerSetCharacterSelection is accepted.  Passes\nthe APlayerController* that owns this PlayerState as the single argument.\nGameMode can bind to this event and then call SpawnChosenPawnForController(SelectingPC)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterOptionsTable_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 *  Cached pointer to our Character\xe2\x80\x90options DataTable.\n\x09 *  We load it once in the constructor (server only).\n\x09 *  After that, any call to FindRow<\xe2\x80\xa6>() is very cheap at runtime.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached pointer to our Character\xe2\x80\x90options DataTable.\nWe load it once in the constructor (server only).\nAfter that, any call to FindRow<\xe2\x80\xa6>() is very cheap at runtime." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ChosenRole;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ChosenCharacterKey;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterSelected;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterOptionsTable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass, "GetChosenPawnClass" }, // 1909513106
		{ &Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection, "ServerSetCharacterSelection" }, // 1754132136
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13PlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AF13PlayerState_Statics::NewProp_ChosenRole = { "ChosenRole", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13PlayerState, ChosenRole), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChosenRole_MetaData), NewProp_ChosenRole_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AF13PlayerState_Statics::NewProp_ChosenCharacterKey = { "ChosenCharacterKey", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13PlayerState, ChosenCharacterKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChosenCharacterKey_MetaData), NewProp_ChosenCharacterKey_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AF13PlayerState_Statics::NewProp_OnCharacterSelected = { "OnCharacterSelected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13PlayerState, OnCharacterSelected), Z_Construct_UDelegateFunction_F13_OnCharacterSelectedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterSelected_MetaData), NewProp_OnCharacterSelected_MetaData) }; // 2064971867
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13PlayerState_Statics::NewProp_CharacterOptionsTable = { "CharacterOptionsTable", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13PlayerState, CharacterOptionsTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterOptionsTable_MetaData), NewProp_CharacterOptionsTable_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AF13PlayerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13PlayerState_Statics::NewProp_ChosenRole,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13PlayerState_Statics::NewProp_ChosenCharacterKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13PlayerState_Statics::NewProp_OnCharacterSelected,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13PlayerState_Statics::NewProp_CharacterOptionsTable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13PlayerState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AF13PlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13PlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AF13PlayerState_Statics::ClassParams = {
	&AF13PlayerState::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AF13PlayerState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AF13PlayerState_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AF13PlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_AF13PlayerState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AF13PlayerState()
{
	if (!Z_Registration_Info_UClass_AF13PlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AF13PlayerState.OuterSingleton, Z_Construct_UClass_AF13PlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AF13PlayerState.OuterSingleton;
}
template<> F13_API UClass* StaticClass<AF13PlayerState>()
{
	return AF13PlayerState::StaticClass();
}
void AF13PlayerState::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_ChosenRole(TEXT("ChosenRole"));
	static const FName Name_ChosenCharacterKey(TEXT("ChosenCharacterKey"));
	const bool bIsValid = true
		&& Name_ChosenRole == ClassReps[(int32)ENetFields_Private::ChosenRole].Property->GetFName()
		&& Name_ChosenCharacterKey == ClassReps[(int32)ENetFields_Private::ChosenCharacterKey].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AF13PlayerState"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13PlayerState);
AF13PlayerState::~AF13PlayerState() {}
// End Class AF13PlayerState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13PlayerState, AF13PlayerState::StaticClass, TEXT("AF13PlayerState"), &Z_Registration_Info_UClass_AF13PlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13PlayerState), 2991321781U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_3006620241(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
