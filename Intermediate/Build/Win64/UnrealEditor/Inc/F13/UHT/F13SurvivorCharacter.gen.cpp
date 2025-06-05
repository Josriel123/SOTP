// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13SurvivorCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13SurvivorCharacter() {}

// Begin Cross Module References
F13_API UClass* Z_Construct_UClass_AF13CharacterBase();
F13_API UClass* Z_Construct_UClass_AF13SurvivorCharacter();
F13_API UClass* Z_Construct_UClass_AF13SurvivorCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13SurvivorCharacter
void AF13SurvivorCharacter::StaticRegisterNativesAF13SurvivorCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AF13SurvivorCharacter);
UClass* Z_Construct_UClass_AF13SurvivorCharacter_NoRegister()
{
	return AF13SurvivorCharacter::StaticClass();
}
struct Z_Construct_UClass_AF13SurvivorCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "F13SurvivorCharacter.h" },
		{ "ModuleRelativePath", "Public/F13SurvivorCharacter.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13SurvivorCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AF13SurvivorCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AF13CharacterBase,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13SurvivorCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AF13SurvivorCharacter_Statics::ClassParams = {
	&AF13SurvivorCharacter::StaticClass,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AF13SurvivorCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AF13SurvivorCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AF13SurvivorCharacter()
{
	if (!Z_Registration_Info_UClass_AF13SurvivorCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AF13SurvivorCharacter.OuterSingleton, Z_Construct_UClass_AF13SurvivorCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AF13SurvivorCharacter.OuterSingleton;
}
template<> F13_API UClass* StaticClass<AF13SurvivorCharacter>()
{
	return AF13SurvivorCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13SurvivorCharacter);
AF13SurvivorCharacter::~AF13SurvivorCharacter() {}
// End Class AF13SurvivorCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13SurvivorCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13SurvivorCharacter, AF13SurvivorCharacter::StaticClass, TEXT("AF13SurvivorCharacter"), &Z_Registration_Info_UClass_AF13SurvivorCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13SurvivorCharacter), 1327860397U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13SurvivorCharacter_h_2707869206(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13SurvivorCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13SurvivorCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
