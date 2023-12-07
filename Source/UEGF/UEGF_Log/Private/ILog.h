// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ILog.generated.h"

// This class does not need to be modified.
UINTERFACE()
class ULog : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

class UEGF_LOG_API ILog
{
	GENERATED_BODY()
public:
	void Verbose(...);
	void Log(...);
	void Warning(...);
	void Error(...);
	void Fatal(...);
	void Log(ELogVerbosity::Type type,...);
};