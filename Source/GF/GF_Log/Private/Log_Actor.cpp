// Fill out your copyright notice in the Description page of Project Settings.


#include "Log_Actor.h"

#include "ALog.h"
#include "LogSubsystem.h"


// Sets default values
ALog_Actor::ALog_Actor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALog_Actor::BeginPlay()
{
	Super::BeginPlay();
	//GF_LOG(TEXT("%d"),Config->MaxParallel);
	//Log("xxxx%d",Config->MaxParallel);
}
void ALog_Actor::Log(FString str)
{
	auto logsubsys =GetGameInstance()->GetSubsystem<ULogSubsystem>();
	if (logsubsys)
	{
		UE_LOG(Log_GF,Log,TEXT("%s"),*str);
	}
	//GetGameInstance()
	//UE_LOG(Log_GF,Log)
	//UE::Logging::Private::BasicLog()
	//UE_LOG(Log_GF,Log);
	//GEngine->AddOnScreenDebugMessage()
	//GEngine->AddOnScreenDebugMessage()
	//GF_LOG_TRACK();
}


// Called every frame
void ALog_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

