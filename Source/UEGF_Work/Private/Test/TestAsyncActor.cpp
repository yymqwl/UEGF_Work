// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/TestAsyncActor.h"

#include "GFCoreGlobals.h"
#include "Soci/Private/SQLSubsystem.h"

// Sets default values
ATestAsyncActor::ATestAsyncActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	/*
	if (InputComponent == nullptr)
	{
		InputComponent = CreatePlayerInputComponent();
		if (InputComponent)
		{
			SetupPlayerInputComponent(InputComponent);
			InputComponent->RegisterComponent();
			if (UInputDelegateBinding::SupportsInputDelegate(GetClass()))
			{
				InputComponent->bBlockInput = bBlockInput;
				UInputDelegateBinding::BindInputDelegatesWithSubojects(this, InputComponent);
			}
		}
	}*/
}


// Called when the game starts or when spawned
void ATestAsyncActor::BeginPlay()
{
	Super::BeginPlay();
	// 获取输入组件
}
//InputComponent  = GetWorld()->GetFirstPlayerController()->InputComponent;
	
//auto input = FindComponentByClass<UEnhancedInputComponent>();
	

//InputComponent = FindComponentByClass<UEnhancedInputComponent>();
/*if (InputComponent == nullptr)
{
	GF_LOG(TEXT(" InputComponent Null"));
	return;
}*/
//check(InputComponent);
//InputComponent->Bind(EKeys::A, , this, &ATestAsyncActor::OnKeyPressed);
/*
void ATestAsyncActor::OnKeyPressed(FKey Key)
{
	GF_LOG(TEXT("A Press"));
}*/

void ATestAsyncActor::Test1()
{
	GF_LOG(TEXT("Test1 Call:%f"),	FPlatformTime::Seconds());

	//TestSociActor->PSQLSubsys->Ping_SQL();

	TestSociActor->PSQLSubsys->Ping_SQL();
	/*
	TArray<int> ay ;
	ay.Sort()
	*/
	//ay.Sort()
	//TestSociActor->PSQLSubsys->Ping_SQL()
	/*
	auto ger  = FFunctionGraphTask::CreateAndDispatchWhenReady([]()
	{
		Log_CurrentThread(TEXT("当前线程1"));
		FPlatformProcess::Sleep(3.f);
		Log_CurrentThread(TEXT("当前线程2"));
	});
	// 同时创建多个任务
	FGraphEventArray Tasks;
	Tasks.Add(ger);
	FFunctionGraphTask::CreateAndDispatchWhenReady([]()
	{
		Log_CurrentThread(TEXT("任务完成"));
	},TStatId{},&Tasks,ENamedThreads::GameThread);*/
	Log_CurrentThread(TEXT("任务下派Test1"));

	//GetGameInstance()->GetSubsystem<>()
}
/*
void ATestAsyncActor::DestroyPlayerInputComponent()
{
	
	if (InputComponent)
	{
		InputComponent->DestroyComponent();
		InputComponent = nullptr;
	}
}
*/


void ATestAsyncActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ATestAsyncActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

