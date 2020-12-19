// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "IFetch.h"
#include "Fetch.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALFETCHEXAMPLE_API UFetch : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFetch();

public:	

	UFUNCTION(BlueprintCallable)
	void Fetch(FString Url, FFetchErrorDelegate OnError, FFetchResponseDelegate OnResponse);

private:
	static FFetchErrorDelegate DefaultOnError;
};
