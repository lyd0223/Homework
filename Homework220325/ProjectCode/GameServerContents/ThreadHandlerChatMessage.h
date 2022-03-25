#pragma once
#include <GameServerNet/TCPSession.h>
#include <GameServerMessage/Messages.h>
#include <GameServerCore\ThreadHandlerBase.h>

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerChatMessage final
	: public ThreadHandlerBase<ChatMessage>
{
private: // Member Var

public: // Default
	ThreadHandlerChatMessage();
	~ThreadHandlerChatMessage();
	ThreadHandlerChatMessage(const ThreadHandlerChatMessage& _Other) = delete;
	ThreadHandlerChatMessage(ThreadHandlerChatMessage&& _Other) noexcept = delete;
	ThreadHandlerChatMessage& operator=(ThreadHandlerChatMessage&& _Other) = delete;
	ThreadHandlerChatMessage& operator=(const ThreadHandlerChatMessage& _Other) = delete;

	void Start() override;

private:

protected:

};