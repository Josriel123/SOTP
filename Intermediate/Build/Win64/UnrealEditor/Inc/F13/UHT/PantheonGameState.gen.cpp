// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "F13/Public/PantheonGameState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheonGameState() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameState();
F13_API UClass* Z_Construct_UClass_APantheonGameState();
F13_API UClass* Z_Construct_UClass_APantheonGameState_NoRegister();
F13_API UFunction* Z_Construct_UDelegateFunction_F13_OnPlayersChanged__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_F13();
// End Cross Module References

// Begin Delegate FOnPlayersChanged
struct Z_Construct_UDelegateFunction_F13_OnPlayersChanged__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PantheonGameState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_F13_OnPlayersChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_F13, nullptr, "OnPlayersChanged__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_F13_OnPlayersChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_F13_OnPlayersChanged__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_F13_OnPlayersChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_F13_OnPlayersChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPlayersChanged_DelegateWrapper(const FMulticastScriptDelegate& OnPlayersChanged)
{
	OnPlayersChanged.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOnPlayersChanged

// Begin Class APantheonGameState
void APantheonGameState::StaticRegisterNativesAPantheonGameState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APantheonGameState);
UClass* Z_Construct_UClass_APantheonGameState_NoRegister()
{
	return APantheonGameState::StaticClass();
}
struct Z_Construct_UClass_APantheonGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PantheonGameState.h" },
		{ "ModuleRelativePath", "Public/PantheonGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APantheonGameState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APantheonGameState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameState,
	(UObject* (*)())Z_Construct_UPackage__Script_F13,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonGameState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APantheonGameState_Statics::ClassParams = {
	&APantheonGameState::StaticClass,
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
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonGameState_Statics::Class_MetaDataParams), Z_Construct_UClass_APantheonGameState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APantheonGameState()
{
	if (!Z_Registration_Info_UClass_APantheonGameState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APantheonGameState.OuterSingleton, Z_Construct_UClass_APantheonGameState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APantheonGameState.OuterSingleton;
}
template<> F13_API UClass* StaticClass<APantheonGameState>()
{
	return APantheonGameState::StaticClass();
}
APantheonGameState::APantheonGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonGameState);
APantheonGameState::~APantheonGameState() {}
// End Class APantheonGameState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonGameState, APantheonGameState::StaticClass, TEXT("APantheonGameState"), &Z_Registration_Info_UClass_APantheonGameState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonGameState), 85366939U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_2689511078(TEXT("/Script/F13"),
	Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_OneDrive_Documents_Unreal_Projects_F13_Source_F13_Public_PantheonGameState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
