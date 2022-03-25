#pragma once
#include <GameServerCore\ThreadHandlerBase.h>

class ThreadHandlerJoinMessage final
	: public ThreadHandlerBase<JoinMessage>
{
private: // Member Var
	// ó���� ���
	JoinResultMessage JoinResultMessage_;

public: // Default
	ThreadHandlerJoinMessage();
	~ThreadHandlerJoinMessage();
	ThreadHandlerJoinMessage(const ThreadHandlerJoinMessage& _Other) = delete;
	ThreadHandlerJoinMessage(ThreadHandlerJoinMessage&& _Other) noexcept = delete;

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Start() override;

public:


private:
	// �� �޼����� ó���ϴ� �ܰ�
	void DBCheck();

	// �� �޼����� ó���� �������� ����Ǵ� �Լ�
	void ResultSend();



protected:
	ThreadHandlerJoinMessage& operator=(const ThreadHandlerJoinMessage& _Other) = delete;
	ThreadHandlerJoinMessage& operator=(ThreadHandlerJoinMessage&& _Other) = delete;

};
