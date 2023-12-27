// Fill out your copyright notice in the Description page of Project Settings.


#include "TestSociActor.h"
#include "SociSubsystem.h"
#include "SQLSubsystem.h"
// Sets default values
ATestSociActor::ATestSociActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATestSociActor::BeginPlay()
{
	Super::BeginPlay();
		
	
	auto ssy =GetGameInstance()->GetSubsystem<USociSubsystem>();
	if (ssy)
	{
		PSQLSubsys = Cast<USQLSubsystem>( ssy->Find_SQLSubsystem(TEXT("数据库1")));
	}
	
	//FindFProperty<>()
}
void ATestSociActor::Ping_SQL()
{
	
	if (PSQLSubsys)
	{
		PSQLSubsys->Ping_SQL();
	}
}


// Called every frame
void ATestSociActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

