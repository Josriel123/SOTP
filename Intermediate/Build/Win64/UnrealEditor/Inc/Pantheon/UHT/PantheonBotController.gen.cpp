// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PantheonBotController.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePantheonBotController() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
PANTHEON_API UClass* Z_Construct_UClass_APantheonBotController();
PANTHEON_API UClass* Z_Construct_UClass_APantheonBotController_NoRegister();
UPackage* Z_Construct_UPackage__Script_Pantheon();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APantheonBotController ***************************************************
void APantheonBotController::StaticRegisterNativesAPantheonBotController()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_APantheonBotController;
UClass* APantheonBotController::GetPrivateStaticClass()
{
	using TClass = APantheonBotController;
	if (!Z_Registration_Info_UClass_APantheonBotController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PantheonBotController"),
			Z_Registration_Info_UClass_APantheonBotController.InnerSingleton,
			StaticRegisterNativesAPantheonBotController,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_APantheonBotController.InnerSingleton;
}
UClass* Z_Construct_UClass_APantheonBotController_NoRegister()
{
	return APantheonBotController::GetPrivateStaticClass();
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
	0x009003A4u,
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
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonBotController);
APantheonBotController::~APantheonBotController() {}
// ********** End Class APantheonBotController *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h__Script_Pantheon_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonBotController, APantheonBotController::StaticClass, TEXT("APantheonBotController"), &Z_Registration_Info_UClass_APantheonBotController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonBotController), 2274859474U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h__Script_Pantheon_2146622915(TEXT("/Script/Pantheon"),
	Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h__Script_Pantheon_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonBotController_h__Script_Pantheon_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
