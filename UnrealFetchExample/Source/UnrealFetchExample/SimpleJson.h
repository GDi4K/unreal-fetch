// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimpleJson.generated.h"

/**
 * 
 */
UCLASS()
class UNREALFETCHEXAMPLE_API USimpleJson : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetObject(FString Field, USimpleJson*& JsonObjet);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetNumber(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString GetString(FString Field);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetBool(FString Field);

	static USimpleJson* Get(TSharedPtr<FJsonObject> Json);
	static USimpleJson* GetInvalid();

public:
	TSharedPtr<FJsonObject> Original;
	bool invalidJson = false;
};
