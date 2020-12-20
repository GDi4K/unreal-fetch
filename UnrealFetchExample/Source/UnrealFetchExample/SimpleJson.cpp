// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleJson.h"


bool USimpleJson::GetObject(FString Field, USimpleJson*& JsonObjet)
{
	if (invalidJson) {
		JsonObjet = this;
		return false;
	}

	bool validField = Original->HasTypedField<EJson::Object>(Field);
	if (!validField)
	{
		JsonObjet = USimpleJson::GetInvalid();
		return false;
	}

	TSharedPtr<FJsonObject> Result = Original->GetObjectField(Field);
	JsonObjet = USimpleJson::Get(Result);
	return true;
}

float USimpleJson::GetNumber(FString Field)
{
	if (invalidJson) {
		return 0;
	}

	bool validField = Original->HasTypedField<EJson::Number>(Field);
	if (!validField) {
		return 0;
	}

	return (float)Original->GetNumberField(Field);
}

FString USimpleJson::GetString(FString Field)
{
	if (invalidJson) {
		return "";
	}

	bool validField = Original->HasTypedField<EJson::String>(Field);
	if (!validField) {
		return "";
	}

	return Original->GetStringField(Field);
}

bool USimpleJson::GetBool(FString Field)
{
	if (invalidJson) {
		return false;
	}

	bool validField = Original->HasTypedField<EJson::Boolean>(Field);
	if (!validField) {
		return false;
	}

	return Original->GetBoolField(Field);
}

USimpleJson* USimpleJson::Get(TSharedPtr<FJsonObject> Json)
{
	USimpleJson* JsonObjet = NewObject<USimpleJson>();
	JsonObjet->Original = Json;

	return JsonObjet;
}

USimpleJson* USimpleJson::GetInvalid()
{
	USimpleJson* JsonObjet = NewObject<USimpleJson>();
	JsonObjet->invalidJson = true;

	return JsonObjet;
}