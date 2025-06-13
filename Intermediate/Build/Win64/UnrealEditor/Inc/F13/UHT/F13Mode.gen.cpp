// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/F13Mode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeF13Mode() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
F13_API UClass* Z_Construct_UClass_AF13Mode();
F13_API UClass* Z_Construct_UClass_AF13Mode_NoRegister();
HOSTMIGRATIONSYSTEM_API UClass* Z_Construct_UClass_AHMS_GameMode();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class AF13Mode Function HandleCharacterSelected
struct Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics
{
	struct F13Mode_eventHandleCharacterSelected_Parms
	{
		APlayerController* SelectingPC;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// This is the function that actually spawns the pawn for a given PlayerController\n" },
#endif
		{ "ModuleRelativePath", "F13Mode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This is the function that actually spawns the pawn for a given PlayerController" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectingPC;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::NewProp_SelectingPC = { "SelectingPC", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(F13Mode_eventHandleCharacterSelected_Parms, SelectingPC), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::NewProp_SelectingPC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AF13Mode, nullptr, "HandleCharacterSelected", nullptr, nullptr, Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::F13Mode_eventHandleCharacterSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::F13Mode_eventHandleCharacterSelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AF13Mode_HandleCharacterSelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AF13Mode_HandleCharacterSelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AF13Mode::execHandleCharacterSelected)
{
	P_GET_OBJECT(APlayerController,Z_Param_SelectingPC);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCharacterSelected(Z_Param_SelectingPC);
	P_NATIVE_END;
}
// End Class AF13Mode Function HandleCharacterSelected

// Begin Class AF13Mode
void AF13Mode::StaticRegisterNativesAF13Mode()
{
	UClass* Class = AF13Mode::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HandleCharacterSelected", &AF13Mode::execHandleCharacterSelected },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		{ "ModuleRelativePath", "F13Mode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PawnToSpawn_MetaData[] = {
		{ "Category", "Variables" },
		{ "ModuleRelativePath", "F13Mode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_PawnToSpawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AF13Mode_HandleCharacterSelected, "HandleCharacterSelected" }, // 2022002596
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AF13Mode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AF13Mode_Statics::NewProp_PawnToSpawn = { "PawnToSpawn", nullptr, (EPropertyFlags)0x0014000000000004, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AF13Mode, PawnToSpawn), Z_Construct_UClass_UClass, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PawnToSpawn_MetaData), NewProp_PawnToSpawn_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AF13Mode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AF13Mode_Statics::NewProp_PawnToSpawn,
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
	FuncInfo,
	Z_Construct_UClass_AF13Mode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13Mode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AF13Mode, AF13Mode::StaticClass, TEXT("AF13Mode"), &Z_Registration_Info_UClass_AF13Mode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AF13Mode), 447412989U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13Mode_h_3000951549(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13Mode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_F13Mode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
