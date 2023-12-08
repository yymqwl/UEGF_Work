// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_LogActor.h"

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


	
	//GF_LOG_TRACK();
	//UE_LOG(Log_GF,Log,TEXT("ATest_LogActor:%d"),111);
	//GF_LOG(TEXT("ATest_LogActor:%d"),111);
}

// Called every frame
void ATest_LogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

