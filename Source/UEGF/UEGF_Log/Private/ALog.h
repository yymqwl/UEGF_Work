// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "ILog.h"
#include "ALog.generated.h"
//定义区域
DECLARE_LOG_CATEGORY_EXTERN(Log_UEGF,Log,All);
//////////////////
///

#define UEGF_LOG(Format, ...) \
	UE_LOG(Log_UEGF,Log,Format,##__VA_ARGS__)

//#define UEGF_LOG_TRACK() UEGF_LOG(TEXT("方法:%s 文件%s 行数:%d"),*FString(__FUNCTION__), *FString(__FILE__), __LINE__)



UCLASS(Abstract)
class UEGF_LOG_API UALog : public UObject ,public ILog
{
	GENERATED_BODY()
};