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


ESocil_SQLType UOdbcSubsystem::Get_SQLType()
{
	return ESocil_SQLType::EOdbc;
}


void UOdbcSubsystem::Open()
{
	if(SQLSubsys_State != ESQLSubsys_State::ENone)
	{
		SOCI_LOG(TEXT("Open Error: %s"),SQLSubsys_State);
		return ;
	}
	
	try
	{
		FScopeLock SL(&SQL_CS);
		//auto sql = (ANSICHAR*)StringCast<UTF8CHAR>(*PSociDefinition->ConString).Get();
		//std::string(TCHAR_TO_UTF8(*PSociDefinition->ConString));
		//(ANSICHAR*)FTCHARToUTF8((const TCHAR*)str).Get()
		Sql_Session.open(soci::odbc,  TCHAR_TO_UTF8(*PSociDefinition->ConString));


		//SQLSubsys_State = ESQLSubsys_State::ENone;
	}
	catch (soci::soci_error const& e)
	{
		FScopeLock SL(&SQL_CS);
		SQLSubsys_State = ESQLSubsys_State::ENone;
		SOCI_ERROR(TEXT("Connect Error: %s"),e.what());
	}
	
}



void UOdbcSubsystem::Initialize(const FSociDefinition* sociDefinition)
{
	Super::Initialize(sociDefinition);
	if (sociDefinition->HasLog)
	{
		Sql_Session.set_logger(new Ue_Soci_Log_Impl);
	}
	
}
