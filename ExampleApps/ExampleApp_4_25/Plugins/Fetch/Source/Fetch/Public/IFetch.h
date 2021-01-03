// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FetchResponse.h"
#include "Json.h"
#include "SimpleJsonObject.h"
#include "SimpleJsonValue.h"
#include "Types.h"

#include "IFetch.generated.h"


DECLARE_DYNAMIC_DELEGATE_TwoParams(FFetchResponseDelegate, int32, StatusCode, FString, Content);
DECLARE_DYNAMIC_DELEGATE_OneParam(FFetchErrorDelegate, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FFetchTextResponseDelegate, FString, TextContent, UFetchResponse*, Response);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FFetchJsonResponseDelegate, USimpleJsonValue*, JsonValue, UFetchResponse*, Response);

/**
 * 
 */
UCLASS()
class FETCH_API UIFetch : public UObject
{
	GENERATED_BODY()
	
};
