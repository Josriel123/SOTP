// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13BotController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13BotController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
F13_API UClass* Z_Construct_UClass_AF13BotController();
F13_API UClass* Z_Construct_UClass_AF13BotController_NoRegister();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13BotController
void AF13BotController::StaticRegisterNativesAF13BotController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AF13BotController);
UClass* Z_Construct_UClass_AF13BotController_NoRegister()
{
	return AF13BotController::StaticClass();
}
struct Z_Construct_UClass_AF13BotController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "F13BotController.h" },
		{ "ModuleRelativePath", "Public/F13BotController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkipLogoutRespawn_MetaData[] = {
		{ "Category", "F13BotController" },
		{ "ModuleRelativePath", "Public/F13BotController.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bSkipLogoutRespawn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkipLogoutRespawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13BotController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_AF13BotController_Statics::NewProp_bSkipLogoutRespawn_SetBit(void* Obj)
{
	((AF13BotController*)Obj)->bSkipLogoutRespawn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AF13BotController_Statics::NewProp_bSkipLogoutRespawn = { "bSkipLogoutRespawn", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AF13BotController), &Z_Construct_UClass_AF13BotController_Statics::NewProp_bSkipLogoutRespawn_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkipLogoutRespawn_MetaData), NewProp_bSkipLogoutRespawn_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AF13BotController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13BotController_Statics::NewProp_bSkipLogoutRespawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13BotController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AF13BotController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13BotController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AF13BotController_Statics::ClassParams = {
	&AF13BotController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AF13BotController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AF13BotController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AF13BotController_Statics::Class_MetaDataParams), Z_Construct_UClass_AF13BotController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AF13BotController()
{
	if (!Z_Registration_Info_UClass_AF13BotController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AF13BotController.OuterSingleton, Z_Construct_UClass_AF13BotController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AF13BotController.OuterSingleton;
}
template<> F13_API UClass* StaticClass<AF13BotController>()
{
	return AF13BotController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13BotController);
AF13BotController::~AF13BotController() {}
// End Class AF13BotController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13BotController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13BotController, AF13BotController::StaticClass, TEXT("AF13BotController"), &Z_Registration_Info_UClass_AF13BotController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13BotController), 985889895U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13BotController_h_2329213390(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13BotController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13BotController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
