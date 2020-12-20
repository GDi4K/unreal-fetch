// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FetchResponse.h"
#include "Json.h"
#include "SimpleJson.h"
#include "IFetch.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FFetchResponseDelegate, int32, StatusCode, FString, Content);
DECLARE_DYNAMIC_DELEGATE_OneParam(FFetchErrorDelegate, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FFetchTextResponseDelegate, FString, TextContent, UFetchResponse*, Response);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FFetchJsonResponseDelegate, USimpleJson*, JsonObject, UFetchResponse*, Response);

/**
 * 
 */
UCLASS()
class UNREALFETCHEXAMPLE_API UIFetch : public UObject
{
	GENERATED_BODY()
	
};
