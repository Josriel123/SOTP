// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Pantheon/Public/PantheonKillerCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheonKillerCharacter() {}

// Begin Cross Module References
PANTHEON_API UClass* Z_Construct_UClass_APantheonCharacterBase();
PANTHEON_API UClass* Z_Construct_UClass_APantheonKillerCharacter();
PANTHEON_API UClass* Z_Construct_UClass_APantheonKillerCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_Pantheon();
// End Cross Module References

// Begin Class APantheonKillerCharacter
void APantheonKillerCharacter::StaticRegisterNativesAPantheonKillerCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APantheonKillerCharacter);
UClass* Z_Construct_UClass_APantheonKillerCharacter_NoRegister()
{
	return APantheonKillerCharacter::StaticClass();
}
struct Z_Construct_UClass_APantheonKillerCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PantheonKillerCharacter.h" },
		{ "ModuleRelativePath", "Public/PantheonKillerCharacter.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APantheonKillerCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APantheonKillerCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APantheonCharacterBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Pantheon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonKillerCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APantheonKillerCharacter_Statics::ClassParams = {
	&APantheonKillerCharacter::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonKillerCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_APantheonKillerCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APantheonKillerCharacter()
{
	if (!Z_Registration_Info_UClass_APantheonKillerCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APantheonKillerCharacter.OuterSingleton, Z_Construct_UClass_APantheonKillerCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APantheonKillerCharacter.OuterSingleton;
}
template<> PANTHEON_API UClass* StaticClass<APantheonKillerCharacter>()
{
	return APantheonKillerCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonKillerCharacter);
APantheonKillerCharacter::~APantheonKillerCharacter() {}
// End Class APantheonKillerCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonKillerCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonKillerCharacter, APantheonKillerCharacter::StaticClass, TEXT("APantheonKillerCharacter"), &Z_Registration_Info_UClass_APantheonKillerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonKillerCharacter), 683668204U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonKillerCharacter_h_3517262989(TEXT("/Script/Pantheon"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonKillerCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_Slayers_Of_The_Pantheon_Source_Pantheon_Public_PantheonKillerCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
