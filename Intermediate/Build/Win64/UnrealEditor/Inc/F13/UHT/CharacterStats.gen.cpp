// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/CharacterStats.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterStats() {}

// Begin Cross Module References
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
F13_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterStats();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin ScriptStruct FCharacterStats
static_assert(std::is_polymorphic<FCharacterStats>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FCharacterStats cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CharacterStats;
class UScriptStruct* FCharacterStats::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CharacterStats.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CharacterStats.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCharacterStats, (UObject*)Z_Construct_UPackage__Script_F13(), TEXT("CharacterStats"));
	}
	return Z_Registration_Info_UScriptStruct_CharacterStats.OuterSingleton;
}
template<> F13_API UScriptStruct* StaticStruct<FCharacterStats>()
{
	return FCharacterStats::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCharacterStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * A single row in our CharacterStats DataTable.\n * Contains both basic movement floats and flags/parameters for custom abilities.\n */" },
#endif
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A single row in our CharacterStats DataTable.\nContains both basic movement floats and flags/parameters for custom abilities." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Movement|Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Walking speed (cm/s). */" },
#endif
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Walking speed (cm/s)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Movement|Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sprinting speed (cm/s). */" },
#endif
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sprinting speed (cm/s)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkAccel_MetaData[] = {
		{ "Category", "Movement|Accel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Acceleration (cm/s\xc2\xb2) from Rest \xe2\x86\x92 Walk. */" },
#endif
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Acceleration (cm/s\xc2\xb2) from Rest \xe2\x86\x92 Walk." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAccel_MetaData[] = {
		{ "Category", "Movement|Accel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Acceleration (cm/s\xc2\xb2) from Walk \xe2\x86\x92 Sprint. */" },
#endif
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Acceleration (cm/s\xc2\xb2) from Walk \xe2\x86\x92 Sprint." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrakingDecelWalking_MetaData[] = {
		{ "Category", "Movement|Braking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Braking deceleration (cm/s\xc2\xb2) when walking. */" },
#endif
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Braking deceleration (cm/s\xc2\xb2) when walking." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanDash_MetaData[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Does this character have a \xe2\x80\x9c""dash\xe2\x80\x9d ability? */" },
#endif
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Does this character have a \xe2\x80\x9c""dash\xe2\x80\x9d ability?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DashDistance_MetaData[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If bCanDash = true, how far (units) does the dash move? */" },
#endif
		{ "EditCondition", "bCanDash" },
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If bCanDash = true, how far (units) does the dash move?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DashCooldown_MetaData[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If bCanDash = true, how long (seconds) is the dash cooldown? */" },
#endif
		{ "EditCondition", "bCanDash" },
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If bCanDash = true, how long (seconds) is the dash cooldown?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanDoubleJump_MetaData[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Does this character have a double\xe2\x80\x90jump? */" },
#endif
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Does this character have a double\xe2\x80\x90jump?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoubleJumpZVelocity_MetaData[] = {
		{ "Category", "Abilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If bCanDoubleJump = true, what is the double\xe2\x80\x90jump Z velocity? */" },
#endif
		{ "EditCondition", "bCanDoubleJump" },
		{ "ModuleRelativePath", "Public/CharacterStats.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If bCanDoubleJump = true, what is the double\xe2\x80\x90jump Z velocity?" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkAccel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintAccel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BrakingDecelWalking;
	static void NewProp_bCanDash_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanDash;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DashDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DashCooldown;
	static void NewProp_bCanDoubleJump_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanDoubleJump;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DoubleJumpZVelocity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCharacterStats>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStats, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStats, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSpeed_MetaData), NewProp_SprintSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_WalkAccel = { "WalkAccel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStats, WalkAccel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkAccel_MetaData), NewProp_WalkAccel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_SprintAccel = { "SprintAccel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStats, SprintAccel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAccel_MetaData), NewProp_SprintAccel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_BrakingDecelWalking = { "BrakingDecelWalking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStats, BrakingDecelWalking), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrakingDecelWalking_MetaData), NewProp_BrakingDecelWalking_MetaData) };
void Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_bCanDash_SetBit(void* Obj)
{
	((FCharacterStats*)Obj)->bCanDash = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_bCanDash = { "bCanDash", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterStats), &Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_bCanDash_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanDash_MetaData), NewProp_bCanDash_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_DashDistance = { "DashDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStats, DashDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DashDistance_MetaData), NewProp_DashDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_DashCooldown = { "DashCooldown", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStats, DashCooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DashCooldown_MetaData), NewProp_DashCooldown_MetaData) };
void Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_bCanDoubleJump_SetBit(void* Obj)
{
	((FCharacterStats*)Obj)->bCanDoubleJump = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_bCanDoubleJump = { "bCanDoubleJump", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterStats), &Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_bCanDoubleJump_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanDoubleJump_MetaData), NewProp_bCanDoubleJump_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_DoubleJumpZVelocity = { "DoubleJumpZVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterStats, DoubleJumpZVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoubleJumpZVelocity_MetaData), NewProp_DoubleJumpZVelocity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCharacterStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_SprintSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_WalkAccel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_SprintAccel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_BrakingDecelWalking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_bCanDash,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_DashDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_DashCooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_bCanDoubleJump,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterStats_Statics::NewProp_DoubleJumpZVelocity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCharacterStats_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"CharacterStats",
	Z_Construct_UScriptStruct_FCharacterStats_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterStats_Statics::PropPointers),
	sizeof(FCharacterStats),
	alignof(FCharacterStats),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterStats_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCharacterStats_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCharacterStats()
{
	if (!Z_Registration_Info_UScriptStruct_CharacterStats.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CharacterStats.InnerSingleton, Z_Construct_UScriptStruct_FCharacterStats_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CharacterStats.InnerSingleton;
}
// End ScriptStruct FCharacterStats

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_CharacterStats_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCharacterStats::StaticStruct, Z_Construct_UScriptStruct_FCharacterStats_Statics::NewStructOps, TEXT("CharacterStats"), &Z_Registration_Info_UScriptStruct_CharacterStats, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterStats), 4127423566U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_CharacterStats_h_1001182909(TEXT("/Script/F13"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_CharacterStats_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_CharacterStats_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
