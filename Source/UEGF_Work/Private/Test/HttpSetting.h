// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "HttpSetting.generated.h"

/**
 * 
 */
UCLASS(Config=HttpSetting,Defaultconfig)
class   UHttpSetting  : public UObject
{
	GENERATED_BODY()
public:
	//UHttpSetting();
	UPROPERTY(config)
	int32						MaxParallel;//最大的下载并行数
	UPROPERTY(config)
	int32						MaxTryCount;//最大的重连次数
	UPROPERTY(config)
	int32						RequestKBSize;//每个子任务的大小
	UPROPERTY(config)
	float						ResponseTimeout;//请求超时的时间
};
