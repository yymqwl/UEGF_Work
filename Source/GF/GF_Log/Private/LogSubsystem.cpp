// Fill out your copyright notice in the Description page of Project Settings.


#include "LogSubsystem.h"
#include "ALog.h"


void ULogSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	
	//GConfig->GetInt()
	//GF_LOG(TEXT("ULogSubsystem Initialize"));
}



void ULogSubsystem::Deinitialize()
{
	//GF_LOG(TEXT("ULogSubsystem Deinitialize"));
}


