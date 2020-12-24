// Fill out your copyright notice in the Description page of Project Settings.


#include "Fetch.h"
#include "FetchRequest.h"

// Sets default values for this component's properties
UFetch::UFetch()
{
	
}

UFetchRequest* UFetch::Fetch(FString Url, FFetchOptions Options)
{
	UFetchRequest* Request = NewObject<UFetchRequest>();
	Request->Process(Url, Options);

	return Request;
}