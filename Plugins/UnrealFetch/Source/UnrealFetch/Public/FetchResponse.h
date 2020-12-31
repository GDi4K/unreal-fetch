// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Types.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "FetchResponse.generated.h"

/**
 *
 */
UCLASS()
class UNREALFETCH_API UFetchResponse : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly);
	int32 StatusCode;

	UPROPERTY(BlueprintReadOnly);
	FString ResponseText;

	UPROPERTY(BlueprintReadOnly);
	TArray<FFetchHeader> Headers;

private:
	FHttpResponsePtr Original;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetHeader(FString Key);

	static UFetchResponse* Get(FHttpResponsePtr Response);
};