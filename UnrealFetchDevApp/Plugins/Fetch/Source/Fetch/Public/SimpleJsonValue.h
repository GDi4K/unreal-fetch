// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

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
class FETCH_API USimpleJsonValue : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonValue")
		float AsNumber();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonValue")
		FString AsString();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonValue")
		bool AsBool();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonValue")
		USimpleJsonObject* AsObject();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonValue")
		TArray<USimpleJsonValue*> AsArray();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonValue")
		bool IsNull();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJsonValue")
        bool IsValid();

	static USimpleJsonValue* Get(TSharedPtr<FJsonValue> JsonValue);

public:
	TSharedPtr<FJsonValue> Original;
	bool InvalidJson = false;
};
