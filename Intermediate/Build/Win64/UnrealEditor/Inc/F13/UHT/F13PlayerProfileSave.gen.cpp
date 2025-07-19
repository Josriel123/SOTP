// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13PlayerProfileSave.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13PlayerProfileSave() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_USaveGame();
F13_API UClass* Z_Construct_UClass_UF13PlayerProfileSave();
F13_API UClass* Z_Construct_UClass_UF13PlayerProfileSave_NoRegister();
F13_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerProfileData();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin ScriptStruct FPlayerProfileData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PlayerProfileData;
class UScriptStruct* FPlayerProfileData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PlayerProfileData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PlayerProfileData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlayerProfileData, (UObject*)Z_Construct_UPackage__Script_F13(), TEXT("PlayerProfileData"));
	}
	return Z_Registration_Info_UScriptStruct_PlayerProfileData.OuterSingleton;
}
template<> F13_API UScriptStruct* StaticStruct<FPlayerProfileData>()
{
	return FPlayerProfileData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FPlayerProfileData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/F13PlayerProfileSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurvivorRowKey_MetaData[] = {
		{ "ModuleRelativePath", "Public/F13PlayerProfileSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KillerRowKey_MetaData[] = {
		{ "ModuleRelativePath", "Public/F13PlayerProfileSave.h" },
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
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
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
	if (!Z_Registration_Info_UScriptStruct_PlayerProfileData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PlayerProfileData.InnerSingleton, Z_Construct_UScriptStruct_FPlayerProfileData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_PlayerProfileData.InnerSingleton;
}
// End ScriptStruct FPlayerProfileData

// Begin Class UF13PlayerProfileSave
void UF13PlayerProfileSave::StaticRegisterNativesUF13PlayerProfileSave()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UF13PlayerProfileSave);
UClass* Z_Construct_UClass_UF13PlayerProfileSave_NoRegister()
{
	return UF13PlayerProfileSave::StaticClass();
}
struct Z_Construct_UClass_UF13PlayerProfileSave_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "F13PlayerProfileSave.h" },
		{ "ModuleRelativePath", "Public/F13PlayerProfileSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveVersion_MetaData[] = {
		{ "ModuleRelativePath", "Public/F13PlayerProfileSave.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Profile_MetaData[] = {
		{ "ModuleRelativePath", "Public/F13PlayerProfileSave.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_SaveVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Profile;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UF13PlayerProfileSave>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UF13PlayerProfileSave_Statics::NewProp_SaveVersion = { "SaveVersion", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UF13PlayerProfileSave, SaveVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveVersion_MetaData), NewProp_SaveVersion_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UF13PlayerProfileSave_Statics::NewProp_Profile = { "Profile", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UF13PlayerProfileSave, Profile), Z_Construct_UScriptStruct_FPlayerProfileData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Profile_MetaData), NewProp_Profile_MetaData) }; // 3163263218
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UF13PlayerProfileSave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UF13PlayerProfileSave_Statics::NewProp_SaveVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UF13PlayerProfileSave_Statics::NewProp_Profile,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UF13PlayerProfileSave_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UF13PlayerProfileSave_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USaveGame,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UF13PlayerProfileSave_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UF13PlayerProfileSave_Statics::ClassParams = {
	&UF13PlayerProfileSave::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UF13PlayerProfileSave_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UF13PlayerProfileSave_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UF13PlayerProfileSave_Statics::Class_MetaDataParams), Z_Construct_UClass_UF13PlayerProfileSave_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UF13PlayerProfileSave()
{
	if (!Z_Registration_Info_UClass_UF13PlayerProfileSave.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UF13PlayerProfileSave.OuterSingleton, Z_Construct_UClass_UF13PlayerProfileSave_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UF13PlayerProfileSave.OuterSingleton;
}
template<> F13_API UClass* StaticClass<UF13PlayerProfileSave>()
{
	return UF13PlayerProfileSave::StaticClass();
}
UF13PlayerProfileSave::UF13PlayerProfileSave(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UF13PlayerProfileSave);
UF13PlayerProfileSave::~UF13PlayerProfileSave() {}
// End Class UF13PlayerProfileSave

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerProfileSave_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPlayerProfileData::StaticStruct, Z_Construct_UScriptStruct_FPlayerProfileData_Statics::NewStructOps, TEXT("PlayerProfileData"), &Z_Registration_Info_UScriptStruct_PlayerProfileData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlayerProfileData), 3163263218U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UF13PlayerProfileSave, UF13PlayerProfileSave::StaticClass, TEXT("UF13PlayerProfileSave"), &Z_Registration_Info_UClass_UF13PlayerProfileSave, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UF13PlayerProfileSave), 954707366U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerProfileSave_h_3940680488(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerProfileSave_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerProfileSave_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerProfileSave_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13PlayerProfileSave_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
