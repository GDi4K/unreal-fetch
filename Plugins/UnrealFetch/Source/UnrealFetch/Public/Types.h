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
struct UNREALFETCH_API FFetchHeader
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Value;
};

USTRUCT(BlueprintType)
struct UNREALFETCH_API FFetchOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<FFetchOptionsMethod> Method = FFetchOptionsMethod::GET;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FFetchHeader> Headers;
};

USTRUCT(BlueprintType)
struct UNREALFETCH_API FFetchJsonOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<FFetchOptionsMethod> Method = FFetchOptionsMethod::GET;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USimpleJsonValue* Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FFetchHeader> Headers;
};

/**
 * 
 */
UCLASS()
class UNREALFETCH_API UTypes : public UObject
{
	GENERATED_BODY()
	
};
