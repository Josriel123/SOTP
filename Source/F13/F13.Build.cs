// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class F13 : ModuleRules
{
	public F13(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "OnlineSubsystem",
            "OnlineSubsystemUtils",
            "OnlineSubsystemEOS",
            "OnlineSubsystemNull",
            "HostMigrationSystem",
            "AIModule"
        });
    }
}
