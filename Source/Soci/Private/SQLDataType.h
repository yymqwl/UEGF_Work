
#pragma once

#include "CoreMinimal.h"
//#include "SQLDataType.generated.h"
//
template<typename T> 
struct FSQLDataType//
{
	//GENERATED_BODY()
public:
	bool operator==(const FSQLDataType& Other) const
	{
		return Other.Data == Data;
	}
	bool operator!=(const FSQLDataType& Other) const
	{
		return Other.Data!=Data;
	}
	FSQLDataType& operator=(const FSQLDataType& Other)
	{
		Data = Other.Data;
		bChange=true;
		return *this;
	}

	FSQLDataType(const FSQLDataType& Other)
	{
		Data = Other.Data;
		bChange=true;
	}
	FSQLDataType(T data):bChange(false),Data(data)
	{
		
	}
	FSQLDataType():bChange(false)
	{
		
	}
	T& GetData()
	{
		return Data;
	}
	/*
	void SetData(T data)
	{
		Data = data;
	}*/
public:
	//UPROPERTY(EditAnywhere,meta=(ToolTip="是否改变"))
	bool bChange;
	T  Data;
};


//USTRUCT()
struct  FSQL_Float : public FSQLDataType<float>
{
	//GENERATED_BODY()
public:
	
	FSQL_Float& operator=(const float& Other) 
	{
		Data = Other;
		bChange=true;
		return *this;
	}
};

struct FSQL_String : public FSQLDataType<FString>
{
public:
};
