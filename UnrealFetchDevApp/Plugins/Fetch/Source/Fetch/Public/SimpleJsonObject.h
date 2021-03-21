// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Json.h"
#include "SimpleJsonObject.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class FETCH_API USimpleJsonObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		USimpleJsonObject* GetObject(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		float GetNumber(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		FString GetString(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		bool GetBool(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		TArray<USimpleJsonValue*> GetArray(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		bool IsNull(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		bool IsNone(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		bool IsEmpty(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		USimpleJsonObject* SetNumber(FString Field, float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		USimpleJsonObject* SetString(FString Field, FString Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		USimpleJsonObject* SetBool(FString Field, bool Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		USimpleJsonObject* SetObject(FString Field, USimpleJsonObject* JsonObjet);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		USimpleJsonObject* SetArray(FString Field, TArray<USimpleJsonValue*> Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		FString Stringify(bool pretty = false);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		USimpleJsonValue* AsValue();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		bool IsValidObject();

	static USimpleJsonObject* Get(TSharedPtr<FJsonObject> Json);
	static USimpleJsonObject* GetInvalid();

public:
	TSharedPtr<FJsonObject> Original;
	bool invalidJson = false;
};
