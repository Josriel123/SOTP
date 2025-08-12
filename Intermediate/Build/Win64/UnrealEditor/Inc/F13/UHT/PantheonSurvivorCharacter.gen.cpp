// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/PantheonSurvivorCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheonSurvivorCharacter() {}

// Begin Cross Module References
F13_API UClass* Z_Construct_UClass_APantheonCharacterBase();
F13_API UClass* Z_Construct_UClass_APantheonSurvivorCharacter();
F13_API UClass* Z_Construct_UClass_APantheonSurvivorCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class APantheonSurvivorCharacter
void APantheonSurvivorCharacter::StaticRegisterNativesAPantheonSurvivorCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APantheonSurvivorCharacter);
UClass* Z_Construct_UClass_APantheonSurvivorCharacter_NoRegister()
{
	return APantheonSurvivorCharacter::StaticClass();
}
struct Z_Construct_UClass_APantheonSurvivorCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PantheonSurvivorCharacter.h" },
		{ "ModuleRelativePath", "Public/PantheonSurvivorCharacter.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APantheonSurvivorCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APantheonSurvivorCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APantheonCharacterBase,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonSurvivorCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APantheonSurvivorCharacter_Statics::ClassParams = {
	&APantheonSurvivorCharacter::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonSurvivorCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_APantheonSurvivorCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APantheonSurvivorCharacter()
{
	if (!Z_Registration_Info_UClass_APantheonSurvivorCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APantheonSurvivorCharacter.OuterSingleton, Z_Construct_UClass_APantheonSurvivorCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APantheonSurvivorCharacter.OuterSingleton;
}
template<> F13_API UClass* StaticClass<APantheonSurvivorCharacter>()
{
	return APantheonSurvivorCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonSurvivorCharacter);
APantheonSurvivorCharacter::~APantheonSurvivorCharacter() {}
// End Class APantheonSurvivorCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonSurvivorCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonSurvivorCharacter, APantheonSurvivorCharacter::StaticClass, TEXT("APantheonSurvivorCharacter"), &Z_Registration_Info_UClass_APantheonSurvivorCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonSurvivorCharacter), 2850749484U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonSurvivorCharacter_h_4159955352(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonSurvivorCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonSurvivorCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
