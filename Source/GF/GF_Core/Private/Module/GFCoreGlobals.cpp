

#include "GFCoreGlobals.h"

//定义日志方法
DEFINE_LOG_CATEGORY(GF_Log);

///


















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