// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PantheonSurvivorCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePantheonSurvivorCharacter() {}

// ********** Begin Cross Module References ********************************************************
PANTHEON_API UClass* Z_Construct_UClass_APantheonCharacterBase();
PANTHEON_API UClass* Z_Construct_UClass_APantheonSurvivorCharacter();
PANTHEON_API UClass* Z_Construct_UClass_APantheonSurvivorCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_Pantheon();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APantheonSurvivorCharacter ***********************************************
void APantheonSurvivorCharacter::StaticRegisterNativesAPantheonSurvivorCharacter()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_APantheonSurvivorCharacter;
UClass* APantheonSurvivorCharacter::GetPrivateStaticClass()
{
	using TClass = APantheonSurvivorCharacter;
	if (!Z_Registration_Info_UClass_APantheonSurvivorCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PantheonSurvivorCharacter"),
			Z_Registration_Info_UClass_APantheonSurvivorCharacter.InnerSingleton,
			StaticRegisterNativesAPantheonSurvivorCharacter,
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
	return Z_Registration_Info_UClass_APantheonSurvivorCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_APantheonSurvivorCharacter_NoRegister()
{
	return APantheonSurvivorCharacter::GetPrivateStaticClass();
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
	(UObject* (*)())Z_Construct_UPackage__Script_Pantheon,
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
	0x009001A4u,
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
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonSurvivorCharacter);
APantheonSurvivorCharacter::~APantheonSurvivorCharacter() {}
// ********** End Class APantheonSurvivorCharacter *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonSurvivorCharacter_h__Script_Pantheon_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonSurvivorCharacter, APantheonSurvivorCharacter::StaticClass, TEXT("APantheonSurvivorCharacter"), &Z_Registration_Info_UClass_APantheonSurvivorCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonSurvivorCharacter), 497994591U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonSurvivorCharacter_h__Script_Pantheon_572705862(TEXT("/Script/Pantheon"),
	Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonSurvivorCharacter_h__Script_Pantheon_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonSurvivorCharacter_h__Script_Pantheon_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
