// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "SimpleJsonValue.h"
#include "UObject/NoExportTypes.h"
#include "SimpleJson.generated.h"

/**
 * 
 */
UCLASS()
class FETCH_API USimpleJson : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJson(FString InputJson);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJsonSync(FString InputJson)
	{
		return MakeJson(InputJson);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJsonNumber(float Number);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJsonNumberSync(float Number)
	{
		return MakeJsonNumber(Number);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJsonBool(bool Value);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJsonBoolSync(bool Value)
	{
		return MakeJsonBool(Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJsonString(FString Value);
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJsonStringSync(FString Value)
	{
		return MakeJsonString(Value);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJsonNull();
	UFUNCTION(BlueprintCallable, Category = "Fetch | SimpleJson")
	static USimpleJsonValue* MakeJsonNullSync()
	{
		return MakeJsonNull();
	}
};
