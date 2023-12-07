// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_LogActor.h"

#include "HttpSetting.h"
//#include "Log/Log.h"

// Sets default values
ATest_LogActor::ATest_LogActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	
}

// Called when the game starts or when spawned
void ATest_LogActor::BeginPlay()
{
	Super::BeginPlay();

	
	const UHttpSetting* Config = GetDefault<UHttpSetting>();
	//UE_LOG(LogTemp,Log,TEXT("%s"),*Config->GetCategoryName().GetPlainNameString());
	UE_LOG(LogTemp,Log,TEXT("%d"),Config->MaxParallel);

	auto Config2 = GetMutableDefault<UHttpSetting>();
	Config2->MaxParallel = 10;
	
	//FString PathToConfigFile;
	Config2->SaveConfig();
	/*
	int x;
	GConfig->GetInt(TEXT("HttpSetting"),TEXT("MaxParallel"),x,HttpSetting);
	*/
	//auto  UEGF = FModuleManager::LoadModuleChecked<FUEGF>(FName(TEXT("UEGF")));
	
	//UEGF_LOG_TRACK();
	//UE_LOG(Log_UEGF,Log,TEXT("ATest_LogActor:%d"),111);
	//UEGF_LOG(TEXT("ATest_LogActor:%d"),111);
}

// Called every frame
void ATest_LogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

