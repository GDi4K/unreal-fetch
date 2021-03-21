// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.


#include "FetchResponse.h"

FString UFetchResponse::GetHeader(FString Key)
{
	return Original->GetHeader(Key);
}

UFetchResponse* UFetchResponse::Get(FHttpResponsePtr Response)
{
	UFetchResponse* Instance = NewObject<UFetchResponse>();
	Instance->Original = Response;
	Instance->StatusCode = Response->GetResponseCode();
	Instance->ResponseText = Response->GetContentAsString();

	for (FString Header : Response->GetAllHeaders())
	{
		FString Key;
		FString Value;
		Header.Split(":", &Key, &Value);

		Key.TrimStartAndEndInline();
		Value.TrimStartAndEndInline();

		Instance->Headers.Push({ Key, Value });
	}

	return Instance;
}
