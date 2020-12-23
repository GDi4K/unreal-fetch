// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleJson.h"

typedef TJsonWriterFactory< TCHAR, TCondensedJsonPrintPolicy<TCHAR> > FCondensedJsonStringWriterFactory;
typedef TJsonWriter< TCHAR, TCondensedJsonPrintPolicy<TCHAR> > FCondensedJsonStringWriter;

typedef TJsonWriterFactory< TCHAR, TPrettyJsonPrintPolicy<TCHAR> > FPrettyJsonStringWriterFactory;
typedef TJsonWriter< TCHAR, TPrettyJsonPrintPolicy<TCHAR> > FPrettyJsonStringWriter;

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

bool USimpleJson::IsNull(FString Field)
{
	if (invalidJson) {
		return false;
	}

	return Original->HasTypedField<EJson::Null>(Field);
}

bool USimpleJson::IsNone(FString Field)
{
	if (invalidJson) {
		return false;
	}

	return Original->HasTypedField<EJson::None>(Field);
}

bool USimpleJson::IsEmpty(FString Field)
{
	if (invalidJson) {
		return false;
	}

	return IsNone(Field) || IsNull(Field);
}

USimpleJson* USimpleJson::SetNumber(FString Field, float Value)
{
	if (invalidJson) {
		return this;
	}

	Original->SetNumberField(Field, Value);
	return this;
}

USimpleJson* USimpleJson::SetString(FString Field, FString Value)
{
	if (invalidJson) {
		return this;
	}

	Original->SetStringField(Field, Value);
	return this;
}

USimpleJson* USimpleJson::SetBool(FString Field, bool Value)
{
	if (invalidJson) {
		return this;
	}

	Original->SetBoolField(Field, Value);
	return this;
}

USimpleJson* USimpleJson::SetObject(FString Field, USimpleJson* JsonObjet)
{
	if (invalidJson) {
		return this;
	}

	Original->SetObjectField(Field, JsonObjet->Original);
	return this;
}

FString USimpleJson::Stringify(bool pretty)
{
	FString OutputString;
	if (pretty)
	{
		TSharedRef< FPrettyJsonStringWriter > Writer = FPrettyJsonStringWriterFactory::Create(&OutputString);
		FJsonSerializer::Serialize(Original.ToSharedRef(), Writer);
	}
	else
	{
		TSharedRef< FCondensedJsonStringWriter > Writer = FCondensedJsonStringWriterFactory::Create(&OutputString);
		FJsonSerializer::Serialize(Original.ToSharedRef(), Writer);
	}
	
	return OutputString;
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
