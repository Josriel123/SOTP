// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/F13Mode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13Mode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
F13_API UClass* Z_Construct_UClass_AF13Mode();
F13_API UClass* Z_Construct_UClass_AF13Mode_NoRegister();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13Mode
void AF13Mode::StaticRegisterNativesAF13Mode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AF13Mode);
UClass* Z_Construct_UClass_AF13Mode_NoRegister()
{
	return AF13Mode::StaticClass();
}
struct Z_Construct_UClass_AF13Mode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "F13Mode.h" },
		{ "ModuleRelativePath", "F13Mode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13Mode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AF13Mode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13Mode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AF13Mode_Statics::ClassParams = {
	&AF13Mode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AF13Mode_Statics::Class_MetaDataParams), Z_Construct_UClass_AF13Mode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AF13Mode()
{
	if (!Z_Registration_Info_UClass_AF13Mode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AF13Mode.OuterSingleton, Z_Construct_UClass_AF13Mode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AF13Mode.OuterSingleton;
}
template<> F13_API UClass* StaticClass<AF13Mode>()
{
	return AF13Mode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13Mode);
AF13Mode::~AF13Mode() {}
// End Class AF13Mode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13Mode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13Mode, AF13Mode::StaticClass, TEXT("AF13Mode"), &Z_Registration_Info_UClass_AF13Mode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13Mode), 4275938890U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13Mode_h_1665082732(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13Mode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13Mode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
