// Fill out your copyright notice in the Description page of Project Settings.


#include "TestConfigActor.h"

#include "GFSetting.h"

// Sets default values
ATestConfigActor::ATestConfigActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestConfigActor::BeginPlay()
{
	Super::BeginPlay();
	const UGFSetting* Config = GetDefault<UGFSetting>();
	UE_LOG(LogTemp,Log,TEXT("%s"),*Config->Name);

	auto config = GetMutableDefault<UGFSetting>();
	config->Name  = TEXT("xxx");
	config->SaveConfig();
	//GConfig->LoadGlobalIniFile()
}

// Called every frame
void ATestConfigActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

