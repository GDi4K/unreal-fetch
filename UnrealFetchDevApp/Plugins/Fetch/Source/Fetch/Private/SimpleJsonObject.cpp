// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.


#include "SimpleJsonObject.h"
#include "SimpleJsonValue.h"

typedef TJsonWriterFactory< TCHAR, TCondensedJsonPrintPolicy<TCHAR> > FCondensedJsonStringWriterFactory;
typedef TJsonWriter< TCHAR, TCondensedJsonPrintPolicy<TCHAR> > FCondensedJsonStringWriter;

typedef TJsonWriterFactory< TCHAR, TPrettyJsonPrintPolicy<TCHAR> > FPrettyJsonStringWriterFactory;
typedef TJsonWriter< TCHAR, TPrettyJsonPrintPolicy<TCHAR> > FPrettyJsonStringWriter;

USimpleJsonObject* USimpleJsonObject::GetObject(FString Field)
{
	if (invalidJson) {
		return this;
	}

	bool validField = Original->HasTypedField<EJson::Object>(Field);
	if (!validField)
	{
		return USimpleJsonObject::GetInvalid();
	}

	TSharedPtr<FJsonObject> Result = Original->GetObjectField(Field);
	return USimpleJsonObject::Get(Result);
}

float USimpleJsonObject::GetNumber(FString Field)
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

FString USimpleJsonObject::GetString(FString Field)
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

bool USimpleJsonObject::GetBool(FString Field)
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

TArray<USimpleJsonValue*> USimpleJsonObject::GetArray(FString Field)
{
	TArray<USimpleJsonValue*> Arr;

	TArray<TSharedPtr<FJsonValue>> OriginalArr = Original->GetArrayField(Field);
	for (TSharedPtr<FJsonValue> Item : OriginalArr)
	{
		Arr.Push(USimpleJsonValue::Get(Item));
	}

	return Arr;
}

bool USimpleJsonObject::HasKey(FString Field)
{
	if (invalidJson) {
		return false;
	}

	return Original->HasField(Field);
}

bool USimpleJsonObject::IsNull(FString Field)
{
	if (invalidJson) {
		return false;
	}

	return Original->HasTypedField<EJson::Null>(Field);
}

bool USimpleJsonObject::IsNone(FString Field)
{
	if (invalidJson) {
		return false;
	}

	return Original->HasTypedField<EJson::None>(Field);
}

bool USimpleJsonObject::IsEmpty(FString Field)
{
	if (invalidJson) {
		return false;
	}

	return IsNone(Field) || IsNull(Field);
}

USimpleJsonObject* USimpleJsonObject::SetNumber(FString Field, float Value)
{
	if (invalidJson) {
		return this;
	}

	Original->SetNumberField(Field, Value);
	return this;
}

USimpleJsonObject* USimpleJsonObject::SetString(FString Field, FString Value)
{
	if (invalidJson) {
		return this;
	}

	Original->SetStringField(Field, Value);
	return this;
}

USimpleJsonObject* USimpleJsonObject::SetBool(FString Field, bool Value)
{
	if (invalidJson) {
		return this;
	}

	Original->SetBoolField(Field, Value);
	return this;
}

USimpleJsonObject* USimpleJsonObject::SetObject(FString Field, USimpleJsonObject* JsonObjet)
{
	if (invalidJson) {
		return this;
	}

	Original->SetObjectField(Field, JsonObjet->Original);
	return this;
}

USimpleJsonObject* USimpleJsonObject::SetArray(FString Field, TArray<USimpleJsonValue*> Value)
{
	TArray<TSharedPtr<FJsonValue>> Arr;
	for (USimpleJsonValue* Item : Value)
	{
		Arr.Push(Item->Original);
	}

	Original->SetArrayField(Field, Arr);
	return this;
}

FString USimpleJsonObject::Stringify(bool pretty)
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

USimpleJsonValue* USimpleJsonObject::AsValue()
{
	return USimpleJsonValue::Get(MakeShared<FJsonValueObject>(Original));
}

bool USimpleJsonObject::IsValidObject()
{
	return !invalidJson;
}

USimpleJsonObject* USimpleJsonObject::Get(TSharedPtr<FJsonObject> Json)
{
	USimpleJsonObject* JsonObjet = NewObject<USimpleJsonObject>();
	JsonObjet->Original = Json;

	return JsonObjet;
}

USimpleJsonObject* USimpleJsonObject::GetInvalid()
{
	USimpleJsonObject* JsonObjet = NewObject<USimpleJsonObject>();
	JsonObjet->invalidJson = true;

	return JsonObjet;
}

