#pragma once
#include <GameServerCore\ThreadHandlerBase.h>

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerLoginMessage final
	: public ThreadHandlerBase<LoginMessage>
{
private: // Member Var
	// ó���� ���
	LoginResultMessage LoginResult_;

public: // Default
	ThreadHandlerLoginMessage();
	~ThreadHandlerLoginMessage();
	ThreadHandlerLoginMessage(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage(ThreadHandlerLoginMessage&& _Other) noexcept = delete;

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Start() override;

public:


private:
	// �� �޼����� ó���ϴ� �ܰ�
	void DBCheck();

	// �� �޼����� ó���� �������� ����Ǵ� �Լ�
	void ResultSend();



protected:
	ThreadHandlerLoginMessage& operator=(const ThreadHandlerLoginMessage& _Other) = delete;
	ThreadHandlerLoginMessage& operator=(ThreadHandlerLoginMessage&& _Other) = delete;

};

