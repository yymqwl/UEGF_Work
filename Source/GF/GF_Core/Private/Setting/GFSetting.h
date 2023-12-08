// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GFSetting.generated.h"

/**
 * 
 */
UCLASS(Config=GFSetting,Defaultconfig)//Defaultconfig
class GF_CORE_API UGFSetting : public UObject
{
	GENERATED_BODY()
public:
	/*UPROPERTY(config)
	FString Name;
	UPROPERTY(Config)
	ELog_Type Log_Type;*/
};
