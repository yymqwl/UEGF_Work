// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"



class GF_CONFIG_API FGF_Config : public FDefaultGameModuleImpl
{
public:	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};


