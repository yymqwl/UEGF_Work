// Fill out your copyright notice in the Description page of Project Settings.

#include "SQLSubsystem.h"
#include "SociLog.h"


void USQLSubsystem::Initialize(const FSociDefinition* sociDefinition)
{
	Super::Initialize(sociDefinition);
	
	if (sociDefinition->HasLog)
	{
		Sql_Session.set_logger(new Ue_Soci_Log_Impl);
	}
}
void USQLSubsystem::Deinitialize()
{
	Super::Deinitialize();
	Close();
}


const soci::backend_factory& USQLSubsystem::Get_backend_factory()
{

	/*
	if (PSociDefinition->SQLType ==  ESocil_SQLType::EDB2)
	{
		return  soci::odbc;
	}*/
	return  soci::odbc;
	//return backend_factory();
}


void USQLSubsystem::Open()
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
			Sql_Session.open(Get_backend_factory(),  TCHAR_TO_UTF8(*PSociDefinition->ConString));
			SQLSubsys_State = ESQLSubsys_State::EConnected;//直接算连上
			UpdateActiveTime();
		}
		catch (soci::soci_error const& e)
		{
			SQLSubsys_State = ESQLSubsys_State::ENone;
			SOCI_ERROR(TEXT("Connect Error: %s"),e.what());
		}
	});
}


void USQLSubsystem::Close()
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
}



void USQLSubsystem::Tick()
{
	if (SQLSubsys_State == ESQLSubsys_State::EFail)//失败重试
	{
		if (IRetry>0 )
		{
			--IRetry;
			SQLSubsys_State = ESQLSubsys_State::ENone;
			SOCI_LOG(TEXT("Retry Nub: %d"),IRetry);
		}
		else
		{
			SOCI_LOG(TEXT("Retry Nub Not enough"));
		}
	}
	else if (SQLSubsys_State == ESQLSubsys_State::ENone )
	{
		this->Open();
	}
	else if (SQLSubsys_State == ESQLSubsys_State::EConnecting)
	{
		SOCI_LOG(TEXT("%s Connecting"),*PSociDefinition->DefName.ToString());
	}
	else if (SQLSubsys_State == ESQLSubsys_State::EConnected )
	{
		if (IsConnected())
		{
			auto delta = FPlatformTime::Seconds()-LastActiveTime;
			if (delta > SQLSubSys_TimeOut)//防止超时
			{
				Ping_SQL();
			}
		}
	}
	else if (SQLSubsys_State == ESQLSubsys_State::EConnected )//X s进行测检测
	{
		
	}

	
}

std::string USQLSubsystem::Get_PingSQL()
{
	std::string sql = "";
	if (Get_SQLType() == ESocil_SQLType::EOdbc)
	{
		sql = "select getdate()";
	}
	return sql;
}


void USQLSubsystem::Ping_SQL()
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
			//soci::row r;
			Sql_Session << Get_PingSQL() ;//,into(r);
			this->UpdateActiveTime();
		}
		catch (std::runtime_error const& e)
		{
			SOCI_ERROR(TEXT("Ping Error: %s"),e.what());
			this->Close();
		}
	});
}






