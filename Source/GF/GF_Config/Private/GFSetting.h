// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GFSetting.generated.h"

/**
 * 
 */
UCLASS(Config=GFSetting,Defaultconfig)
class UGFSetting : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(config)
	FString Name;
};
