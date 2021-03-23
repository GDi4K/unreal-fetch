// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Json.h"
#include "SimpleJsonObject.h"
#include "SimpleJsonValue.h"
#include "Types.generated.h"

UENUM(BlueprintType)
enum FFetchOptionsMethod
{
	GET,
	POST,
	PUT,
	DELETE
};

USTRUCT(BlueprintType)
struct FETCH_API FFetchHeader
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scripting | Javascript")
		FString Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scripting | Javascript")
		FString Value;
};

USTRUCT(BlueprintType)
struct FETCH_API FFetchOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scripting | Javascript")
		TEnumAsByte<FFetchOptionsMethod> Method = FFetchOptionsMethod::GET;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scripting | Javascript")
		FString Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scripting | Javascript")
		TArray<FFetchHeader> Headers;
};

USTRUCT(BlueprintType)
struct FETCH_API FFetchJsonOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scripting | Javascript")
		TEnumAsByte<FFetchOptionsMethod> Method = FFetchOptionsMethod::GET;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scripting | Javascript")
		USimpleJsonValue* Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scripting | Javascript")
		TArray<FFetchHeader> Headers;
};

/**
 * 
 */
UCLASS()
class FETCH_API UTypes : public UObject
{
	GENERATED_BODY()
	
};
