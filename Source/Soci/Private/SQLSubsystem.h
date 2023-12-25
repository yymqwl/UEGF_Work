// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "soci/soci.h"
#include "soci/odbc/soci-odbc.h"//放第一个不然会有歧义
#include "CoreMinimal.h"
#include "SociLog.h"
#include "SociSetting.h"
#include "SQLSubsystem.generated.h"

class USociSubsystem;
/**
 * 依附于USociSubsystem系统之下
 *
*/

//DECLARE_DELEGATE_OneParam()

UCLASS()
class SOCI_API USQLSubsystem : public UObject
{
	GENERATED_BODY()
public:
	USQLSubsystem(){};
	//UASQLSubsystem(const FSociDefinition* sociDefinition);

	virtual void Initialize(const FSociDefinition* sociDefinition);

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize();

	UFUNCTION()
	virtual void Open();
	UFUNCTION()
	virtual  bool IsConnected();
	UFUNCTION()
	virtual void Close();

	
	template<typename T>
	FString GetInsertSQLStr()
	{
		//check(str_tb.IsEmpty());
	    FString	str_tb = T::StaticStruct()->GetName();
		FString str1 = FString::Format(TEXT("insert into {0}("),{*str_tb});
		FString str2 = FString(TEXT("values("));
		for (TFieldIterator<FProperty>  it(T::StaticStruct()); it;++it )
		{
			auto key=it->GetNameCPP();
			str1 += FString::Format(TEXT("{0},"),{*key});
			str2 += FString::Format(TEXT(":{0},"),{*key}); //TEXT(":")+TCHAR_TO_UTF8(*key)+""
		}
		str1.LeftInline(str1.Len()-1);
		str2.LeftInline(str2.Len()-1);
		
		FString str = FString::Format(TEXT("{0}) {1})"),{*str1,*str2});
		//FString::Left()
		return str;
	}
	
	template<typename T>
	void Query(const FString& sql,TFunction<void(TSharedPtr<TArray<T>>,TSharedPtr<FSoci_Error> error)> fun)
	{
		TSharedPtr<TArray<T>>  p_ay=  MakeShareable(new TArray<T>);
		TSharedPtr<FSoci_Error> p_error = MakeShareable(new FSoci_Error);
		//这里用引用传值大概率会报错,变量大部分都是局部
		auto get_thread = FFunctionGraphTask::CreateAndDispatchWhenReady([this,sql,p_ay,p_error]()
		{
			try
			{
				auto str =TCHAR_TO_UTF8(*sql);
				FScopeLock SL(&this->SQL_CS);
				soci::rowset<T> rs=(this->Sql_Session.prepare << TCHAR_TO_UTF8(*sql) );
				for (auto it = rs.begin(); it != rs.end(); ++it)
				{
					p_ay->Add((*it));
				}
				this->UpdateActiveTime();
				//SOCI_LOG(TEXT("query success"));
			}
			catch (std::runtime_error const& e)
			{
				p_error->ErrorType = FSoci_ErrorType::EQuery;
				p_error->ErrorMsg = UTF8_TO_TCHAR(e.what());
				SOCI_ERROR(TEXT("Query Error: %s"), *p_error->ErrorMsg);
			}
			catch (std::exception e)
			{
				p_error->ErrorType = FSoci_ErrorType::EUnKnowns;
				p_error->ErrorMsg = UTF8_TO_TCHAR(e.what());
				SOCI_ERROR(TEXT("Query Error:%s"),*p_error->ErrorMsg);
			}
		});
		
		FGraphEventArray Tasks;
		Tasks.Add(get_thread);
		FFunctionGraphTask::CreateAndDispatchWhenReady([this,fun,p_ay,p_error]()
		{
			fun(p_ay,p_error );
		},TStatId{},&Tasks,ENamedThreads::GameThread);
	}
	//"insert into person(Id, Name) values(:Id, :Name)"//标准输入
	template<typename T>
	void Insert(TSharedPtr<T> data,TFunction<void(TSharedPtr<FSoci_Error> error)> fun)
	{
		TSharedPtr<FSoci_Error> p_error = MakeShareable(new FSoci_Error);
		
		auto get_thread = FFunctionGraphTask::CreateAndDispatchWhenReady([this,data,p_error]()
		{
			try
			{
				auto sql = TCHAR_TO_UTF8(*GetInsertSQLStr<T>());
				FScopeLock SL(&this->SQL_CS);
				Sql_Session << sql ,
				soci::use(*data);
				this->UpdateActiveTime();
				//SOCI_LOG(TEXT("query success"));
			}
			catch (std::runtime_error const& e)
			{
				p_error->ErrorType = FSoci_ErrorType::EInsert;
				p_error->ErrorMsg = UTF8_TO_TCHAR(e.what());
				SOCI_ERROR(TEXT("Query Error: %s"), *p_error->ErrorMsg);
			}
			catch (std::exception e)
			{
				p_error->ErrorType = FSoci_ErrorType::EUnKnowns;
				p_error->ErrorMsg = UTF8_TO_TCHAR(e.what());
				SOCI_ERROR(TEXT("Query Error:%s"),*p_error->ErrorMsg);
			}
		});
	}
	
	/*
	template<typename  T>
	void Query(const FString& sql,TFunction<void(TSharedPtr<T>)>  fun)
	{
		//TDelegate<>
		//T t;
		//TSharedPtr<SQL_Function<T>> pt= MakeShareable<SQL_Function<T>>(new SQL_Function<T>());
		
		SOCI_LOG(TEXT("query start:%s"),*sql);
		std::string cstr (TCHAR_TO_UTF8(*sql));
		

		
		TSharedPtr<T> pt;

		auto get_thread = FFunctionGraphTask::CreateAndDispatchWhenReady([this,sql,&pt]()
		{
			try
			{
				FScopeLock SL(&this->SQL_CS);
				pt = MakeShareable<T>(new T);
				//TCHAR_TO_UTF8(*sql)
				//std::string cstr(TCHAR_TO_UTF8(*sql));
				this->Sql_Session << TCHAR_TO_UTF8(*sql) ,soci::into(*pt);
				this->UpdateActiveTime();
				//SOCI_LOG(TEXT("query success"));
			}
			catch (std::runtime_error const& e)
			{
				SOCI_ERROR(TEXT("Query Error: %s"),UTF8_TO_TCHAR(e.what()));
			}
			//Sql_Session << sql , soci::into( *pt.Get());
		});
		//auto ger  = FFunctionGraphTask::CreateAndDispatchWhenReady(MoveTemp(thread_fun));
		// 同时创建多个任务
		FGraphEventArray Tasks;
		Tasks.Add(get_thread);
		FFunctionGraphTask::CreateAndDispatchWhenReady([this,fun,&pt]()
		{
			fun(pt);
		},TStatId{},&Tasks,ENamedThreads::GameThread);
	}*/

	void Test_1();
	
	
	//线程执行,主线程执行
	virtual FGraphEventRef Async_Operate(TUniqueFunction<void()>&& thread_fun,TUniqueFunction<void()>&& game_fun);
	
	
	
	virtual void Tick();

	void UpdateActiveTime();
	
	virtual void Ping_SQL();//定时Ping 防止断开连接
	//TFuture<bool> GetTime();

	
	
	//////////////需要重载的数据
	ESocil_SQLType Get_SQLType();
	std::string Get_PingSQL();//得到ping sql语句
	USociSubsystem* GetSociSubsystem() const;
private:
	const soci::backend_factory& Get_backend_factory();
	////
protected:
	//bool bConnected;//是否连接
	//UPROPERTY()
	const FSociDefinition* PSociDefinition;//定义名称
	ESQLSubsys_State  SQLSubsys_State;//线程安全
	FCriticalSection SQL_CS;//线程同步锁
	FTimerHandle TH_Tick;
	int8  IRetry;//重试次数
	double LastActiveTime;
	
public:
	soci::session Sql_Session;//回话
};
