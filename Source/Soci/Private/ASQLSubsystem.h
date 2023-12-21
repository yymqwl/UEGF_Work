// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SociSetting.h"
#include "ASQLSubsystem.generated.h"

class USociSubsystem;
/**
 * 依附于USociSubsystem系统之下
 *
*/


UCLASS(Abstract)

class SOCI_API UASQLSubsystem : public UObject
{
	GENERATED_BODY()
public:
	UASQLSubsystem(){};
	//UASQLSubsystem(const FSociDefinition* sociDefinition);

	virtual void Initialize(const FSociDefinition* sociDefinition);

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize();

	UFUNCTION()
	virtual void Open();
	UFUNCTION()
	virtual  bool IsConnected();
	UFUNCTION()
	virtual void Close();

	
	template<typename  T>
	TArray<T> Query(FString sql);

	//线程执行,主线程执行
	virtual FGraphEventRef Async_Operate(TUniqueFunction<void()>&& thread_fun,TUniqueFunction<void()>&& game_fun);

	
	virtual void Tick();

	void UpdateActiveTime();
	
	virtual void Ping_SQL();//定时Ping 防止断开连接
	//TFuture<bool> GetTime();

	//////////////需要重载的数据
	ESocil_SQLType Get_SQLType();
	////
	
	USociSubsystem* GetSociSubsystem() const;
protected:
	//bool bConnected;//是否连接
	//UPROPERTY()
	const FSociDefinition* PSociDefinition;//定义名称
	ESQLSubsys_State  SQLSubsys_State;//线程安全
	FCriticalSection SQL_CS;//线程同步锁
	FTimerHandle TH_Tick;
	int8  IRetry;//重试次数
	double LastActiveTime;
};
