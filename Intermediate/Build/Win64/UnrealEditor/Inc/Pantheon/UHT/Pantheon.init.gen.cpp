// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePantheon_init() {}
	PANTHEON_API UFunction* Z_Construct_UDelegateFunction_Pantheon_OnCharacterSelectedSignature__DelegateSignature();
	PANTHEON_API UFunction* Z_Construct_UDelegateFunction_Pantheon_OnPlayersChanged__DelegateSignature();
	PANTHEON_API UFunction* Z_Construct_UDelegateFunction_Pantheon_OnReadyChanged__DelegateSignature();
	PANTHEON_API UFunction* Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature();
	PANTHEON_API UFunction* Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature();
	PANTHEON_API UFunction* Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Pantheon;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Pantheon()
	{
		if (!Z_Registration_Info_UPackage__Script_Pantheon.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Pantheon_OnCharacterSelectedSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Pantheon_OnPlayersChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Pantheon_OnReadyChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Pantheon_OnSessionCreated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Pantheon_OnSessionJoined__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Pantheon_OnSessionListReady__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Pantheon",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x28D2CEAF,
				0x8EFB7ADB,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Pantheon.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Pantheon.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Pantheon(Z_Construct_UPackage__Script_Pantheon, TEXT("/Script/Pantheon"), Z_Registration_Info_UPackage__Script_Pantheon, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x28D2CEAF, 0x8EFB7ADB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
