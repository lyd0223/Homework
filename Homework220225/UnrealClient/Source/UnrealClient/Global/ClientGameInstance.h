// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <string>
#include <vector>
#include <Memory>
#include <functional>
#include "../Message/Messages.h"
#include "../Play/ChatWindow.h"
#include "ClientGameInstance.generated.h"

// std::thread
// ��� �ڵ带 ������Ѽ� ó������ �����Ҽ� ����?
class UnrealRecvThread : public FRunnable 
{
private:
	TAtomic<bool> IsAppClose_;
	FSocket* RecvSocket_;
	TQueue<std::shared_ptr<GameServerMessage>, EQueueMode::Spsc>* MessageQueue_;

public:
	UnrealRecvThread(FSocket* _RecvSocket, TQueue<std::shared_ptr<GameServerMessage>>* MessageQueue_);

	static bool FunctionTest();

	uint32 Run() override;

public:
	void Close();

};

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UClientGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	TQueue<std::shared_ptr<GameServerMessage>> MessageQueue_;

private:
	UnrealRecvThread* RecvThread_;
	FRunnableThread* ThreadRunalbe_;

	ISocketSubsystem* SocketSubSystem_;
	FSocket* NewSocket_;
	// TQueue<TArray<char>>

	// Post
	// FNonAbandonableTask

	// Recv�� �翬�� �����忡�� ó���ϰ� �ɰ��̰�
	// �𸮾��� ������ ����� 2���� ������ ����� �����Ѵ�.
	
	// ��¥ ���ߵ��� ������ �����带 ����� �̴ϴ�.
	// FRunnable // �� ��ӹ��� ������ ������ �� ����°�.
	// FNonAbandonableTask // �� ��ӹ��� ������ ������ �� ����°�.

public:
	FString ID;

	UChatWindow* ChatWindow_;

public:
	UClientGameInstance();
	~UClientGameInstance();


	bool IsThreadCheck();
	bool IsGameCheck();

	bool ServerConnect(const FString& _IPString, const FString& _PORTString);
	void Close();

	bool Send(const std::vector<uint8>& _Data);
	//bool Recv();

	void FinishDestroy() override;
};
