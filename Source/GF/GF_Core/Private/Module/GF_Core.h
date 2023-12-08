// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"



class GF_CORE_API FGF_Core : public FDefaultGameModuleImpl
{
public:	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};


///示例展示
/*
const UGFSetting* Config = GetDefault<UGFSetting>();
UE_LOG(LogTemp,Log,TEXT("%s"),*Config->Name);

auto config = GetMutableDefault<UGFSetting>();
config->Name  = TEXT("xxx");
config->SaveConfig();
auto gconfig =GConfig;
	
//UE_LOG(LogTemp,Log,TEXT("%s"),*gconfig->);
auto cf =GConfig->Find(config->GetDefaultConfigFilename());

FString Value;
GConfig->GetString(TEXT("/Script/GF_Config.GFSetting"), TEXT("Name"), Value, config->GetClass()->GetConfigName() );

config->UpdateDefaultConfigFile()
GConfig->LoadGlobalIniFile()
*/