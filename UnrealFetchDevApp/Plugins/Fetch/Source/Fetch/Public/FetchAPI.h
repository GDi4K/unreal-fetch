// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"


#include "FetchRequest.h"
#include "Components/SceneComponent.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "IFetch.h"
#include "FetchAPI.generated.h"

//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
UCLASS()
class FETCH_API UFetchAPI : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFetchAPI();

public:

	UFUNCTION(BlueprintCallable, Category = "Fetch")
		static UFetchRequest* Fetch(FString Url, FFetchOptions Options);

	UFUNCTION(BlueprintCallable, Category = "Fetch")
		static UFetchRequest* FetchJson(FString Url, FFetchJsonOptions Options);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Fetch | Headers")
		static FFetchHeader MakeBasicAuthHeader(FString Username, FString Password);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Fetch | Headers")
        static FFetchHeader MakeOAuthHeader(FString Token);
};
