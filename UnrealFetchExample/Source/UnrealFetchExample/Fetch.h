// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "IFetch.h"
#include "Fetch.generated.h"

//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
UCLASS()
class UNREALFETCHEXAMPLE_API UFetch : public UObject
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFetch();

public:	

	UFUNCTION(BlueprintCallable)
	static UFetchRequest* Fetch(FString Url, FFetchOptions Options);

	
};
