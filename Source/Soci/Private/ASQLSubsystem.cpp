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
	return PSociDefinition->SQLType;
}

void UASQLSubsystem::Initialize(const FSociDefinition* sociDefinition)
{
	check(sociDefinition);
	PSociDefinition = sociDefinition;
	SQLSubsys_State = ESQLSubsys_State::ENone;
	IRetry = SQLSubSys_Retry_Nub;
	SOCI_LOG(TEXT("Initialize:%d_%s"),PSociDefinition->SQLType,*PSociDefinition->DefName.ToString());

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
	SOCI_LOG(TEXT("Deinitialize:%d_%s"),PSociDefinition->SQLType, *PSociDefinition->DefName.ToString());
	PSociDefinition = nullptr;
	GetSociSubsystem()->GetGameInstance()->GetTimerManager().ClearTimer(TH_Tick);
}
void UASQLSubsystem::UpdateActiveTime()
{
	LastActiveTime = FPlatformTime::Seconds();
}
/*
const soci::backend_factory& UASQLSubsystem::Get_backend_factory()
{
	return  soci::odbc;
	//return backend_factory();
}*/



void UASQLSubsystem::Open()
{
	
}
void UASQLSubsystem::Close()
{
	
}



void UASQLSubsystem::Tick()
{
	//SOCI_LOG(TEXT("Tick"));
}

void UASQLSubsystem::Ping_SQL()
{
	
}


FGraphEventRef UASQLSubsystem::Async_Operate(TUniqueFunction<void()>&& thread_fun,TUniqueFunction<void()>&& game_fun)
{
	//FFunctionGraphTask::CreateAndDispatchWhenReady()
	auto get_thread = FFunctionGraphTask::CreateAndDispatchWhenReady(MoveTemp(thread_fun));
	//auto ger  = FFunctionGraphTask::CreateAndDispatchWhenReady(MoveTemp(thread_fun));
	// 同时创建多个任务
	FGraphEventArray Tasks;
	Tasks.Add(get_thread);
	return FFunctionGraphTask::CreateAndDispatchWhenReady(MoveTemp(game_fun),TStatId{},&Tasks,ENamedThreads::GameThread);
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