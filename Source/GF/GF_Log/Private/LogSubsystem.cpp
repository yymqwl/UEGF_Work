// Fill out your copyright notice in the Description page of Project Settings.


#include "LogSubsystem.h"
#include "ALog.h"
#include "GFCoreGlobals.h"


void ULogSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);


	/*auto LogSetting = GetDefault<UGF_LogSetting>();
	check(LogSetting);
	
	GF_LOG(TEXT("闪退:1"));
	UE_LOG(GF_Log,Warning,TEXT("闪退:2"));
	*/
	
	//GF_LOG(TEXT("闪退:1"));
	/*if (LogSetting == nullptr)
	{
		GF_LOG(TEXT("闪退:%s"),LogSetting->Log_Type);
		checkf(LogSetting,TEXT("闪退"));
		if ( EnumHasAnyFlags(LogSetting->Log_Type,ELog_Type::ELog)  )
		{
			
		}
	}*/
	//BytesToHex()
	//PrintTraceStack();
	
	//UE_LOG()
	
	//GetStaticEnum()
	//GF_LOG(TEXT("ULogSubsystem Initialize"));
}

void ULogSubsystem::Log(...)
{
	
}
/*
void  ULogSubsystem::Log(ELogVerbosity::Type type, ...) 
{
}*/



void ULogSubsystem::Deinitialize()
{
	//LogMap.Empty();//清空
	//GF_LOG(TEXT("ULogSubsystem Deinitialize"));
}


