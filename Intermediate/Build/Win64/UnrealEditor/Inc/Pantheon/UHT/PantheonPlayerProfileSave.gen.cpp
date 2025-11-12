// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PantheonPlayerProfileSave.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePantheonPlayerProfileSave() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_USaveGame();
PANTHEON_API UClass* Z_Construct_UClass_UPantheonPlayerProfileSave();
PANTHEON_API UClass* Z_Construct_UClass_UPantheonPlayerProfileSave_NoRegister();
PANTHEON_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerProfileData();
UPackage* Z_Construct_UPackage__Script_Pantheon();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FPlayerProfileData ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPlayerProfileData;
class UScriptStruct* FPlayerProfileData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPlayerProfileData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPlayerProfileData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlayerProfileData, (UObject*)Z_Construct_UPackage__Script_Pantheon(), TEXT("PlayerProfileData"));
	}
	return Z_Registration_Info_UScriptStruct_FPlayerProfileData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FPlayerProfileData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PantheonPlayerProfileSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurvivorRowKey_MetaData[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerProfileSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KillerRowKey_MetaData[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerProfileSave.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SurvivorRowKey;
	static const UECodeGen_Private::FNamePropertyParams NewProp_KillerRowKey;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlayerProfileData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPlayerProfileData_Statics::NewProp_SurvivorRowKey = { "SurvivorRowKey", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerProfileData, SurvivorRowKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurvivorRowKey_MetaData), NewProp_SurvivorRowKey_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPlayerProfileData_Statics::NewProp_KillerRowKey = { "KillerRowKey", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlayerProfileData, KillerRowKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KillerRowKey_MetaData), NewProp_KillerRowKey_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlayerProfileData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerProfileData_Statics::NewProp_SurvivorRowKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlayerProfileData_Statics::NewProp_KillerRowKey,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerProfileData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlayerProfileData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Pantheon,
	nullptr,
	&NewStructOps,
	"PlayerProfileData",
	Z_Construct_UScriptStruct_FPlayerProfileData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerProfileData_Statics::PropPointers),
	sizeof(FPlayerProfileData),
	alignof(FPlayerProfileData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlayerProfileData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlayerProfileData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlayerProfileData()
{
	if (!Z_Registration_Info_UScriptStruct_FPlayerProfileData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPlayerProfileData.InnerSingleton, Z_Construct_UScriptStruct_FPlayerProfileData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FPlayerProfileData.InnerSingleton;
}
// ********** End ScriptStruct FPlayerProfileData **************************************************

// ********** Begin Class UPantheonPlayerProfileSave ***********************************************
void UPantheonPlayerProfileSave::StaticRegisterNativesUPantheonPlayerProfileSave()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UPantheonPlayerProfileSave;
UClass* UPantheonPlayerProfileSave::GetPrivateStaticClass()
{
	using TClass = UPantheonPlayerProfileSave;
	if (!Z_Registration_Info_UClass_UPantheonPlayerProfileSave.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PantheonPlayerProfileSave"),
			Z_Registration_Info_UClass_UPantheonPlayerProfileSave.InnerSingleton,
			StaticRegisterNativesUPantheonPlayerProfileSave,
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
	return Z_Registration_Info_UClass_UPantheonPlayerProfileSave.InnerSingleton;
}
UClass* Z_Construct_UClass_UPantheonPlayerProfileSave_NoRegister()
{
	return UPantheonPlayerProfileSave::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPantheonPlayerProfileSave_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PantheonPlayerProfileSave.h" },
		{ "ModuleRelativePath", "Public/PantheonPlayerProfileSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveVersion_MetaData[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerProfileSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Profile_MetaData[] = {
		{ "ModuleRelativePath", "Public/PantheonPlayerProfileSave.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_SaveVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Profile;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPantheonPlayerProfileSave>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::NewProp_SaveVersion = { "SaveVersion", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPantheonPlayerProfileSave, SaveVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveVersion_MetaData), NewProp_SaveVersion_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::NewProp_Profile = { "Profile", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPantheonPlayerProfileSave, Profile), Z_Construct_UScriptStruct_FPlayerProfileData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Profile_MetaData), NewProp_Profile_MetaData) }; // 3079805725
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::NewProp_SaveVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::NewProp_Profile,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USaveGame,
	(UObject* (*)())Z_Construct_UPackage__Script_Pantheon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::ClassParams = {
	&UPantheonPlayerProfileSave::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::Class_MetaDataParams), Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPantheonPlayerProfileSave()
{
	if (!Z_Registration_Info_UClass_UPantheonPlayerProfileSave.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPantheonPlayerProfileSave.OuterSingleton, Z_Construct_UClass_UPantheonPlayerProfileSave_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPantheonPlayerProfileSave.OuterSingleton;
}
UPantheonPlayerProfileSave::UPantheonPlayerProfileSave(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPantheonPlayerProfileSave);
UPantheonPlayerProfileSave::~UPantheonPlayerProfileSave() {}
// ********** End Class UPantheonPlayerProfileSave *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h__Script_Pantheon_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPlayerProfileData::StaticStruct, Z_Construct_UScriptStruct_FPlayerProfileData_Statics::NewStructOps, TEXT("PlayerProfileData"), &Z_Registration_Info_UScriptStruct_FPlayerProfileData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlayerProfileData), 3079805725U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPantheonPlayerProfileSave, UPantheonPlayerProfileSave::StaticClass, TEXT("UPantheonPlayerProfileSave"), &Z_Registration_Info_UClass_UPantheonPlayerProfileSave, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPantheonPlayerProfileSave), 4066867271U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h__Script_Pantheon_686190231(TEXT("/Script/Pantheon"),
	Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h__Script_Pantheon_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h__Script_Pantheon_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h__Script_Pantheon_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonPlayerProfileSave_h__Script_Pantheon_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
