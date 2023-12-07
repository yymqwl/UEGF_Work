// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CGF : ModuleRules
{
	public CGF(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
		
		/*
		PrivateIncludePaths.AddRange(new string[]
		{
		});*/
	}
}
