// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEGF_Work : ModuleRules
{
	public UEGF_Work(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore"//,"ApplicationCore"
		});
		bUseRTTI = true;
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			//"GF_Log",
			//"GF_Config"
			"GF_Core",
			"Soci"
		});
		PrivateIncludePaths.AddRange(new string[]
		{
			"GF/GF_Core/Public",
			"Soci/include"
			//"Soci/include"
		});
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
