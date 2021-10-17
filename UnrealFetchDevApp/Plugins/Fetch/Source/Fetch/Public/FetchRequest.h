// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IFetch.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "FetchRequest.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class FETCH_API UFetchRequest : public UObject
{
	GENERATED_BODY()

public:
	UFetchRequest();
	void Process(FString URL, FFetchOptions Options);

	UFUNCTION(BlueprintCallable, Category = "Fetch | Request")
		UFetchRequest* OnText(FFetchTextResponseDelegate Event);

	UFUNCTION(BlueprintCallable, Category = "Fetch | Request")
		UFetchRequest* OnError(FFetchErrorDelegate Event);

	UFUNCTION(BlueprintCallable, Category = "Fetch | Request")
		UFetchRequest* OnJson(FFetchJsonResponseDelegate Event);

private:
	bool bStarted = false;
	bool bFinished = false;
	bool bSuccessful = false;
	UFetchResponse* FetchResponse;
	FString ResponseText;

	FFetchTextResponseDelegate OnTextDelegate;
	FFetchErrorDelegate OnErrorDelegate;
	FFetchJsonResponseDelegate OnJsonDelegate;

	void OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);
	FString HttpMethodToString(FFetchOptionsMethod Method);
};

