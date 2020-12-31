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

UFetchRequest* UFetch::FetchJson(FString Url, FFetchJsonOptions Options)
{
	FFetchOptions RealOptions;
	RealOptions.Headers.Add({ "Content-Type", "application/json" });
	RealOptions.Headers.Add({ "Accept", "application/json" });

	for (FFetchHeader Header : Options.Headers)
	{
		RealOptions.Headers.Push(Header);
	}

	RealOptions.Method = Options.Method;

	if (Options.Body != nullptr)
	{
		RealOptions.Body = Options.Body->AsObject()->Stringify();
	}

	return Fetch(Url, RealOptions);
}
