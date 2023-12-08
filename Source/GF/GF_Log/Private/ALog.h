// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "ILog.h"
#include "ALog.generated.h"


UCLASS(Abstract)
class GF_LOG_API UALog : public UObject ,public ILog
{
	GENERATED_BODY()
};