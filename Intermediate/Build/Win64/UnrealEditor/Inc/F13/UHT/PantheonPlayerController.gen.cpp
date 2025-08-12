// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/PantheonPlayerController.h"
#include "F13/Public/PantheonPlayerProfileSave.h"
#include "UObject/CoreNet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheonPlayerController() {}

// Begin Cross Module References
F13_API UClass* Z_Construct_UClass_APantheonPlayerController();
F13_API UClass* Z_Construct_UClass_APantheonPlayerController_NoRegister();
F13_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerProfileData();
HOSTMIGRATIONSYSTEM_API UClass* Z_Construct_UClass_AHMS_PlayerController();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class APantheonPlayerController Function Client_SaveLocalProfile
struct PantheonPlayerController_eventClient_SaveLocalProfile_Parms
{
	FPlayerProfileData InProfile;
};
static const FName NAME_APantheonPlayerController_Client_SaveLocalProfile = FName(TEXT("Client_SaveLocalProfile"));
void APantheonPlayerController::Client_SaveLocalProfile(FPlayerProfileData const& InProfile)
{
	PantheonPlayerController_eventClient_SaveLocalProfile_Parms Parms;
	Parms.InProfile=InProfile;
	UFunction* Func = FindFunctionChecked(NAME_APantheonPlayerController_Client_SaveLocalProfile);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Role = \"Killer\" or \"Survivor\"\n" },
#endif
		{ "ModuleRelativePath", "Public/PantheonPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Role = \"Killer\" or \"Survivor\"" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InProfile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InProfile;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::NewProp_InProfile = { "InProfile", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PantheonPlayerController_eventClient_SaveLocalProfile_Parms, InProfile), Z_Construct_UScriptStruct_FPlayerProfileData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InProfile_MetaData), NewProp_InProfile_MetaData) }; // 8793383
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::NewProp_InProfile,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APantheonPlayerController, nullptr, "Client_SaveLocalProfile", nullptr, nullptr, Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::PropPointers), sizeof(PantheonPlayerController_eventClient_SaveLocalProfile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::Function_MetaDataParams), Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::Function_MetaDataParams) };
static_assert(sizeof(PantheonPlayerController_eventClient_SaveLocalProfile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APantheonPlayerController::execClient_SaveLocalProfile)
{
	P_GET_STRUCT(FPlayerProfileData,Z_Param_InProfile);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Client_SaveLocalProfile_Implementation(Z_Param_InProfile);
	P_NATIVE_END;
}
// End Class APantheonPlayerController Function Client_SaveLocalProfile

// Begin Class APantheonPlayerController Function ServerSetCharacterPreference
struct PantheonPlayerController_eventServerSetCharacterPreference_Parms
{
	FName RowKey;
	FString InRole;
};
static const FName NAME_APantheonPlayerController_ServerSetCharacterPreference = FName(TEXT("ServerSetCharacterPreference"));
void APantheonPlayerController::ServerSetCharacterPreference(FName RowKey, const FString& InRole)
{
	PantheonPlayerController_eventServerSetCharacterPreference_Parms Parms;
	Parms.RowKey=RowKey;
	Parms.InRole=InRole;
	UFunction* Func = FindFunctionChecked(NAME_APantheonPlayerController_ServerSetCharacterPreference);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InRole_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_RowKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InRole;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::NewProp_RowKey = { "RowKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PantheonPlayerController_eventServerSetCharacterPreference_Parms, RowKey), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::NewProp_InRole = { "InRole", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PantheonPlayerController_eventServerSetCharacterPreference_Parms, InRole), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InRole_MetaData), NewProp_InRole_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::NewProp_RowKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::NewProp_InRole,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APantheonPlayerController, nullptr, "ServerSetCharacterPreference", nullptr, nullptr, Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::PropPointers), sizeof(PantheonPlayerController_eventServerSetCharacterPreference_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::Function_MetaDataParams), Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::Function_MetaDataParams) };
static_assert(sizeof(PantheonPlayerController_eventServerSetCharacterPreference_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APantheonPlayerController::execServerSetCharacterPreference)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_RowKey);
	P_GET_PROPERTY(FStrProperty,Z_Param_InRole);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ServerSetCharacterPreference_Validate(Z_Param_RowKey,Z_Param_InRole))
	{
		RPC_ValidateFailed(TEXT("ServerSetCharacterPreference_Validate"));
		return;
	}
	P_THIS->ServerSetCharacterPreference_Implementation(Z_Param_RowKey,Z_Param_InRole);
	P_NATIVE_END;
}
// End Class APantheonPlayerController Function ServerSetCharacterPreference

// Begin Class APantheonPlayerController Function ServerSetReady
struct PantheonPlayerController_eventServerSetReady_Parms
{
	bool bNewReady;
};
static const FName NAME_APantheonPlayerController_ServerSetReady = FName(TEXT("ServerSetReady"));
void APantheonPlayerController::ServerSetReady(bool bNewReady)
{
	PantheonPlayerController_eventServerSetReady_Parms Parms;
	Parms.bNewReady=bNewReady ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_APantheonPlayerController_ServerSetReady);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerController.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bNewReady_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::NewProp_bNewReady_SetBit(void* Obj)
{
	((PantheonPlayerController_eventServerSetReady_Parms*)Obj)->bNewReady = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::NewProp_bNewReady = { "bNewReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PantheonPlayerController_eventServerSetReady_Parms), &Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::NewProp_bNewReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::NewProp_bNewReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APantheonPlayerController, nullptr, "ServerSetReady", nullptr, nullptr, Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::PropPointers), sizeof(PantheonPlayerController_eventServerSetReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::Function_MetaDataParams), Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::Function_MetaDataParams) };
static_assert(sizeof(PantheonPlayerController_eventServerSetReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APantheonPlayerController_ServerSetReady()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APantheonPlayerController_ServerSetReady_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APantheonPlayerController::execServerSetReady)
{
	P_GET_UBOOL(Z_Param_bNewReady);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ServerSetReady_Validate(Z_Param_bNewReady))
	{
		RPC_ValidateFailed(TEXT("ServerSetReady_Validate"));
		return;
	}
	P_THIS->ServerSetReady_Implementation(Z_Param_bNewReady);
	P_NATIVE_END;
}
// End Class APantheonPlayerController Function ServerSetReady

// Begin Class APantheonPlayerController
void APantheonPlayerController::StaticRegisterNativesAPantheonPlayerController()
{
	UClass* Class = APantheonPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Client_SaveLocalProfile", &APantheonPlayerController::execClient_SaveLocalProfile },
		{ "ServerSetCharacterPreference", &APantheonPlayerController::execServerSetCharacterPreference },
		{ "ServerSetReady", &APantheonPlayerController::execServerSetReady },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APantheonPlayerController);
UClass* Z_Construct_UClass_APantheonPlayerController_NoRegister()
{
	return APantheonPlayerController::StaticClass();
}
struct Z_Construct_UClass_APantheonPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * PlayerController responsible for receiving character-selection clicks from UI\n * and forwarding them to the server-side PlayerState RPC.\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "PantheonPlayerController.h" },
		{ "ModuleRelativePath", "Public/PantheonPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PlayerController responsible for receiving character-selection clicks from UI\nand forwarding them to the server-side PlayerState RPC." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APantheonPlayerController_Client_SaveLocalProfile, "Client_SaveLocalProfile" }, // 31023537
		{ &Z_Construct_UFunction_APantheonPlayerController_ServerSetCharacterPreference, "ServerSetCharacterPreference" }, // 2817890515
		{ &Z_Construct_UFunction_APantheonPlayerController_ServerSetReady, "ServerSetReady" }, // 374623294
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APantheonPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APantheonPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHMS_PlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APantheonPlayerController_Statics::ClassParams = {
	&APantheonPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_APantheonPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APantheonPlayerController()
{
	if (!Z_Registration_Info_UClass_APantheonPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APantheonPlayerController.OuterSingleton, Z_Construct_UClass_APantheonPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APantheonPlayerController.OuterSingleton;
}
template<> F13_API UClass* StaticClass<APantheonPlayerController>()
{
	return APantheonPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonPlayerController);
APantheonPlayerController::~APantheonPlayerController() {}
// End Class APantheonPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonPlayerController, APantheonPlayerController::StaticClass, TEXT("APantheonPlayerController"), &Z_Registration_Info_UClass_APantheonPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonPlayerController), 528315476U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_1485842229(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
