// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ALog.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LogSubsystem.generated.h"



/**
 日志系统
 */
UCLASS(Blueprintable)
class GF_LOG_API ULogSubsystem : public UGameInstanceSubsystem,public ILog
{
	GENERATED_BODY()
public:
	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize()override;

	/*
	virtual  void Verbose(...);
	virtual void Log(...);
	virtual void Warning(...);
	virtual void Error(...);
	virtual void Fatal(...);*/
	virtual void Log(...) ;
	//virtual void Log(ELogVerbosity::Type type,...);
protected:
	//TMap<ELog_Type,UALog> LogMap;
};
