// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimpleJsonObject.generated.h"

/**
 *
 */
UCLASS()
class UNREALFETCHEXAMPLE_API USimpleJsonObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool GetObject(FString Field, USimpleJsonObject*& JsonObjet);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		float GetNumber(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetString(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool GetBool(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		TArray<USimpleJsonValue*> GetArray(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsNull(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsNone(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsEmpty(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		USimpleJsonObject* SetNumber(FString Field, float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		USimpleJsonObject* SetString(FString Field, FString Value);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		USimpleJsonObject* SetBool(FString Field, bool Value);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		USimpleJsonObject* SetObject(FString Field, USimpleJsonObject* JsonObjet);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString Stringify(bool pretty = false);

	static USimpleJsonObject* Get(TSharedPtr<FJsonObject> Json);
	static USimpleJsonObject* GetInvalid();

public:
	TSharedPtr<FJsonObject> Original;
	bool invalidJson = false;
};
