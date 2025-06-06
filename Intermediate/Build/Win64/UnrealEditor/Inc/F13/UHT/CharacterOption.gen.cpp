// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/CharacterOption.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterOption() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
F13_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterOption();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin ScriptStruct FCharacterOption
static_assert(std::is_polymorphic<FCharacterOption>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FCharacterOption cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CharacterOption;
class UScriptStruct* FCharacterOption::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CharacterOption.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CharacterOption.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCharacterOption, (UObject*)Z_Construct_UPackage__Script_F13(), TEXT("CharacterOption"));
	}
	return Z_Registration_Info_UScriptStruct_CharacterOption.OuterSingleton;
}
template<> F13_API UScriptStruct* StaticStruct<FCharacterOption>()
{
	return FCharacterOption::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCharacterOption_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * A single row in our Character DataTable:\n *   RoleName:      \xe2\x80\x9cKiller\xe2\x80\x9d or \xe2\x80\x9cSurvivor\xe2\x80\x9d\n *   CharacterName: Display string for UI\n *   PawnClass:     Which Pawn subclass to spawn when chosen\n */" },
#endif
		{ "ModuleRelativePath", "Public/CharacterOption.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A single row in our Character DataTable:\n  RoleName:      \xe2\x80\x9cKiller\xe2\x80\x9d or \xe2\x80\x9cSurvivor\xe2\x80\x9d\n  CharacterName: Display string for UI\n  PawnClass:     Which Pawn subclass to spawn when chosen" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoleName_MetaData[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Role string (for filtering in UI). Could also use an enum if you prefer.\n" },
#endif
		{ "ModuleRelativePath", "Public/CharacterOption.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Role string (for filtering in UI). Could also use an enum if you prefer." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterDisplayName_MetaData[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Display name in UI (e.g. \xe2\x80\x9cJason (Part 3)\xe2\x80\x9d, \xe2\x80\x9c""Brutal Billy\xe2\x80\x9d)\n" },
#endif
		{ "ModuleRelativePath", "Public/CharacterOption.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display name in UI (e.g. \xe2\x80\x9cJason (Part 3)\xe2\x80\x9d, \xe2\x80\x9c""Brutal Billy\xe2\x80\x9d)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PawnClass_MetaData[] = {
		{ "Category", "CharacterSelection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The actual Pawn subclass to spawn for this character\n" },
#endif
		{ "ModuleRelativePath", "Public/CharacterOption.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The actual Pawn subclass to spawn for this character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Texture_MetaData[] = {
		{ "Category", "DataTable" },
		{ "ModuleRelativePath", "Public/CharacterOption.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_RoleName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterDisplayName;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PawnClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCharacterOption>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharacterOption_Statics::NewProp_RoleName = { "RoleName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterOption, RoleName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoleName_MetaData), NewProp_RoleName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharacterOption_Statics::NewProp_CharacterDisplayName = { "CharacterDisplayName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterOption, CharacterDisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterDisplayName_MetaData), NewProp_CharacterDisplayName_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FCharacterOption_Statics::NewProp_PawnClass = { "PawnClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterOption, PawnClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PawnClass_MetaData), NewProp_PawnClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCharacterOption_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterOption, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Texture_MetaData), NewProp_Texture_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCharacterOption_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterOption_Statics::NewProp_RoleName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterOption_Statics::NewProp_CharacterDisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterOption_Statics::NewProp_PawnClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterOption_Statics::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterOption_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCharacterOption_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"CharacterOption",
	Z_Construct_UScriptStruct_FCharacterOption_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterOption_Statics::PropPointers),
	sizeof(FCharacterOption),
	alignof(FCharacterOption),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterOption_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCharacterOption_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCharacterOption()
{
	if (!Z_Registration_Info_UScriptStruct_CharacterOption.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CharacterOption.InnerSingleton, Z_Construct_UScriptStruct_FCharacterOption_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CharacterOption.InnerSingleton;
}
// End ScriptStruct FCharacterOption

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_CharacterOption_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCharacterOption::StaticStruct, Z_Construct_UScriptStruct_FCharacterOption_Statics::NewStructOps, TEXT("CharacterOption"), &Z_Registration_Info_UScriptStruct_CharacterOption, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterOption), 1010984285U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_CharacterOption_h_3300965132(TEXT("/Script/F13"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_CharacterOption_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_CharacterOption_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
