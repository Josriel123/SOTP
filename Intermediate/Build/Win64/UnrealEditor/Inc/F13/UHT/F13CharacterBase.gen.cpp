// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13CharacterBase.h"
#include "UObject/CoreNet.h"
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

// Begin Class AF13CharacterBase Function OnRep_IsSprinting
struct Z_Construct_UFunction_AF13CharacterBase_OnRep_IsSprinting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called on clients when bIsSprinting changes */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called on clients when bIsSprinting changes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AF13CharacterBase_OnRep_IsSprinting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AF13CharacterBase, nullptr, "OnRep_IsSprinting", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13CharacterBase_OnRep_IsSprinting_Statics::Function_MetaDataParams), Z_Construct_UFunction_AF13CharacterBase_OnRep_IsSprinting_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AF13CharacterBase_OnRep_IsSprinting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AF13CharacterBase_OnRep_IsSprinting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AF13CharacterBase::execOnRep_IsSprinting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_IsSprinting();
	P_NATIVE_END;
}
// End Class AF13CharacterBase Function OnRep_IsSprinting

// Begin Class AF13CharacterBase Function ServerSetSprinting
struct F13CharacterBase_eventServerSetSprinting_Parms
{
	bool bNewSprinting;
};
static const FName NAME_AF13CharacterBase_ServerSetSprinting = FName(TEXT("ServerSetSprinting"));
void AF13CharacterBase::ServerSetSprinting(bool bNewSprinting)
{
	F13CharacterBase_eventServerSetSprinting_Parms Parms;
	Parms.bNewSprinting=bNewSprinting ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AF13CharacterBase_ServerSetSprinting);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** RPC to tell the server \xe2\x80\x9cI started/stopped sprinting\xe2\x80\x9d */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "RPC to tell the server \xe2\x80\x9cI started/stopped sprinting\xe2\x80\x9d" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bNewSprinting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewSprinting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::NewProp_bNewSprinting_SetBit(void* Obj)
{
	((F13CharacterBase_eventServerSetSprinting_Parms*)Obj)->bNewSprinting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::NewProp_bNewSprinting = { "bNewSprinting", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(F13CharacterBase_eventServerSetSprinting_Parms), &Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::NewProp_bNewSprinting_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::NewProp_bNewSprinting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AF13CharacterBase, nullptr, "ServerSetSprinting", nullptr, nullptr, Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::PropPointers), sizeof(F13CharacterBase_eventServerSetSprinting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80240CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::Function_MetaDataParams), Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::Function_MetaDataParams) };
static_assert(sizeof(F13CharacterBase_eventServerSetSprinting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AF13CharacterBase::execServerSetSprinting)
{
	P_GET_UBOOL(Z_Param_bNewSprinting);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ServerSetSprinting_Validate(Z_Param_bNewSprinting))
	{
		RPC_ValidateFailed(TEXT("ServerSetSprinting_Validate"));
		return;
	}
	P_THIS->ServerSetSprinting_Implementation(Z_Param_bNewSprinting);
	P_NATIVE_END;
}
// End Class AF13CharacterBase Function ServerSetSprinting

// Begin Class AF13CharacterBase
void AF13CharacterBase::StaticRegisterNativesAF13CharacterBase()
{
	UClass* Class = AF13CharacterBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnRep_IsSprinting", &AF13CharacterBase::execOnRep_IsSprinting },
		{ "ServerSetSprinting", &AF13CharacterBase::execServerSetSprinting },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "F13CharacterBase.h" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterStatsTable_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stats (filled from your DataTable via Blueprint) */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stats (filled from your DataTable via Blueprint)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatsRowName_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Movement|Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Speeds & accels (populated in BeginPlay) */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Speeds & accels (populated in BeginPlay)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Movement|Speed" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkAccel_MetaData[] = {
		{ "Category", "Movement|Accel" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAccel_MetaData[] = {
		{ "Category", "Movement|Accel" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrakingDecelWalking_MetaData[] = {
		{ "Category", "Movement|Accel" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IMC_JasonPart3_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enhanced Input assets (set via Blueprint defaults) */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enhanced Input assets (set via Blueprint defaults)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Move_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Look_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Jump_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Sprint_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//-------------Camera setup----------------------------\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "-------------Camera setup----------------------------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraDistance_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// If you have these properties in Blueprint:\n" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If you have these properties in Blueprint:" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraHeightOffset_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraRelativeRotation_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSprinting_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sprint state, replicated to server so movement stays in sync */" },
#endif
		{ "ModuleRelativePath", "Public/F13CharacterBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sprint state, replicated to server so movement stays in sync" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterStatsTable;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StatsRowName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkAccel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintAccel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BrakingDecelWalking;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IMC_JasonPart3;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Move;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Look;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Jump;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Sprint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraHeightOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraRelativeRotation;
	static void NewProp_bIsSprinting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSprinting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AF13CharacterBase_OnRep_IsSprinting, "OnRep_IsSprinting" }, // 3652445926
		{ &Z_Construct_UFunction_AF13CharacterBase_ServerSetSprinting, "ServerSetSprinting" }, // 1190207242
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13CharacterBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CharacterStatsTable = { "CharacterStatsTable", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CharacterStatsTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterStatsTable_MetaData), NewProp_CharacterStatsTable_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_StatsRowName = { "StatsRowName", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, StatsRowName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatsRowName_MetaData), NewProp_StatsRowName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSpeed_MetaData), NewProp_SprintSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_WalkAccel = { "WalkAccel", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, WalkAccel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkAccel_MetaData), NewProp_WalkAccel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_SprintAccel = { "SprintAccel", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, SprintAccel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAccel_MetaData), NewProp_SprintAccel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_BrakingDecelWalking = { "BrakingDecelWalking", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, BrakingDecelWalking), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrakingDecelWalking_MetaData), NewProp_BrakingDecelWalking_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IMC_JasonPart3 = { "IMC_JasonPart3", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IMC_JasonPart3), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IMC_JasonPart3_MetaData), NewProp_IMC_JasonPart3_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Move = { "IA_Move", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IA_Move), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Move_MetaData), NewProp_IA_Move_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Look = { "IA_Look", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IA_Look), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Look_MetaData), NewProp_IA_Look_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Jump = { "IA_Jump", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IA_Jump), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Jump_MetaData), NewProp_IA_Jump_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Sprint = { "IA_Sprint", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, IA_Sprint), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Sprint_MetaData), NewProp_IA_Sprint_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraDistance = { "CameraDistance", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CameraDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraDistance_MetaData), NewProp_CameraDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraHeightOffset = { "CameraHeightOffset", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CameraHeightOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraHeightOffset_MetaData), NewProp_CameraHeightOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraRelativeRotation = { "CameraRelativeRotation", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13CharacterBase, CameraRelativeRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraRelativeRotation_MetaData), NewProp_CameraRelativeRotation_MetaData) };
void Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_bIsSprinting_SetBit(void* Obj)
{
	((AF13CharacterBase*)Obj)->bIsSprinting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_bIsSprinting = { "bIsSprinting", "OnRep_IsSprinting", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AF13CharacterBase), &Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_bIsSprinting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSprinting_MetaData), NewProp_bIsSprinting_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AF13CharacterBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CharacterStatsTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_StatsRowName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_SprintSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_WalkAccel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_SprintAccel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_BrakingDecelWalking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IMC_JasonPart3,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Look,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Jump,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_IA_Sprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraHeightOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_CameraRelativeRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13CharacterBase_Statics::NewProp_bIsSprinting,
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
	FuncInfo,
	Z_Construct_UClass_AF13CharacterBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
void AF13CharacterBase::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_bIsSprinting(TEXT("bIsSprinting"));
	const bool bIsValid = true
		&& Name_bIsSprinting == ClassReps[(int32)ENetFields_Private::bIsSprinting].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AF13CharacterBase"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13CharacterBase);
AF13CharacterBase::~AF13CharacterBase() {}
// End Class AF13CharacterBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13CharacterBase, AF13CharacterBase::StaticClass, TEXT("AF13CharacterBase"), &Z_Registration_Info_UClass_AF13CharacterBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13CharacterBase), 4233159265U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_2245308605(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13CharacterBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
