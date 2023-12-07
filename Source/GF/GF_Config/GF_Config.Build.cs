// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GF_Config : ModuleRules
{
	public GF_Config(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore"
        });
        //PrivateDependencyModuleNames.AddRange(new string[] {  });
    }
}
