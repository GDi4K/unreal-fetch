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
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		float AsNumber();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		FString AsString();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		bool AsBool();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		USimpleJsonObject* AsObject();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		TArray<USimpleJsonValue*> AsArray();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Scripting | Javascript")
		bool IsNull();

	static USimpleJsonValue* Get(TSharedPtr<FJsonValue> JsonValue);

public:
	TSharedPtr<FJsonValue> Original;
};
