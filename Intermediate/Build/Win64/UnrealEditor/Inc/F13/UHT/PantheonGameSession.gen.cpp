// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/PantheonGameSession.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheonGameSession() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameSession();
F13_API UClass* Z_Construct_UClass_APantheonGameSession();
F13_API UClass* Z_Construct_UClass_APantheonGameSession_NoRegister();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class APantheonGameSession
void APantheonGameSession::StaticRegisterNativesAPantheonGameSession()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APantheonGameSession);
UClass* Z_Construct_UClass_APantheonGameSession_NoRegister()
{
	return APantheonGameSession::StaticClass();
}
struct Z_Construct_UClass_APantheonGameSession_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Custom GameSession that skips duplicate bot registration after\n    host-migration and logs Public / Registered counts. */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PantheonGameSession.h" },
		{ "ModuleRelativePath", "Public/PantheonGameSession.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom GameSession that skips duplicate bot registration after\n   host-migration and logs Public / Registered counts." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APantheonGameSession>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APantheonGameSession_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameSession,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonGameSession_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APantheonGameSession_Statics::ClassParams = {
	&APantheonGameSession::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonGameSession_Statics::Class_MetaDataParams), Z_Construct_UClass_APantheonGameSession_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APantheonGameSession()
{
	if (!Z_Registration_Info_UClass_APantheonGameSession.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APantheonGameSession.OuterSingleton, Z_Construct_UClass_APantheonGameSession_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APantheonGameSession.OuterSingleton;
}
template<> F13_API UClass* StaticClass<APantheonGameSession>()
{
	return APantheonGameSession::StaticClass();
}
APantheonGameSession::APantheonGameSession(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonGameSession);
APantheonGameSession::~APantheonGameSession() {}
// End Class APantheonGameSession

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameSession_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonGameSession, APantheonGameSession::StaticClass, TEXT("APantheonGameSession"), &Z_Registration_Info_UClass_APantheonGameSession, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonGameSession), 1293178664U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameSession_h_3592167932(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameSession_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameSession_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
