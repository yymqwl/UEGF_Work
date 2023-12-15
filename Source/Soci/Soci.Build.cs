// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class Soci : ModuleRules
{
	protected readonly string Version = "4.0.3";
	protected readonly string Lib_Soci_Core = "libsoci_core_4_0.lib";
	protected readonly string Lib_Soci_Odbc = "libsoci_odbc_4_0.lib";

	protected  string Lib_Path_Win
	{
		get
		{
			return Path.Combine(ModuleDirectory,"lib", "Win64", "Release");
		}
	}
		
		
		//= Path.Combine(ModuleDirectory,"/Soci","lib", "Win64", "Release");
	public Soci(ReadOnlyTargetRules Target) : base(Target)
	{
		
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PrivateDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine", 
		});
		
		/*
		PublicDefinitions.AddRange(new []
		{
			"SOCI_LOG =1 "
		});*/

		bUseRTTI = true;//开启RTTI 使用dynamic_cast功能
		
		PrivateIncludePaths.AddRange(new string[]
		{
			"Soci/include",
			//"include/soci",
		});
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.AddRange(
				new []
				{
					Path.Combine(Lib_Path_Win,Lib_Soci_Core),
					Path.Combine(Lib_Path_Win,Lib_Soci_Odbc),
				});
		}
		
	}
}
