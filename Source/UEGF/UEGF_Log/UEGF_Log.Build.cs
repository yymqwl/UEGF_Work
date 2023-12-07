// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEGF_Log : ModuleRules
{
	public UEGF_Log(ReadOnlyTargetRules Target) : base(Target)
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
