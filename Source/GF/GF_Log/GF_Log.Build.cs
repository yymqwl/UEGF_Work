// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GF_Log : ModuleRules
{
	public GF_Log(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PrivateDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine", 
			"InputCore"
		});
	}
}
