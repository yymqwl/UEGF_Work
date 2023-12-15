


#pragma once
#include "CoreMinimal.h"

#include "SociSetting.generated.h"

//https://soci.sourceforge.net/doc/release/4.0
///相关文档
UENUM()
enum class ESocil_SQLType :uint8
{
	ENone,
	EOdbc,//微软
	EMySql,//mysql
	EDB2,
	EFirebird,
	Oracle,
	PostgreSQL,
	SQLite3,
	Max
};
ENUM_CLASS_FLAGS(ESocil_SQLType);


USTRUCT()
struct FSociDefinition
{
	GENERATED_BODY()
	UPROPERTY( meta=(DisplayName = "定义名"))
	FName DefName;
	UPROPERTY( meta=(DisplayName = "连接字符串"))
	FString ConString;
	UPROPERTY()
	bool HasLog;
	UPROPERTY()
	ESocil_SQLType SQLType;

	
	FSociDefinition():
	DefName(NAME_None),
	HasLog(false)
	{
		
	}
};

/*
UCLASS(Config=Game,Defaultconfig)
class SOCI_API USociSetting : public UObject
{
	GENERATED_BODY()
public:
	//定义群
	UPROPERTY(Config,transient)
	TArray<FSociDefinition> SociDefinitions;
};*/
