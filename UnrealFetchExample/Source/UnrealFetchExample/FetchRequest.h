// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IFetch.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "FetchRequest.generated.h"

/**
 * 
 */
UCLASS()
class UNREALFETCHEXAMPLE_API UFetchRequest : public UObject
{
	GENERATED_BODY()

public:
	UFetchRequest();
	void Process(FString URL);

	UFUNCTION(BlueprintCallable)
	UFetchRequest* OnText(FFetchTextResponseDelegate Event);

	UFUNCTION(BlueprintCallable)
	UFetchRequest* OnError(FFetchErrorDelegate Event);

private:
	bool bStarted = false;
	bool bFinished = false;
	bool bSuccessful = false;
	UFetchResponse* FetchResponse;
	FString ResponseText;

	FFetchTextResponseDelegate OnTextDelegate;
	FFetchErrorDelegate OnErrorDelegate;

	void OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);
};
