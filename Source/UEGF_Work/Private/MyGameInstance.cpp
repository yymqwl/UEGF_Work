// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "Test/HttpSetting.h"


void UMyGameInstance::LoadCustomConfig()
{
	/*
	auto ConfigPath = FPaths::ProjectDir() / TEXT("HttpSetting.ini");
	GConfig->Flush(true,ConfigPath);



	
	UHttpSetting* httpSetting = NewObject<UHttpSetting>();
	//UE_LOG(LogTemp,Log,TEXT("%s"),*Config->GetCategoryName().GetPlainNameString());
	UE_LOG(LogTemp,Log,TEXT("%d"),httpSetting->MaxParallel);
	ReloadConfig(httpSetting->GetClass(),*ConfigPath);
	httpSetting = NewObject<UHttpSetting>();
	//UE_LOG(LogTemp,Log,TEXT("%s"),*Config->GetCategoryName().GetPlainNameString());
	UE_LOG(LogTemp,Log,TEXT("%d"),httpSetting->MaxParallel);
	*/
	
}


void UMyGameInstance::Init()
{
	Super::Init();
	LoadCustomConfig();
}
