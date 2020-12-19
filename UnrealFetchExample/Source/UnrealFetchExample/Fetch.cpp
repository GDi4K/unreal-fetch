// Fill out your copyright notice in the Description page of Project Settings.


#include "Fetch.h"
#include "FetchRequest.h"

// Sets default values for this component's properties
UFetch::UFetch()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UFetch::Fetch(FString Url, FFetchErrorDelegate OnError, FFetchResponseDelegate OnResponse)
{
	UE_LOG(LogTemp, Warning, TEXT("Calling URL: %s"), *Url);
	UFetchRequest* Request = NewObject<UFetchRequest>();
	Request->Process(Url, OnError, OnResponse);
}
