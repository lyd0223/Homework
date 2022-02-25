#pragma once
#include "CoreMinimal.h"
#include <Memory>
#include "../Messages.h"

// �� ���ǵ� ���⼭ �޴´�.
class ThreadHandlerMonsterCreateMessage final
{
private: 
	class UWorld* World_;
	class UClientGameInstance* Inst_;
	std::shared_ptr<ServerDestroyMessage> Message_;

public: // Default
	ThreadHandlerMonsterCreateMessage(std::shared_ptr<ServerDestroyMessage> _LoginMessage);

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Init(UClientGameInstance* _Inst, UWorld* _World);
	void Start();
};

