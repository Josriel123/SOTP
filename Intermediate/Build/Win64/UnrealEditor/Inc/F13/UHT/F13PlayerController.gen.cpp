// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13PlayerController.h"
#include "UObject/CoreNet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13PlayerController() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
F13_API UClass* Z_Construct_UClass_AF13PlayerController();
F13_API UClass* Z_Construct_UClass_AF13PlayerController_NoRegister();
F13_API UClass* Z_Construct_UClass_AF13PlayerState_NoRegister();
HOSTMIGRATIONSYSTEM_API UClass* Z_Construct_UClass_AHMS_PlayerController();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13PlayerController Function ServerSelectPawnClass
struct F13PlayerController_eventServerSelectPawnClass_Parms
{
	TSubclassOf<APawn> PawnClass;
};
static const FName NAME_AF13PlayerController_ServerSelectPawnClass = FName(TEXT("ServerSelectPawnClass"));
void AF13PlayerController::ServerSelectPawnClass(TSubclassOf<APawn> PawnClass)
{
	F13PlayerController_eventServerSelectPawnClass_Parms Parms;
	Parms.PawnClass=PawnClass;
	UFunction* Func = FindFunctionChecked(NAME_AF13PlayerController_ServerSelectPawnClass);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/F13PlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_PawnClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::NewProp_PawnClass = { "PawnClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13PlayerController_eventServerSelectPawnClass_Parms, PawnClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::NewProp_PawnClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AF13PlayerController, nullptr, "ServerSelectPawnClass", nullptr, nullptr, Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::PropPointers), sizeof(F13PlayerController_eventServerSelectPawnClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::Function_MetaDataParams) };
static_assert(sizeof(F13PlayerController_eventServerSelectPawnClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AF13PlayerController::execServerSelectPawnClass)
{
	P_GET_OBJECT(UClass,Z_Param_PawnClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ServerSelectPawnClass_Validate(Z_Param_PawnClass))
	{
		RPC_ValidateFailed(TEXT("ServerSelectPawnClass_Validate"));
		return;
	}
	P_THIS->ServerSelectPawnClass_Implementation(Z_Param_PawnClass);
	P_NATIVE_END;
}
// End Class AF13PlayerController Function ServerSelectPawnClass

// Begin Class AF13PlayerController Function ServerSetReady
struct F13PlayerController_eventServerSetReady_Parms
{
	bool bNewReady;
};
static const FName NAME_AF13PlayerController_ServerSetReady = FName(TEXT("ServerSetReady"));
void AF13PlayerController::ServerSetReady(bool bNewReady)
{
	F13PlayerController_eventServerSetReady_Parms Parms;
	Parms.bNewReady=bNewReady ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AF13PlayerController_ServerSetReady);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/F13PlayerController.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bNewReady_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::NewProp_bNewReady_SetBit(void* Obj)
{
	((F13PlayerController_eventServerSetReady_Parms*)Obj)->bNewReady = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::NewProp_bNewReady = { "bNewReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(F13PlayerController_eventServerSetReady_Parms), &Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::NewProp_bNewReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::NewProp_bNewReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AF13PlayerController, nullptr, "ServerSetReady", nullptr, nullptr, Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::PropPointers), sizeof(F13PlayerController_eventServerSetReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x84220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::Function_MetaDataParams), Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::Function_MetaDataParams) };
static_assert(sizeof(F13PlayerController_eventServerSetReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AF13PlayerController_ServerSetReady()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AF13PlayerController_ServerSetReady_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AF13PlayerController::execServerSetReady)
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
// End Class AF13PlayerController Function ServerSetReady

// Begin Class AF13PlayerController
void AF13PlayerController::StaticRegisterNativesAF13PlayerController()
{
	UClass* Class = AF13PlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ServerSelectPawnClass", &AF13PlayerController::execServerSelectPawnClass },
		{ "ServerSetReady", &AF13PlayerController::execServerSetReady },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AF13PlayerController);
UClass* Z_Construct_UClass_AF13PlayerController_NoRegister()
{
	return AF13PlayerController::StaticClass();
}
struct Z_Construct_UClass_AF13PlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * PlayerController responsible for receiving character\xe2\x80\x90selection clicks from UI\n * and forwarding them to the server\xe2\x80\x90side PlayerState RPC.\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "F13PlayerController.h" },
		{ "ModuleRelativePath", "Public/F13PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PlayerController responsible for receiving character\xe2\x80\x90selection clicks from UI\nand forwarding them to the server\xe2\x80\x90side PlayerState RPC." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_F13PlayerStateCached_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached pointer to our PlayerState, cast to AF13PlayerState. */" },
#endif
		{ "ModuleRelativePath", "Public/F13PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached pointer to our PlayerState, cast to AF13PlayerState." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_F13PlayerStateCached;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AF13PlayerController_ServerSelectPawnClass, "ServerSelectPawnClass" }, // 2494364073
		{ &Z_Construct_UFunction_AF13PlayerController_ServerSetReady, "ServerSetReady" }, // 4241041020
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13PlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13PlayerController_Statics::NewProp_F13PlayerStateCached = { "F13PlayerStateCached", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13PlayerController, F13PlayerStateCached), Z_Construct_UClass_AF13PlayerState_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_F13PlayerStateCached_MetaData), NewProp_F13PlayerStateCached_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AF13PlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13PlayerController_Statics::NewProp_F13PlayerStateCached,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13PlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AF13PlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHMS_PlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13PlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AF13PlayerController_Statics::ClassParams = {
	&AF13PlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AF13PlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AF13PlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AF13PlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AF13PlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AF13PlayerController()
{
	if (!Z_Registration_Info_UClass_AF13PlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AF13PlayerController.OuterSingleton, Z_Construct_UClass_AF13PlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AF13PlayerController.OuterSingleton;
}
template<> F13_API UClass* StaticClass<AF13PlayerController>()
{
	return AF13PlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13PlayerController);
AF13PlayerController::~AF13PlayerController() {}
// End Class AF13PlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13PlayerController, AF13PlayerController::StaticClass, TEXT("AF13PlayerController"), &Z_Registration_Info_UClass_AF13PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13PlayerController), 1948049451U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_2332931649(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
