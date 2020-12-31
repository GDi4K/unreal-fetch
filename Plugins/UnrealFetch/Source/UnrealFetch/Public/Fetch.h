// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "IFetch.h"
#include "Fetch.generated.h"

//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
UCLASS()
class UNREALFETCH_API UFetch : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFetch();

public:

	UFUNCTION(BlueprintCallable)
		static UFetchRequest* Fetch(FString Url, FFetchOptions Options);

	UFUNCTION(BlueprintCallable)
		static UFetchRequest* FetchJson(FString Url, FFetchJsonOptions Options);
};
