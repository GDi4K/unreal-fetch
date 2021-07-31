// Copyright (c) 2020 Arunoda Susiripala. All Rights Reserved.


#include "FetchAPI.h"
#include "FetchRequest.h"
#include "Misc/Base64.h"

// Sets default values for this component's properties
UFetchAPI::UFetchAPI()
{

}

UFetchRequest* UFetchAPI::Fetch(FString Url, FFetchOptions Options)
{
	UFetchRequest* Request = NewObject<UFetchRequest>();
	Request->Process(Url, Options);

	return Request;
}

UFetchRequest* UFetchAPI::FetchJson(FString Url, FFetchJsonOptions Options)
{
	FFetchOptions RealOptions;
	RealOptions.Headers.Add({ "Content-Type", "application/json" });
	RealOptions.Headers.Add({ "Accept", "application/json" });

	for (FFetchHeader Header : Options.Headers)
	{
		RealOptions.Headers.Push(Header);
	}

	RealOptions.Method = Options.Method;

	if (Options.Body != nullptr)
	{
		RealOptions.Body = Options.Body->AsObject()->Stringify();
	}

	return Fetch(Url, RealOptions);
}

FFetchHeader UFetchAPI::MakeBasicAuthHeader(FString Username, FString Password)
{
	FFetchHeader Header;

	Header.Key = "Authorization";
	Header.Value = "Basic " + FBase64::Encode(Username + ":" + Password);
	
	return Header;
}

FFetchHeader UFetchAPI::MakeOAuthHeader(FString Token)
{
	return {
		"Authorization",
		"Bearer " + Token
	};
}
