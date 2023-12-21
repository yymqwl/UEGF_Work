// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SQLSubsystem.h"
#include <soci/soci.h>
#include <soci/odbc/soci-odbc.h>
#if PLATFORM_WINDOWS
#endif
#include "OdbcSubsystem.generated.h"


/**
 * 
 */
UCLASS()
class SOCI_API UOdbcSubsystem : public UASQLSubsystem
{
	GENERATED_BODY()
public:
	UOdbcSubsystem();
	virtual ~UOdbcSubsystem() override;
	//virtual ESocil_SQLType Get_SQLType() override;
	//virtual void Initialize(const FSociDefinition* sociDefinition) override;

	//soci::backend_factory Get_backend_factory() override;
	
	//virtual void Open() override;
	//virtual void Close() override;

	 

	/*
	template <typename T>
	TArray<T> Qeury(FString& sql);
	*/

	//virtual void Ping_SQL() override;
protected:
	//soci::session Sql_Session;//ODBC
};
