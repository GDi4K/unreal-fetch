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

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		float GetNumber(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		FString GetString(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		bool GetBool(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		TArray<USimpleJsonValue*> GetArray(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		bool IsNull(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		bool IsNone(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		bool IsEmpty(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
        bool HasKey(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		USimpleJsonObject* SetNumber(FString Field, float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		USimpleJsonObject* SetString(FString Field, FString Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		USimpleJsonObject* SetBool(FString Field, bool Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		USimpleJsonObject* SetObject(FString Field, USimpleJsonObject* JsonObjet);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		USimpleJsonObject* SetArray(FString Field, TArray<USimpleJsonValue*> Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		FString Stringify(bool pretty = false);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		USimpleJsonValue* AsValue();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonObject")
		bool IsValidObject();

	static USimpleJsonObject* Get(TSharedPtr<FJsonObject> Json);
	static USimpleJsonObject* GetInvalid();

public:
	TSharedPtr<FJsonObject> Original;
	bool invalidJson = false;
};
