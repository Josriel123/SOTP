// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/F13PlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13PlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
F13_API UClass* Z_Construct_UClass_AF13PlayerController();
F13_API UClass* Z_Construct_UClass_AF13PlayerController_NoRegister();
F13_API UClass* Z_Construct_UClass_AF13PlayerState_NoRegister();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13PlayerController Function ClientClickedSelectOption
struct Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics
{
	struct F13PlayerController_eventClientClickedSelectOption_Parms
	{
		FString ChosenRole;
		FName ChosenKey;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called by the UI (Blueprint) when the player clicks on a character option.\n\x09 * Forwards to the PlayerState server RPC.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "F13PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called by the UI (Blueprint) when the player clicks on a character option.\nForwards to the PlayerState server RPC." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChosenRole_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChosenKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ChosenRole;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ChosenKey;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::NewProp_ChosenRole = { "ChosenRole", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13PlayerController_eventClientClickedSelectOption_Parms, ChosenRole), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChosenRole_MetaData), NewProp_ChosenRole_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::NewProp_ChosenKey = { "ChosenKey", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13PlayerController_eventClientClickedSelectOption_Parms, ChosenKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChosenKey_MetaData), NewProp_ChosenKey_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::NewProp_ChosenRole,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::NewProp_ChosenKey,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AF13PlayerController, nullptr, "ClientClickedSelectOption", nullptr, nullptr, Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::PropPointers), sizeof(Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::F13PlayerController_eventClientClickedSelectOption_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::Function_MetaDataParams), Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::F13PlayerController_eventClientClickedSelectOption_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AF13PlayerController::execClientClickedSelectOption)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ChosenRole);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_ChosenKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientClickedSelectOption(Z_Param_ChosenRole,Z_Param_Out_ChosenKey);
	P_NATIVE_END;
}
// End Class AF13PlayerController Function ClientClickedSelectOption

// Begin Class AF13PlayerController
void AF13PlayerController::StaticRegisterNativesAF13PlayerController()
{
	UClass* Class = AF13PlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientClickedSelectOption", &AF13PlayerController::execClientClickedSelectOption },
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
		{ "ModuleRelativePath", "F13PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PlayerController responsible for receiving character\xe2\x80\x90selection clicks from UI\nand forwarding them to the server\xe2\x80\x90side PlayerState RPC." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_F13PlayerStateCached_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached pointer to our PlayerState, cast to AF13PlayerState. */" },
#endif
		{ "ModuleRelativePath", "F13PlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached pointer to our PlayerState, cast to AF13PlayerState." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_F13PlayerStateCached;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AF13PlayerController_ClientClickedSelectOption, "ClientClickedSelectOption" }, // 1262126504
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
	(UObject* (*)())Z_Construct_UClass_APlayerController,
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
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13PlayerController, AF13PlayerController::StaticClass, TEXT("AF13PlayerController"), &Z_Registration_Info_UClass_AF13PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13PlayerController), 4134574681U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerController_h_2632479748(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13PlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
