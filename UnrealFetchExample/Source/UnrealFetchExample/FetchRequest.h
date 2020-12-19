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
	void Process(FString URL, FFetchErrorDelegate OnError, FFetchResponseDelegate OnResponse);

private:
	FFetchResponseDelegate ResponseHandler;
	FFetchErrorDelegate ErrorHandler;
	
	void OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);
};
