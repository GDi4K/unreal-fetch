// Fill out your copyright notice in the Description page of Project Settings.


#include "FetchRequest.h"

UFetchRequest::UFetchRequest()
{

}

void UFetchRequest::Process(FString Url, FFetchErrorDelegate OnError, FFetchResponseDelegate OnResponse)
{
	ResponseHandler = OnResponse;
	ErrorHandler = OnError;

	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->SetURL(Url);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), TEXT("unreal-fetch"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("text/plain"));

	Request->OnProcessRequestComplete().BindUObject(this, &UFetchRequest::OnResponse);
	Request->ProcessRequest();
}

void UFetchRequest::OnResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	if (!bSuccess)
	{
		if (Response.IsValid())
		{
			ErrorHandler.Execute("Request Failed with error: " + Response->GetContentAsString());
			return;
		}


		ErrorHandler.Execute("Request failed without making a request");
		return;
	}

	int32 StatusCode = Response->GetResponseCode();
	ResponseHandler.Execute(StatusCode, Response->GetContentAsString());
}