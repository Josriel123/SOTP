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
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
F13_API UClass* Z_Construct_UClass_AF13PlayerState();
F13_API UClass* Z_Construct_UClass_AF13PlayerState_NoRegister();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

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
		{ "Comment", "/** Returns the actual Pawn class (looks up the DataTable row by ChosenCharacterKey). */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the actual Pawn class (looks up the DataTable row by ChosenCharacterKey)." },
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
		{ "Comment", "/** Set both fields on the server (called via RPC). */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set both fields on the server (called via RPC)." },
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
		{ "Comment", "/**\n * Our custom PlayerState, stores role/character choices.\n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "F13PlayerState.h" },
		{ "ModuleRelativePath", "F13PlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Our custom PlayerState, stores role/character choices." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChosenRole_MetaData[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The role this player chose: \xe2\x80\x9cKiller\xe2\x80\x9d or \xe2\x80\x9cSurvivor\xe2\x80\x9d */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The role this player chose: \xe2\x80\x9cKiller\xe2\x80\x9d or \xe2\x80\x9cSurvivor\xe2\x80\x9d" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChosenCharacterKey_MetaData[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The DataTable RowName (key) for the character they picked. */" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The DataTable RowName (key) for the character they picked." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterOptionsTable_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cached pointer to our DataTable. We will lazy\xe2\x80\x90load it the first time GetChosenPawnClass() is called.\n" },
#endif
		{ "ModuleRelativePath", "F13PlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached pointer to our DataTable. We will lazy\xe2\x80\x90load it the first time GetChosenPawnClass() is called." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ChosenRole;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ChosenCharacterKey;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterOptionsTable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AF13PlayerState_GetChosenPawnClass, "GetChosenPawnClass" }, // 1940793767
		{ &Z_Construct_UFunction_AF13PlayerState_ServerSetCharacterSelection, "ServerSetCharacterSelection" }, // 1743847960
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13PlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AF13PlayerState_Statics::NewProp_ChosenRole = { "ChosenRole", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13PlayerState, ChosenRole), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChosenRole_MetaData), NewProp_ChosenRole_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AF13PlayerState_Statics::NewProp_ChosenCharacterKey = { "ChosenCharacterKey", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13PlayerState, ChosenCharacterKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChosenCharacterKey_MetaData), NewProp_ChosenCharacterKey_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13PlayerState_Statics::NewProp_CharacterOptionsTable = { "CharacterOptionsTable", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13PlayerState, CharacterOptionsTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterOptionsTable_MetaData), NewProp_CharacterOptionsTable_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AF13PlayerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13PlayerState_Statics::NewProp_ChosenRole,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13PlayerState_Statics::NewProp_ChosenCharacterKey,
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
		{ Z_Construct_UClass_AF13PlayerState, AF13PlayerState::StaticClass, TEXT("AF13PlayerState"), &Z_Registration_Info_UClass_AF13PlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13PlayerState), 2180971795U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_2619478872(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
