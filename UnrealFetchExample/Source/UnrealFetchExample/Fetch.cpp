// Fill out your copyright notice in the Description page of Project Settings.


#include "Fetch.h"
#include "FetchRequest.h"

// Sets default values for this component's properties
UFetch::UFetch()
{
	PrimaryComponentTick.bCanEverTick = false;
}

UFetchRequest* UFetch::Fetch(FString Url)
{
	UFetchRequest* Request = NewObject<UFetchRequest>();
	Request->Process(Url);

	return Request;
}

