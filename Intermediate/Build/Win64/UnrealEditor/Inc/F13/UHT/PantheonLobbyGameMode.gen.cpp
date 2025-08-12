// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/PantheonLobbyGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheonLobbyGameMode() {}

// Begin Cross Module References
F13_API UClass* Z_Construct_UClass_APantheonLobbyGameMode();
F13_API UClass* Z_Construct_UClass_APantheonLobbyGameMode_NoRegister();
HOSTMIGRATIONSYSTEM_API UClass* Z_Construct_UClass_AHMS_GameMode();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class APantheonLobbyGameMode
void APantheonLobbyGameMode::StaticRegisterNativesAPantheonLobbyGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APantheonLobbyGameMode);
UClass* Z_Construct_UClass_APantheonLobbyGameMode_NoRegister()
{
	return APantheonLobbyGameMode::StaticClass();
}
struct Z_Construct_UClass_APantheonLobbyGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PantheonLobbyGameMode.h" },
		{ "ModuleRelativePath", "Public/PantheonLobbyGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APantheonLobbyGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APantheonLobbyGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHMS_GameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonLobbyGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APantheonLobbyGameMode_Statics::ClassParams = {
	&APantheonLobbyGameMode::StaticClass,
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
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonLobbyGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_APantheonLobbyGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APantheonLobbyGameMode()
{
	if (!Z_Registration_Info_UClass_APantheonLobbyGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APantheonLobbyGameMode.OuterSingleton, Z_Construct_UClass_APantheonLobbyGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APantheonLobbyGameMode.OuterSingleton;
}
template<> F13_API UClass* StaticClass<APantheonLobbyGameMode>()
{
	return APantheonLobbyGameMode::StaticClass();
}
APantheonLobbyGameMode::APantheonLobbyGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonLobbyGameMode);
APantheonLobbyGameMode::~APantheonLobbyGameMode() {}
// End Class APantheonLobbyGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonLobbyGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonLobbyGameMode, APantheonLobbyGameMode::StaticClass, TEXT("APantheonLobbyGameMode"), &Z_Registration_Info_UClass_APantheonLobbyGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonLobbyGameMode), 3021646469U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonLobbyGameMode_h_1580083189(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonLobbyGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonLobbyGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
