// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Pantheon : ModuleRules
{
	public Pantheon(ReadOnlyTargetRules Target) : base(Target)
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
            "AIModule",
            "Sockets",
            "Networking"
        });
    }
}
