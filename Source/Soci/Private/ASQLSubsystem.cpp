// Fill out your copyright notice in the Description page of Project Settings.
#pragma once


#include "ASQLSubsystem.h"

#include "SociLog.h"
#include "SociSubsystem.h"
//#include "SociSubsystem.h"

//它允许你将生成的文件(xxx.Generated.cpp)内联到模块CPP文件中，这样能减少需要解析的头文件数量，从而缩短编译时间。
//#include UE_INLINE_GENERATED_CPP_BY_NAME(SQLSubsystem)

/*
UASQLSubsystem::UASQLSubsystem(const FSociDefinition* sociDefinition)
	:Ptr_SociDefinition( sociDefinition)
{
	
}*/

bool UASQLSubsystem::IsConnected()
{
	if (PSociDefinition == nullptr)
	{
		return false;
	}
	return SQLSubsys_State == ESQLSubsys_State::EConnected;
}

ESocil_SQLType UASQLSubsystem::Get_SQLType()
{
	return ESocil_SQLType::ENone;
}

void UASQLSubsystem::Initialize(const FSociDefinition* sociDefinition)
{
	check(sociDefinition);
	PSociDefinition = sociDefinition;
	SQLSubsys_State = ESQLSubsys_State::ENone;
	IRetry = SQLSubSys_Retry_Nub;
	
	
	GetSociSubsystem()->GetGameInstance()->GetTimerManager().SetTimer(TH_Tick,this,&UASQLSubsystem::Tick,SQLSubSys_Tick_Rate,true,0);
	
	//FFunctionGraphTask::CreateAndDispatchWhenReady()
	/*
	TPromise<bool> Promise;
	// 返回一个尚未兑现的未来
	TFuture<bool> Future = Promise.GetFuture();
	Future.WaitFor(FTimespan::FromSeconds(5));
	*/
}

void UASQLSubsystem::Deinitialize()
{
	PSociDefinition = nullptr;
	GetSociSubsystem()->GetGameInstance()->GetTimerManager().ClearTimer(TH_Tick);
}
void UASQLSubsystem::Open()
{
	
}

void UASQLSubsystem::Tick()
{
	if (SQLSubsys_State == ESQLSubsys_State::EFail)//失败重试
	{
		if (IRetry>0 )
		{
			--IRetry;
			SQLSubsys_State = ESQLSubsys_State::ENone;
			SOCI_LOG(TEXT("Retry Nub: %d"),IRetry);
		}
		else
		{
			SOCI_LOG(TEXT("Retry Nub Not enough"));
		}
	}
	else if (SQLSubsys_State == ESQLSubsys_State::ENone )
	{
		this->Open();
	}
	else if (SQLSubsys_State == ESQLSubsys_State::EConnecting )
	{
		
	}
	else if (SQLSubsys_State == ESQLSubsys_State::EConnected )//X s进行测检测
	{
		
	}
	
	//SOCI_LOG(TEXT("Tick"));
}



void UASQLSubsystem::SQL_Operate(TUniqueFunction<void()>&& thread_fun,TUniqueFunction<void()> game_fun)
{
	//FFunctionGraphTask::CreateAndDispatchWhenReady()
	FFunctionGraphTask::CreateAndDispatchWhenReady(MoveTemp(thread_fun));
	//auto ger  = FFunctionGraphTask::CreateAndDispatchWhenReady(MoveTemp(thread_fun));

	// 同时创建多个任务

	/*
	FGraphEventArray Tasks;
	Tasks.Add(ger);
	FFunctionGraphTask::CreateAndDispatchWhenReady([]()
	{
		Log_CurrentThread(TEXT("任务完成"));
	},TStatId{},&Tasks,ENamedThreads::GameThread);
	Log_CurrentThread(TEXT("任务下派Test1"));
	*/
}


/*
TFuture<bool> UASQLSubsystem::GetTime()
{
	TPromise<bool> promise;
	promise.SetValue(true);
	return promise.GetFuture();
}*/





USociSubsystem* UASQLSubsystem::GetSociSubsystem() const
{
	return Cast<USociSubsystem>(GetOuter());
}