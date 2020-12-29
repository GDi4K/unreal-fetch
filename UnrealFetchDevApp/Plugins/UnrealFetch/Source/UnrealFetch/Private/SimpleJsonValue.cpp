// Fill out your copyright notice in the Description page of Project Settings.


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

USimpleJsonValue* USimpleJsonValue::Get(TSharedPtr<FJsonValue> Original)
{
	USimpleJsonValue* JsonValue = NewObject<USimpleJsonValue>();
	JsonValue->Original = Original;

	return JsonValue;
}
