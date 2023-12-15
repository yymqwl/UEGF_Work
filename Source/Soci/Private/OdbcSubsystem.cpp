// Fill out your copyright notice in the Description page of Project Settings.


#include "OdbcSubsystem.h"



ESocil_SQLType UOdbcSubsystem::Get_SQLType()
{
	return ESocil_SQLType::EOdbc;
}



void UOdbcSubsystem::Initialize(const FSociDefinition* sociDefinition)
{
	Super::Initialize(sociDefinition);
}
