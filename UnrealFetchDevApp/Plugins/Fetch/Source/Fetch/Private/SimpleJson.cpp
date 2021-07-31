// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.


#include "SimpleJson.h"
#include "SimpleJsonValue.h"
#include "Json.h"

USimpleJsonValue* USimpleJson::MakeJson(FString InputJson)
{
	TSharedPtr<FJsonValue> ParsedJSON;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InputJson);
	if (FJsonSerializer::Deserialize(Reader, ParsedJSON))
	{
		return USimpleJsonValue::Get(ParsedJSON);
	}

	TSharedRef<TJsonReader<>> Reader2 = TJsonReaderFactory<>::Create("{}");
	FJsonSerializer::Deserialize(Reader2, ParsedJSON);
	USimpleJsonValue* InvalidJson =  USimpleJsonValue::Get(ParsedJSON);
	InvalidJson->InvalidJson = true;

	return InvalidJson;
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