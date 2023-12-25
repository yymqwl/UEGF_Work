// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/TestAsyncActor.h"
#include "Soci/Private/SQLSubsystem.h"
#include "GFCoreGlobals.h"
#include "Soci/Private/SQLDataType.h"
#include "Person.h"


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

	FSQL_Float f;
	
	GF_LOG(TEXT("%d"),f.bChange);
	f = 33;
	GF_LOG(TEXT("%d"),f.bChange);
	//f = 44;
	//FVector2d V2= 
	//FSQL_Float  f();
	//auto str = FString::Format(TEXT("{0}:{1}"), {TEXT("11"),TEXT("2222222")});
	//auto str = TestSociActor->PSQLSubsys->GetInsertSQLStr<FPerson>();//FString(TEXT("Test1 Call:"));
	
	/*
	TSharedPtr<FPerson> p2 = MakeShareable(new FPerson);
	p2->Id= 5;
	p2->Name  = TEXT("测试5");

	
	
	TestSociActor->PSQLSubsys->Insert(p2,[](TSharedPtr<FSoci_Error> error)
	{
		if (error->HasError())
		{
			return;
		}
		GF_LOG(TEXT("插入成功") );
	});*/
	//FPerson::StaticStruct()->GetName()
	/*
	str.LeftInline(str.Len()-1);
	str +=")";
	*/
	
	//GF_LOG(TEXT("%s"),*str);
	
	/*
	TestSociActor->PSQLSubsys->Query<FPerson>(TEXT("select * from Person"),[](TSharedPtr<TArray<FPerson>> p_ay,TSharedPtr<FSoci_Error> error)
	{
		if (error->HasError())
		{
			return;
		}
		
		if (p_ay->Num()>0)
		{
			GF_LOG(TEXT("Test1 Call From Query :%s"),  *(*p_ay)[4].Name );
		}
	});*/
	/*
	TestSociActor->PSQLSubsys->Query<FPerson>(TEXT("select * from Person"),[](TSharedPtr<FPerson> p)
	{
		GF_LOG(TEXT("Test1 Call From Query :%s"),  *p->Name );
	});*/
	/*[](TSharedPtr<Person> p)
	{
		GF_LOG(TEXT("Test1 Call From Query :%s"), UTF8_TO_TCHAR( p->Name.c_str()));
	});*/
	/*
	FPerson fp;
	fp.Name = TEXT("测试名称1");
	const UStruct* structClass= FPerson::StaticStruct();
	structClass->ChildProperties;
	
	GF_LOG(TEXT("Test1 Call:%s"),*structClass->GetName());
	//遍历属性
	
	for (TFieldIterator<FProperty> i(FPerson::StaticStruct()); i; ++i)
	{
		FProperty* prop=*i;
		if (prop->IsA(FStrProperty::StaticClass()))//(const FStrProperty* StringProperty = Cast<FStrProperty>(prop) )
		{
			const FStrProperty* StringProperty = CastFieldChecked<FStrProperty>(prop);
			auto str	= StringProperty->GetPropertyValue_InContainer(&fp);
			GF_LOG(TEXT("%s:%s"),*prop->GetNameCPP(),*str);
		}
		//prop->GetValue_InContainer()
		//(*prop).IsA<>()
		GF_LOG(TEXT("Test1 Call %s"),*prop->GetName());
		GF_LOG(TEXT("Test1 Call 2"));
		
	}*/
	//TestSociActor->PSQLSubsys->Ping_SQL();
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
	//Log_CurrentThread(TEXT("任务下派Test1"));

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

