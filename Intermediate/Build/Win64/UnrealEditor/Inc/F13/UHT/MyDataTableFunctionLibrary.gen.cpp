// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/MyDataTableFunctionLibrary.h"
#include "F13/Public/CharacterOption.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyDataTableFunctionLibrary() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
F13_API UClass* Z_Construct_UClass_UMyDataTableFunctionLibrary();
F13_API UClass* Z_Construct_UClass_UMyDataTableFunctionLibrary_NoRegister();
F13_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterOption();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Class UMyDataTableFunctionLibrary Function GetCharacterOptionRow
struct Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics
{
	struct MyDataTableFunctionLibrary_eventGetCharacterOptionRow_Parms
	{
		UDataTable* DataTable;
		FName RowName;
		FCharacterOption OutRow;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DataTable" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tries to find a row in the given DataTable */" },
#endif
		{ "ModuleRelativePath", "Public/MyDataTableFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tries to find a row in the given DataTable" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DataTable;
	static const UECodeGen_Private::FNamePropertyParams NewProp_RowName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutRow;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_DataTable = { "DataTable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyDataTableFunctionLibrary_eventGetCharacterOptionRow_Parms, DataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_RowName = { "RowName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyDataTableFunctionLibrary_eventGetCharacterOptionRow_Parms, RowName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_OutRow = { "OutRow", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyDataTableFunctionLibrary_eventGetCharacterOptionRow_Parms, OutRow), Z_Construct_UScriptStruct_FCharacterOption, METADATA_PARAMS(0, nullptr) }; // 1010984285
void Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MyDataTableFunctionLibrary_eventGetCharacterOptionRow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MyDataTableFunctionLibrary_eventGetCharacterOptionRow_Parms), &Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_DataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_RowName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_OutRow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyDataTableFunctionLibrary, nullptr, "GetCharacterOptionRow", nullptr, nullptr, Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::MyDataTableFunctionLibrary_eventGetCharacterOptionRow_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::MyDataTableFunctionLibrary_eventGetCharacterOptionRow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyDataTableFunctionLibrary::execGetCharacterOptionRow)
{
	P_GET_OBJECT(UDataTable,Z_Param_DataTable);
	P_GET_PROPERTY(FNameProperty,Z_Param_RowName);
	P_GET_STRUCT_REF(FCharacterOption,Z_Param_Out_OutRow);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UMyDataTableFunctionLibrary::GetCharacterOptionRow(Z_Param_DataTable,Z_Param_RowName,Z_Param_Out_OutRow);
	P_NATIVE_END;
}
// End Class UMyDataTableFunctionLibrary Function GetCharacterOptionRow

// Begin Class UMyDataTableFunctionLibrary
void UMyDataTableFunctionLibrary::StaticRegisterNativesUMyDataTableFunctionLibrary()
{
	UClass* Class = UMyDataTableFunctionLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCharacterOptionRow", &UMyDataTableFunctionLibrary::execGetCharacterOptionRow },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyDataTableFunctionLibrary);
UClass* Z_Construct_UClass_UMyDataTableFunctionLibrary_NoRegister()
{
	return UMyDataTableFunctionLibrary::StaticClass();
}
struct Z_Construct_UClass_UMyDataTableFunctionLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyDataTableFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/MyDataTableFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyDataTableFunctionLibrary_GetCharacterOptionRow, "GetCharacterOptionRow" }, // 1996201705
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyDataTableFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMyDataTableFunctionLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyDataTableFunctionLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyDataTableFunctionLibrary_Statics::ClassParams = {
	&UMyDataTableFunctionLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyDataTableFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyDataTableFunctionLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyDataTableFunctionLibrary()
{
	if (!Z_Registration_Info_UClass_UMyDataTableFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyDataTableFunctionLibrary.OuterSingleton, Z_Construct_UClass_UMyDataTableFunctionLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyDataTableFunctionLibrary.OuterSingleton;
}
template<> F13_API UClass* StaticClass<UMyDataTableFunctionLibrary>()
{
	return UMyDataTableFunctionLibrary::StaticClass();
}
UMyDataTableFunctionLibrary::UMyDataTableFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyDataTableFunctionLibrary);
UMyDataTableFunctionLibrary::~UMyDataTableFunctionLibrary() {}
// End Class UMyDataTableFunctionLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_MyDataTableFunctionLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyDataTableFunctionLibrary, UMyDataTableFunctionLibrary::StaticClass, TEXT("UMyDataTableFunctionLibrary"), &Z_Registration_Info_UClass_UMyDataTableFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyDataTableFunctionLibrary), 3291186212U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_MyDataTableFunctionLibrary_h_3225255305(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_MyDataTableFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_MyDataTableFunctionLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
