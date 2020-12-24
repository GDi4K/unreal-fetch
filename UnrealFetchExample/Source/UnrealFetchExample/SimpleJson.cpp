// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleJson.h"
#include "SimpleJsonValue.h"

USimpleJsonValue* USimpleJson::MakeJson(FString InputJson)
{
	TSharedPtr<FJsonValue> ParsedJSON;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InputJson);
	if (FJsonSerializer::Deserialize(Reader, ParsedJSON))
	{
		return USimpleJsonValue::Get(ParsedJSON);
	}

	UE_LOG(LogTemp, Warning, TEXT("This is invalid"));
	
	TSharedRef<TJsonReader<>> Reader2 = TJsonReaderFactory<>::Create("{}");
	FJsonSerializer::Deserialize(Reader2, ParsedJSON);
	return USimpleJsonValue::Get(ParsedJSON);
}

USimpleJsonValue* USimpleJson::MakeJsonNumber(float Value)
{
	return USimpleJsonValue::Get(MakeShared<FJsonValueNumber>(Value));
}

USimpleJsonValue* USimpleJson::MakeJsonBool(bool Value)
{
	return USimpleJsonValue::Get(MakeShared<FJsonValueBoolean>(Value));
}

USimpleJsonValue* USimpleJson::MakeJsonString(FString Value)
{
	return USimpleJsonValue::Get(MakeShared<FJsonValueString>(Value));
}

USimpleJsonValue* USimpleJson::MakeJsonNull()
{
	return USimpleJsonValue::Get(MakeShared<FJsonValueNull>());
}