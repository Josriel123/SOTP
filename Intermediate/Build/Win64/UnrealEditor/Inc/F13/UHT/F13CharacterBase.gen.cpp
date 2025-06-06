// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13CharacterBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13CharacterBase() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
F13_API UClass* Z_Construct_UClass_AF13CharacterBase();
F13_API UClass* Z_Construct_UClass_AF13CharacterBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13CharacterBase
void AF13CharacterBase::StaticRegisterNativesAF13CharacterBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AF13CharacterBase);
UClass* Z_Construct_UClass_AF13CharacterBase_NoRegister()
{
	return AF13CharacterBase::StaticClass();
}
struct Z_Construct_UClass_AF13CharacterBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Base class for both Killer and Survivor pawns.\n *  Implements:\n *   - Enhanced Input setup (IMC, IA_Move, IA_Look, IA_Jump, IA_Sprint)\n *   - Walk / Look / Jump / Sprint logic\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "F13CharacterBase.h" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base class for both Killer and Survivor pawns.\nImplements:\n - Enhanced Input setup (IMC, IA_Move, IA_Look, IA_Jump, IA_Sprint)\n - Walk / Look / Jump / Sprint logic" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IMC_JasonPart3_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Which Enhanced Input Mapping Context to use (set this in Blueprint \xe2\x86\x92 Class Defaults). */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Which Enhanced Input Mapping Context to use (set this in Blueprint \xe2\x86\x92 Class Defaults)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Move_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Action: Move (Vector2D). Pressing W/A/S/D should feed here. */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Action: Move (Vector2D). Pressing W/A/S/D should feed here." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Look_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Action: Look (Vector2D). Mouse X/Y drive this. */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Action: Look (Vector2D). Mouse X/Y drive this." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Jump_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Action: Jump (Triggered). Space bar, etc. */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Action: Jump (Triggered). Space bar, etc." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Sprint_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Action: Sprint (Triggered). Left Shift, etc. */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Action: Sprint (Triggered). Left Shift, etc." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Movement|Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Basic walking speed (cm/s) */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic walking speed (cm/s)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Movement|Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sprinting speed (cm/s) */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sprinting speed (cm/s)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkAccel_MetaData[] = {
		{ "Category", "Movement|Accel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Acceleration (cm/s\xc2\xb2) when starting from Rest to Walk */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Acceleration (cm/s\xc2\xb2) when starting from Rest to Walk" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAccel_MetaData[] = {
		{ "Category", "Movement|Accel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Acceleration (cm/s\xc2\xb2) when going from Walk to Sprint */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Acceleration (cm/s\xc2\xb2) when going from Walk to Sprint" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrakingDecelWalking_MetaData[] = {
		{ "Category", "Movement|Accel" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spring arm that holds the camera behind the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spring arm that holds the camera behind the character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The actual camera that follows the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The actual camera that follows the character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraHeightOffset_MetaData[] = {
		{ "Category", "Camera|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Camera settings\n" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraDistance_MetaData[] = {
		{ "Category", "Camera|Settings" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraRelativeRotation_MetaData[] = {
		{ "Category", "Camera|Settings" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterStatsTable_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//___________DataTable_____________\n" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "___________DataTable_____________" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatsRowName_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IMC_JasonPart3;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Move;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Look;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Jump;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Sprint;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkAccel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintAccel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BrakingDecelWalking;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraHeightOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraDistance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraRelativeRotation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterStatsTable;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StatsRowName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13CharacterBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IMC_JasonPart3 = { "IMC_JasonPart3", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IMC_JasonPart3), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IMC_JasonPart3_MetaData), NewProp_IMC_JasonPart3_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Move = { "IA_Move", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IA_Move), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Move_MetaData), NewProp_IA_Move_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Look = { "IA_Look", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IA_Look), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Look_MetaData), NewProp_IA_Look_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Jump = { "IA_Jump", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IA_Jump), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Jump_MetaData), NewProp_IA_Jump_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Sprint = { "IA_Sprint", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IA_Sprint), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Sprint_MetaData), NewProp_IA_Sprint_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSpeed_MetaData), NewProp_SprintSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_WalkAccel = { "WalkAccel", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, WalkAccel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkAccel_MetaData), NewProp_WalkAccel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_SprintAccel = { "SprintAccel", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, SprintAccel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAccel_MetaData), NewProp_SprintAccel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_BrakingDecelWalking = { "BrakingDecelWalking", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, BrakingDecelWalking), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrakingDecelWalking_MetaData), NewProp_BrakingDecelWalking_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraHeightOffset = { "CameraHeightOffset", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CameraHeightOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraHeightOffset_MetaData), NewProp_CameraHeightOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraDistance = { "CameraDistance", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CameraDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraDistance_MetaData), NewProp_CameraDistance_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraRelativeRotation = { "CameraRelativeRotation", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CameraRelativeRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraRelativeRotation_MetaData), NewProp_CameraRelativeRotation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CharacterStatsTable = { "CharacterStatsTable", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CharacterStatsTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterStatsTable_MetaData), NewProp_CharacterStatsTable_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_StatsRowName = { "StatsRowName", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, StatsRowName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatsRowName_MetaData), NewProp_StatsRowName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AF13CharacterBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IMC_JasonPart3,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Look,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Jump,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Sprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_SprintSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_WalkAccel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_SprintAccel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_BrakingDecelWalking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraHeightOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraRelativeRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CharacterStatsTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_StatsRowName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13CharacterBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AF13CharacterBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13CharacterBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AF13CharacterBase_Statics::ClassParams = {
	&AF13CharacterBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AF13CharacterBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AF13CharacterBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AF13CharacterBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AF13CharacterBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AF13CharacterBase()
{
	if (!Z_Registration_Info_UClass_AF13CharacterBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AF13CharacterBase.OuterSingleton, Z_Construct_UClass_AF13CharacterBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AF13CharacterBase.OuterSingleton;
}
template<> F13_API UClass* StaticClass<AF13CharacterBase>()
{
	return AF13CharacterBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13CharacterBase);
AF13CharacterBase::~AF13CharacterBase() {}
// End Class AF13CharacterBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13CharacterBase, AF13CharacterBase::StaticClass, TEXT("AF13CharacterBase"), &Z_Registration_Info_UClass_AF13CharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13CharacterBase), 3836492648U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_1540902244(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
