// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PantheonGameSession.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePantheonGameSession() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameSession();
PANTHEON_API UClass* Z_Construct_UClass_APantheonGameSession();
PANTHEON_API UClass* Z_Construct_UClass_APantheonGameSession_NoRegister();
UPackage* Z_Construct_UPackage__Script_Pantheon();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APantheonGameSession *****************************************************
void APantheonGameSession::StaticRegisterNativesAPantheonGameSession()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_APantheonGameSession;
UClass* APantheonGameSession::GetPrivateStaticClass()
{
	using TClass = APantheonGameSession;
	if (!Z_Registration_Info_UClass_APantheonGameSession.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PantheonGameSession"),
			Z_Registration_Info_UClass_APantheonGameSession.InnerSingleton,
			StaticRegisterNativesAPantheonGameSession,
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
	return Z_Registration_Info_UClass_APantheonGameSession.InnerSingleton;
}
UClass* Z_Construct_UClass_APantheonGameSession_NoRegister()
{
	return APantheonGameSession::GetPrivateStaticClass();
}
struct Z_Construct_UClass_APantheonGameSession_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Custom GameSession that skips duplicate bot registration after\n    host-migration and logs Public / Registered counts. */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PantheonGameSession.h" },
		{ "ModuleRelativePath", "Public/PantheonGameSession.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom GameSession that skips duplicate bot registration after\n   host-migration and logs Public / Registered counts." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APantheonGameSession>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APantheonGameSession_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameSession,
	(UObject* (*)())Z_Construct_UPackage__Script_Pantheon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonGameSession_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APantheonGameSession_Statics::ClassParams = {
	&APantheonGameSession::StaticClass,
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
	0x008003A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APantheonGameSession_Statics::Class_MetaDataParams), Z_Construct_UClass_APantheonGameSession_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APantheonGameSession()
{
	if (!Z_Registration_Info_UClass_APantheonGameSession.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APantheonGameSession.OuterSingleton, Z_Construct_UClass_APantheonGameSession_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APantheonGameSession.OuterSingleton;
}
APantheonGameSession::APantheonGameSession(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APantheonGameSession);
APantheonGameSession::~APantheonGameSession() {}
// ********** End Class APantheonGameSession *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h__Script_Pantheon_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APantheonGameSession, APantheonGameSession::StaticClass, TEXT("APantheonGameSession"), &Z_Registration_Info_UClass_APantheonGameSession, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APantheonGameSession), 1303167107U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h__Script_Pantheon_2373485136(TEXT("/Script/Pantheon"),
	Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h__Script_Pantheon_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joelb_source_repos_SOTP_Source_Pantheon_Public_PantheonGameSession_h__Script_Pantheon_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
