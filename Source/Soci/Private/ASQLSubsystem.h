// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SociSetting.h"
#include "ASQLSubsystem.generated.h"

//class USociSubsystem;
/**
 * 依附于USociSubsystem系统之下
 *
 * 暂时考虑把SOCI放进一个新的线程,方便用户操作
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
	virtual  bool IsConnected();

	UFUNCTION()
	virtual ESocil_SQLType Get_SQLType() ;


	TFuture<bool> GetTime();
	
	//USociSubsystem* GetSociSubsystem()const;
protected:
	//bool bConnected;//是否连接
	const FSociDefinition* PSociDefinition;//定义名称
};
