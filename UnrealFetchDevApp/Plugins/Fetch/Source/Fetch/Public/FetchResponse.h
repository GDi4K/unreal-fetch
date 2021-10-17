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
UCLASS(BlueprintType)
class FETCH_API UFetchResponse : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Fetch | Response");
	int32 StatusCode;

	UPROPERTY(BlueprintReadOnly, Category = "Fetch | Response");
	FString ResponseText;

	UPROPERTY(BlueprintReadOnly, Category = "Fetch | Response");
	TArray<FFetchHeader> Headers;

private:
	FHttpResponsePtr Original;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | Response")
		FString GetHeader(FString Key);

	static UFetchResponse* Get(FHttpResponsePtr Response);
};
