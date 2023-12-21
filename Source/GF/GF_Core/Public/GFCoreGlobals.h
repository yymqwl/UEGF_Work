#pragma once





//定义区域
GF_CORE_API DECLARE_LOG_CATEGORY_EXTERN(GF_Log,Log,All);
//////////////////
///定义GF日志
///[Core.Log]
///GF_Log=Display
///控制方法
#define GF_LOG(Format, ...) \
UE_LOG(GF_Log,Log,Format,##__VA_ARGS__)

#define GF_DISPLAY(Format, ...) \
UE_LOG(GF_Log,Display,Format,##__VA_ARGS__)

#define GF_WARNING(Format, ...) \
UE_LOG(GF_Log,Warning,Format,##__VA_ARGS__)

#define GF_ERROR(Format, ...) \
UE_LOG(GF_Log,Error,Format,##__VA_ARGS__)

#define GF_FATAL(Format, ...) \
UE_LOG(GF_Log,Fatal,Format,##__VA_ARGS__)

///////////////////////////////


//直接输入当前线程号
/*#define GF_LOG_CURRENTTHREAD uint32 CurrentThreadId = FPlatformTLS::GetCurrentThreadId();\
FString CurrentThreadName = FThreadManager::Get().GetThreadName(CurrentThreadId);\
GF_LOG(TEXT("%s[%d] 使用线程"), *CurrentThreadName, CurrentThreadId);
*/
extern GF_CORE_API void Log_CurrentThread(const FString& str);


template<typename TEnum>
extern GF_CORE_API FString GetEnumValueAsString(const FString& Name, TEnum Value);





extern  GF_CORE_API  void  PrintTraceStack(int Depth = 5);