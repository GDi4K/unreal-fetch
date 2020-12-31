// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimpleJsonObject.h"
#include "Json.h"
#include "SimpleJsonValue.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class UNREALFETCH_API USimpleJsonValue : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
		float AsNumber();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString AsString();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool AsBool();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		USimpleJsonObject* AsObject();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		TArray<USimpleJsonValue*> AsArray();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsNull();

	static USimpleJsonValue* Get(TSharedPtr<FJsonValue> JsonValue);

public:
	TSharedPtr<FJsonValue> Original;
};
