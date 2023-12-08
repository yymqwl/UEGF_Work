// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ILog.generated.h"


/*
//定义区域
DECLARE_LOG_CATEGORY_EXTERN(GF_Log,Log,All);
//////////////////
///

#define GF_LOG(Format, ...) \
UE_LOG(GF_Log,Log,Format,##__VA_ARGS__)

*/

//GF_LOG_API  void  PrintTraceStack(int Depth = 5);

//#define GF_LOG_TRACK() GF_LOG(TEXT("方法:%s 文件%s 行数:%d"),*FString(__FUNCTION__), *FString(__FILE__), __LINE__)


/*
UENUM()
enum class ELog_Type:uint8
{
	///** Not used 
	ENoLogging   = 0x0,
	///默认
	ELog = 0x1,
};

ENUM_CLASS_FLAGS(ELog_Type);*/
// This class does not need to be modified.
UINTERFACE()
class ULog : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

class GF_LOG_API ILog
{
	GENERATED_BODY()
public:
	void Verbose(...);
	void Log(...);
	void Warning(...);
	void Error(...);
	void Fatal(...);
	//void Log(ELogVerbosity::Type type,...);
};