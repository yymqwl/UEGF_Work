// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "ILog.h"
#include "ALog.generated.h"
//定义区域
DECLARE_LOG_CATEGORY_EXTERN(Log_GF,Log,All);
//////////////////
///

#define GF_LOG(Format, ...) \
	UE_LOG(Log_GF,Log,Format,##__VA_ARGS__)

//#define GF_LOG_TRACK() GF_LOG(TEXT("方法:%s 文件%s 行数:%d"),*FString(__FUNCTION__), *FString(__FILE__), __LINE__)



UCLASS(Abstract)
class GF_LOG_API UALog : public UObject ,public ILog
{
	GENERATED_BODY()
};