﻿

#include "GFCoreGlobals.h"

#include "HAL/ThreadManager.h"

//定义日志方法
DEFINE_LOG_CATEGORY(GF_Log);

///





/*
https://unreal.gg-labs.com/wiki-archives/macros-and-data-types/enums-for-both-c++-and-bp
 */



template<typename TEnum>
FString GetEnumValueAsString(const FString& Name, TEnum Value) {
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!enumPtr) return FString("Invalid");
	return enumPtr->GetNameByValue((int64)Value).ToString();
} 




void Log_CurrentThread(const FString&  str)
{
	uint32 CurrentThreadId = FPlatformTLS::GetCurrentThreadId();\
	FString CurrentThreadName = FThreadManager::Get().GetThreadName(CurrentThreadId);\
	GF_LOG(TEXT("线程:%s[%d] 输出:%s"), *CurrentThreadName, CurrentThreadId,*str);
}




void PrintTraceStack(int Depth )
{
	FString info = "Stack Info:";
	TArray<FProgramCounterSymbolInfo> stacks = FPlatformStackWalk::GetStack(1, Depth);
	for (int i=0; i < stacks.Num(); i++)
	{
		info += FString("\r\n\t") + FString::Printf(TEXT("%s (%s Line:%d"),
			ANSI_TO_TCHAR(stacks[i].FunctionName),  ANSI_TO_TCHAR(stacks[i].Filename), stacks[i].LineNumber);
	}
	if (stacks.Num() > 0)
	{
		GF_LOG( TEXT("%s"), *info);
	}
}