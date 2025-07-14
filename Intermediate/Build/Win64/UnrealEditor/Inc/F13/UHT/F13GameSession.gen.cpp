// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13GameSession.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13GameSession() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameSession();
F13_API UClass* Z_Construct_UClass_AF13GameSession();
F13_API UClass* Z_Construct_UClass_AF13GameSession_NoRegister();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13GameSession
void AF13GameSession::StaticRegisterNativesAF13GameSession()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AF13GameSession);
UClass* Z_Construct_UClass_AF13GameSession_NoRegister()
{
	return AF13GameSession::StaticClass();
}
struct Z_Construct_UClass_AF13GameSession_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Custom GameSession that skips duplicate bot registration after\n    host-migration and logs Public / Registered counts. */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "F13GameSession.h" },
		{ "ModuleRelativePath", "Public/F13GameSession.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom GameSession that skips duplicate bot registration after\n   host-migration and logs Public / Registered counts." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13GameSession>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AF13GameSession_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameSession,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13GameSession_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AF13GameSession_Statics::ClassParams = {
	&AF13GameSession::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AF13GameSession_Statics::Class_MetaDataParams), Z_Construct_UClass_AF13GameSession_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AF13GameSession()
{
	if (!Z_Registration_Info_UClass_AF13GameSession.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AF13GameSession.OuterSingleton, Z_Construct_UClass_AF13GameSession_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AF13GameSession.OuterSingleton;
}
template<> F13_API UClass* StaticClass<AF13GameSession>()
{
	return AF13GameSession::StaticClass();
}
AF13GameSession::AF13GameSession(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13GameSession);
AF13GameSession::~AF13GameSession() {}
// End Class AF13GameSession

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameSession_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13GameSession, AF13GameSession::StaticClass, TEXT("AF13GameSession"), &Z_Registration_Info_UClass_AF13GameSession, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13GameSession), 2464578782U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameSession_h_1942059365(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameSession_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13GameSession_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
