// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13LobbyMenu.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13LobbyMenu() {}

// Begin Cross Module References
F13_API UClass* Z_Construct_UClass_AF13LobbyMenu();
F13_API UClass* Z_Construct_UClass_AF13LobbyMenu_NoRegister();
HOSTMIGRATIONSYSTEM_API UClass* Z_Construct_UClass_AHMS_GameMode();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13LobbyMenu
void AF13LobbyMenu::StaticRegisterNativesAF13LobbyMenu()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AF13LobbyMenu);
UClass* Z_Construct_UClass_AF13LobbyMenu_NoRegister()
{
	return AF13LobbyMenu::StaticClass();
}
struct Z_Construct_UClass_AF13LobbyMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "F13LobbyMenu.h" },
		{ "ModuleRelativePath", "Public/F13LobbyMenu.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13LobbyMenu>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AF13LobbyMenu_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHMS_GameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13LobbyMenu_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AF13LobbyMenu_Statics::ClassParams = {
	&AF13LobbyMenu::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AF13LobbyMenu_Statics::Class_MetaDataParams), Z_Construct_UClass_AF13LobbyMenu_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AF13LobbyMenu()
{
	if (!Z_Registration_Info_UClass_AF13LobbyMenu.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AF13LobbyMenu.OuterSingleton, Z_Construct_UClass_AF13LobbyMenu_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AF13LobbyMenu.OuterSingleton;
}
template<> F13_API UClass* StaticClass<AF13LobbyMenu>()
{
	return AF13LobbyMenu::StaticClass();
}
AF13LobbyMenu::AF13LobbyMenu(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13LobbyMenu);
AF13LobbyMenu::~AF13LobbyMenu() {}
// End Class AF13LobbyMenu

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13LobbyMenu_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13LobbyMenu, AF13LobbyMenu::StaticClass, TEXT("AF13LobbyMenu"), &Z_Registration_Info_UClass_AF13LobbyMenu, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13LobbyMenu), 1667403329U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13LobbyMenu_h_2542522211(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13LobbyMenu_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13LobbyMenu_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
