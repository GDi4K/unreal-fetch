// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.


#include "SimpleJsonValue.h"

float USimpleJsonValue::AsNumber()
{
	return (float)Original->AsNumber();
}

FString USimpleJsonValue::AsString()
{
	return Original->AsString();
}

bool USimpleJsonValue::AsBool()
{
	return Original->AsBool();
}

USimpleJsonObject* USimpleJsonValue::AsObject()
{
	TSharedPtr<FJsonObject> Obj = Original->AsObject();
	return USimpleJsonObject::Get(Obj);
}

TArray<USimpleJsonValue*> USimpleJsonValue::AsArray()
{
	TArray<USimpleJsonValue*> Arr;

	TArray<TSharedPtr<FJsonValue>> OriginalArray = Original->AsArray();
	for (TSharedPtr<FJsonValue> Item : OriginalArray)
	{
		Arr.Push(USimpleJsonValue::Get(Item));
	}

	return Arr;
}

bool USimpleJsonValue::IsNull()
{
	return Original->IsNull();
}

bool USimpleJsonValue::IsValid()
{
	return !InvalidJson;
}

USimpleJsonValue* USimpleJsonValue::Get(TSharedPtr<FJsonValue> Original)
{
	USimpleJsonValue* JsonValue = NewObject<USimpleJsonValue>();
	JsonValue->Original = Original;

	return JsonValue;
}
