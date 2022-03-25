#pragma once
#include <memory>
#include "../Messages.h"

class ThreadHandlerJoinResultMessage
{
private: 
	class UWorld* World_;
	class UClientGameInstance* Inst_;
	std::shared_ptr<JoinResultMessage> JoinResultMessage_;


public: // Default
	ThreadHandlerJoinResultMessage(std::shared_ptr<JoinResultMessage> _JoinResultMessage);

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Init(UClientGameInstance* _Inst, UWorld* _World);
	void Start();
	
};
