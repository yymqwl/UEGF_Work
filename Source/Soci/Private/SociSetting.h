
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

//数据库连接状态
UENUM()
enum class ESQLSubsys_State
{
	ENone,//最开始状态
	EConnecting,//连接中
	EConnected,//连接上
	EFail,//失败
};
ENUM_CLASS_FLAGS(ESQLSubsys_State);



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
	HasLog(false),
	SQLType(ESocil_SQLType::ENone)
	{
		
	}
};

USTRUCT()
struct FSoci_Row
{
	GENERATED_BODY()
};

/*
template<typename T>
struct SQL_Function
{
public:
	TUniquePtr<T> pt;
	TUniqueFunction<T> fun;
};*/
//tick刷新间隔
#define SQLSubSys_Tick_Rate 5.f
//重试次数
#define SQLSubSys_Retry_Nub 5
//超时时间
#define SQLSubSys_TimeOut 60.f
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
