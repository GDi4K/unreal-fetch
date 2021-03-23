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
class FETCH_API UFetchResponse : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Scripting | Javascript");
	int32 StatusCode;

	UPROPERTY(BlueprintReadOnly, Category = "Scripting | Javascript");
	FString ResponseText;

	UPROPERTY(BlueprintReadOnly, Category = "Scripting | Javascript");
	TArray<FFetchHeader> Headers;

private:
	FHttpResponsePtr Original;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		FString GetHeader(FString Key);

	static UFetchResponse* Get(FHttpResponsePtr Response);
};
