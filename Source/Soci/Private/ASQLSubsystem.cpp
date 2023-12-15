// Fill out your copyright notice in the Description page of Project Settings.
#pragma once


#include "ASQLSubsystem.h"
#include "SociSubsystem.h"

//它允许你将生成的文件(xxx.Generated.cpp)内联到模块CPP文件中，这样能减少需要解析的头文件数量，从而缩短编译时间。
#include UE_INLINE_GENERATED_CPP_BY_NAME(SociSubsystem)

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
	return true;
}

ESocil_SQLType UASQLSubsystem::Get_SQLType()
{
	return ESocil_SQLType::ENone;
}

void UASQLSubsystem::Initialize(const FSociDefinition* sociDefinition)
{
	PSociDefinition = sociDefinition;

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
}

TFuture<bool> UASQLSubsystem::GetTime()
{
	TPromise<bool> promise;
	promise.SetValue(true);
	return promise.GetFuture();
}




/*
USociSubsystem* UASQLSubsystem::GetSociSubsystem() const
{
	return Cast<USociSubsystem>(GetOuter());
}
*/