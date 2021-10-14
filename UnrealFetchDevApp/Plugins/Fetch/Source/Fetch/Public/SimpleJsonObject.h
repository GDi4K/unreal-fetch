// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Json.h"

#include "SimpleJsonObject.generated.h"

class USimpleJsonValue;
/**
 *
 */
UCLASS(BlueprintType)
class FETCH_API USimpleJsonObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* GetObject(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* GetObjectSync(FString Field)
	{
		return GetObject(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	float GetNumber(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	float GetNumberSync(FString Field)
	{
		return GetNumber(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	FString GetString(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	FString GetStringSync(FString Field)
	{
		return GetString(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	bool GetBool(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	bool GetBoolSync(FString Field)
	{
		return GetBool(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	TArray<USimpleJsonValue*> GetArray(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	TArray<USimpleJsonValue*> GetArraySync(FString Field)
	{
		return GetArray(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	bool IsNull(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	bool IsNullSync(FString Field)
	{
		return IsNull(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	bool IsNone(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	bool IsNoneSync(FString Field)
	{
		return IsNone(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	bool IsEmpty(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	bool IsEmptySync(FString Field)
	{
		return IsEmpty(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	bool HasKey(FString Field);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	bool HasKeySync(FString Field)
	{
		return HasKey(Field);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetNumber(FString Field, float Value);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetNumberSync(FString Field, float Value)
	{
		return SetNumber(Field, Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetString(FString Field, FString Value);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetStringSync(FString Field, FString Value)
	{
		return SetString(Field, Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetBool(FString Field, bool Value);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetBoolSync(FString Field, bool Value)
	{
		return SetBool(Field, Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetObject(FString Field, USimpleJsonObject* JsonObjet);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetObjectSync(FString Field, USimpleJsonObject* JsonObjet)
	{
		return SetObject(Field, JsonObjet);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetArray(FString Field, TArray<USimpleJsonValue*> Value);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	USimpleJsonObject* SetArraySync(FString Field, TArray<USimpleJsonValue*> Value)
	{
		return SetArray(Field, Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	FString Stringify(bool pretty = false);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	FString StringifySync(bool pretty = false)
	{
		return Stringify(pretty);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	USimpleJsonValue* AsValue();
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	USimpleJsonValue* AsValueSync()
	{
		return AsValue();
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
	bool IsValidObject();
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJsonObject")
	bool IsValidObjectSync()
	{
		return IsValidObject();
	}

	static USimpleJsonObject* Get(TSharedPtr<FJsonObject> Json);
	static USimpleJsonObject* GetInvalid();

public:
	TSharedPtr<FJsonObject> Original;
	bool invalidJson = false;
};
