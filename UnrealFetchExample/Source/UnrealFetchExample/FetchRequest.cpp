// Fill out your copyright notice in the Description page of Project Settings.


#include "FetchRequest.h"

UFetchRequest::UFetchRequest()
{
	FetchResponse = NewObject<UFetchResponse>();
}

void UFetchRequest::Process(FString Url)
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->SetURL(Url);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), TEXT("unreal-fetch"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("text/plain"));

	Request->OnProcessRequestComplete().BindUObject(this, &UFetchRequest::OnResponse);
	Request->ProcessRequest();
	bStarted = true;
}

void UFetchRequest::OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	bFinished = true;
	bSuccessful = bSuccess;

	if (!bSuccess)
	{
		if (Response.IsValid())
		{
			OnErrorDelegate.ExecuteIfBound("Request Failed with an error: " + Response->GetContentAsString());
			return;
		}


		OnErrorDelegate.ExecuteIfBound("Request failed without making a request");
		return;
	}

	FetchResponse->StatusCode = Response->GetResponseCode();
	FetchResponse->ResponseText = Response->GetContentAsString();

	OnTextDelegate.ExecuteIfBound(FetchResponse->ResponseText, FetchResponse);

	// JSON parsing
	TSharedPtr<FJsonObject> ParsedJSON;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FetchResponse->ResponseText);

	if (OnJsonDelegate.IsBound()) {
		if (FJsonSerializer::Deserialize(Reader, ParsedJSON))
		{
			UE_LOG(LogTemp, Warning, TEXT("JSON Parsing Success: %d"), ParsedJSON->GetObjectField("data")->GetIntegerField("id"))
			OnJsonDelegate.ExecuteIfBound(USimpleJson::Get(ParsedJSON), FetchResponse);
		}
		else {
			OnErrorDelegate.ExecuteIfBound("Invalid JSON as the response");
		}
	}
}

UFetchRequest* UFetchRequest::OnText(FFetchTextResponseDelegate Event)
{
	OnTextDelegate = Event;
	return this;
}

UFetchRequest* UFetchRequest::OnError(FFetchErrorDelegate Event)
{
	OnErrorDelegate = Event;
	return this;
}

UFetchRequest* UFetchRequest::OnJson(FFetchJsonResponseDelegate Event)
{
	OnJsonDelegate = Event;
	return this;
}
