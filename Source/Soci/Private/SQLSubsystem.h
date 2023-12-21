// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "soci/odbc/soci-odbc.h"//放第一个不然会有歧义
#include "CoreMinimal.h"
#include "soci/soci.h"
#include "ASQLSubsystem.h"
#include "SQLSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class SOCI_API USQLSubsystem : public UASQLSubsystem
{
	GENERATED_BODY()
public:
	virtual void Open() override;

	virtual void Close() override;
	virtual void Tick() override;

	virtual void Ping_SQL()override;
	
	virtual void Initialize(const FSociDefinition* sociDefinition) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() override;

	std::string Get_PingSQL();//得到ping sql语句
	
	const soci::backend_factory& Get_backend_factory();
protected:
	soci::session Sql_Session;//回话
};
