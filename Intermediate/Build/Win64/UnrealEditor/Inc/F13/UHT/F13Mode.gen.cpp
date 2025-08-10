// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/F13Mode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13Mode() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
F13_API UClass* Z_Construct_UClass_AF13Mode();
F13_API UClass* Z_Construct_UClass_AF13Mode_NoRegister();
HOSTMIGRATIONSYSTEM_API UClass* Z_Construct_UClass_AHMS_GameMode();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13Mode
void AF13Mode::StaticRegisterNativesAF13Mode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AF13Mode);
UClass* Z_Construct_UClass_AF13Mode_NoRegister()
{
	return AF13Mode::StaticClass();
}
struct Z_Construct_UClass_AF13Mode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "F13Mode.h" },
		{ "ModuleRelativePath", "Public/F13Mode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PawnToSpawn_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "Public/F13Mode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BotControllerClass_MetaData[] = {
		{ "Category", "Bots" },
		{ "ModuleRelativePath", "Public/F13Mode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsRehostGame_MetaData[] = {
		{ "Category", "F13Mode" },
		{ "ModuleRelativePath", "Public/F13Mode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PendingSilentRemovals_MetaData[] = {
		{ "ModuleRelativePath", "Public/F13Mode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_PawnToSpawn;
	static const UECodeGen_Private::FClassPropertyParams NewProp_BotControllerClass;
	static void NewProp_bIsRehostGame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRehostGame;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_PendingSilentRemovals_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_PendingSilentRemovals;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13Mode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AF13Mode_Statics::NewProp_PawnToSpawn = { "PawnToSpawn", nullptr, (EPropertyFlags)0x0014000000000004, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13Mode, PawnToSpawn), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PawnToSpawn_MetaData), NewProp_PawnToSpawn_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AF13Mode_Statics::NewProp_BotControllerClass = { "BotControllerClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13Mode, BotControllerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AAIController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BotControllerClass_MetaData), NewProp_BotControllerClass_MetaData) };
void Z_Construct_UClass_AF13Mode_Statics::NewProp_bIsRehostGame_SetBit(void* Obj)
{
	((AF13Mode*)Obj)->bIsRehostGame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AF13Mode_Statics::NewProp_bIsRehostGame = { "bIsRehostGame", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AF13Mode), &Z_Construct_UClass_AF13Mode_Statics::NewProp_bIsRehostGame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsRehostGame_MetaData), NewProp_bIsRehostGame_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_AF13Mode_Statics::NewProp_PendingSilentRemovals_ElementProp = { "PendingSilentRemovals", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_AF13Mode_Statics::NewProp_PendingSilentRemovals = { "PendingSilentRemovals", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13Mode, PendingSilentRemovals), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PendingSilentRemovals_MetaData), NewProp_PendingSilentRemovals_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AF13Mode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13Mode_Statics::NewProp_PawnToSpawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13Mode_Statics::NewProp_BotControllerClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13Mode_Statics::NewProp_bIsRehostGame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13Mode_Statics::NewProp_PendingSilentRemovals_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13Mode_Statics::NewProp_PendingSilentRemovals,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13Mode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AF13Mode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHMS_GameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AF13Mode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AF13Mode_Statics::ClassParams = {
	&AF13Mode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AF13Mode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AF13Mode_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AF13Mode_Statics::Class_MetaDataParams), Z_Construct_UClass_AF13Mode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AF13Mode()
{
	if (!Z_Registration_Info_UClass_AF13Mode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AF13Mode.OuterSingleton, Z_Construct_UClass_AF13Mode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AF13Mode.OuterSingleton;
}
template<> F13_API UClass* StaticClass<AF13Mode>()
{
	return AF13Mode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AF13Mode);
AF13Mode::~AF13Mode() {}
// End Class AF13Mode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13Mode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13Mode, AF13Mode::StaticClass, TEXT("AF13Mode"), &Z_Registration_Info_UClass_AF13Mode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13Mode), 4169569151U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13Mode_h_475665584(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13Mode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_F13Mode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
