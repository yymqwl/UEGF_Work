// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GF_Core : ModuleRules
{
	public GF_Core(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
        });
        PrivateIncludePaths.AddRange(new string[]
        {
	        "GF/GF_Core/Public"
        });
        //PrivateDependencyModuleNames.AddRange(new string[] {  });
    }
}
