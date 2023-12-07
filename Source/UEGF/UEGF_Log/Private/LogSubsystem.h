// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LogSubsystem.generated.h"



/**
 日志系统
 */
UCLASS(Blueprintable)
class UEGF_LOG_API ULogSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize()override;
protected:
	/*
	UPROPERTY(config = UEGF,EditAnywhere)
	int   x;*/
};
