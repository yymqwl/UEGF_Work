// Fill out your copyright notice in the Description page of Project Settings.


#include "OdbcSubsystem.h"

#include "SociLog.h"


UOdbcSubsystem::UOdbcSubsystem()
{
	SOCI_LOG(TEXT("UOdbcSubsystem()"));
}
UOdbcSubsystem::~UOdbcSubsystem()
{
	SOCI_LOG(TEXT("~UOdbcSubsystem()"));
}

/*
ESocil_SQLType UOdbcSubsystem::Get_SQLType()
{
	return ESocil_SQLType::EOdbc;
}*/


/*
void UOdbcSubsystem::Close()
{
	if (SQLSubsys_State != ESQLSubsys_State::EConnected )
	{
		SOCI_LOG(TEXT("Open Close: %d"),SQLSubsys_State);
		return;
	}
	FFunctionGraphTask::CreateAndDispatchWhenReady([this]()
	{
		
		try
		{
			FScopeLock SL(&SQL_CS);
			Sql_Session.close();
		}
		catch (soci::soci_error const& e)
		{
			SOCI_ERROR(TEXT("Close Error: %s"),e.what());
		}
		SQLSubsys_State = ESQLSubsys_State::ENone;//直接算连上
	});
}*/

/*
void UOdbcSubsystem::Ping_SQL()
{
	if (SQLSubsys_State != ESQLSubsys_State::EConnected )
	{
		SOCI_LOG(TEXT("Open Ping: %d"),SQLSubsys_State);
		return;
	}
	FFunctionGraphTask::CreateAndDispatchWhenReady([this]()
	{
		try
		{
			FScopeLock SL(&SQL_CS);
			soci::row r;
			Sql_Session << "select getdate()" ,into(r);
			this->UpdateActiveTime();
		}
		catch (std::runtime_error const& e)
		{
			SOCI_ERROR(TEXT("Ping Error: %s"),e.what());
			this->Close();
		}
	});
}*/
/*
template <typename T>
TArray<T> UOdbcSubsystem::Qeury(FString& sql)
{
	if(SQLSubsys_State != ESQLSubsys_State::EConnected)
	{
		SOCI_LOG(TEXT("Qeury Error: %d"),SQLSubsys_State);
		return ;
	}
	TArray<T> ay;
	vector<T> v;
	FScopeLock SL(&SQL_CS);
	v.reserve(1);
	Sql_Session << TCHAR_TO_UTF8(*sql) ,into(v);
	for (auto element : v)
	{
		ay.Add(element);
	}
	return ay;
}*/


/*
void UOdbcSubsystem::Open()
{
	if(SQLSubsys_State != ESQLSubsys_State::ENone)
	{
		SOCI_LOG(TEXT("Open Error: %d"),SQLSubsys_State);
		return ;
	}
	//auto sql = (ANSICHAR*)StringCast<UTF8CHAR>(*PSociDefinition->ConString).Get();
	//std::string(TCHAR_TO_UTF8(*PSociDefinition->ConString));
	//(ANSICHAR*)FTCHARToUTF8((const TCHAR*)str).Get()
	{
		FScopeLock SL(&SQL_CS);
		SQLSubsys_State = ESQLSubsys_State::EConnecting;
	}
	
	FFunctionGraphTask::CreateAndDispatchWhenReady([this]()
	{
		SOCI_LOG(TEXT("Connecting: "));
		try
		{
			FScopeLock SL(&SQL_CS);
			Sql_Session.open(soci::odbc,  TCHAR_TO_UTF8(*PSociDefinition->ConString));
			SQLSubsys_State = ESQLSubsys_State::EConnected;//直接算连上
			UpdateActiveTime();
		}
		catch (soci::soci_error const& e)
		{
			SQLSubsys_State = ESQLSubsys_State::ENone;
			SOCI_ERROR(TEXT("Connect Error: %s"),e.what());
		}
	});
}*/

/*

void UOdbcSubsystem::Initialize(const FSociDefinition* sociDefinition)
{
	Super::Initialize(sociDefinition);
	if (sociDefinition->HasLog)
	{
		Sql_Session.set_logger(new Ue_Soci_Log_Impl);
	}
	
}*/
