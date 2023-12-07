// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Log_Actor.generated.h"

UCLASS()
class UEGF_LOG_API ALog_Actor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALog_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Log(FString str);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
