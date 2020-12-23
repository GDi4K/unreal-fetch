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

USimpleJsonValue* UFetch::MakeJson(FString InputJson)
{
	TSharedPtr<FJsonValue> ParsedJSON;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InputJson);
	if (FJsonSerializer::Deserialize(Reader, ParsedJSON))
	{
		return USimpleJsonValue::Get(ParsedJSON);
	}

	UE_LOG(LogTemp, Warning, TEXT("This is invalid"));
	
	TSharedRef<TJsonReader<>> Reader2 = TJsonReaderFactory<>::Create(InputJson);
	FJsonSerializer::Deserialize(Reader2, ParsedJSON);
	return USimpleJsonValue::Get(ParsedJSON);
}