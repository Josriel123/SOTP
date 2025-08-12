// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Pantheon/Public/PantheonBotController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheonBotController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
PANTHEON_API UClass* Z_Construct_UClass_APantheonBotController();
PANTHEON_API UClass* Z_Construct_UClass_APantheonBotController_NoRegister();
UPackage* Z_Construct_UPackage__Script_Pantheon();
// End Cross Module References

// Begin Class APantheonBotController
void APantheonBotController::StaticRegisterNativesAPantheonBotController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APantheonBotController);
UClass* Z_Construct_UClass_APantheonBotController_NoRegister()
{
	return APantheonBotController::StaticClass();
}
struct Z_Construct_UClass_APantheonBotController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "PantheonBotController.h" },
		{ "ModuleRelativePath", "Public/PantheonBotController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkipLogoutRespawn_MetaData[] = {
		{ "Category", "PantheonBotController" },
		{ "ModuleRelativePath", "Public/PantheonBotController.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bSkipLogoutRespawn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkipLogoutRespawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APantheonBotController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_APantheonBotController_Statics::NewProp_bSkipLogoutRespawn_SetBit(void* Obj)
{
	((APantheonBotController*)Obj)->bSkipLogoutRespawn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APantheonBotController_Statics::NewProp_bSkipLogoutRespawn = { "bSkipLogoutRespawn", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APantheonBotController), &Z_Construct_UClass_APantheonBotController_Statics::NewProp_bSkipLogoutRespawn_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkipLogoutRespawn_MetaData), NewProp_bSkipLogoutRespawn_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APantheonBotController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APantheonBotController_Statics::NewProp_bSkipLogoutRespawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonBotController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APantheonBotController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_Pantheon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonBotController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APantheonBotController_Statics::ClassParams = {
	&APantheonBotController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_APantheonBotController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_APantheonBotController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonBotController_Statics::Class_MetaDataParams), Z_Construct_UClass_APantheonBotController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APantheonBotController()
{
	if (!Z_Registration_Info_UClass_APantheonBotController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APantheonBotController.OuterSingleton, Z_Construct_UClass_APantheonBotController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APantheonBotController.OuterSingleton;
}
template<> PANTHEON_API UClass* StaticClass<APantheonBotController>()
{
	return APantheonBotController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonBotController);
APantheonBotController::~APantheonBotController() {}
// End Class APantheonBotController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonBotController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonBotController, APantheonBotController::StaticClass, TEXT("APantheonBotController"), &Z_Registration_Info_UClass_APantheonBotController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonBotController), 2433090228U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonBotController_h_2797870997(TEXT("/Script/Pantheon"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonBotController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonBotController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
