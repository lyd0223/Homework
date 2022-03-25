#include "ThreadHandlerJoinResultMessage.h"

ThreadHandlerJoinResultMessage::ThreadHandlerJoinResultMessage(std::shared_ptr<JoinResultMessage> _JoinResultMessage)
	: JoinResultMessage_(_JoinResultMessage)
{
	// UGameplayStatics::
}

void ThreadHandlerJoinResultMessage::Init(UClientGameInstance* _Inst, UWorld* _World)
{
	Inst_ = _Inst;
	World_ = _World;
}

void ThreadHandlerJoinResultMessage::Start()
{
	EJoinResult JoinReulst = JoinResultMessage_->JoinResult;
	switch (JoinReulst)
	{
	case EJoinResult::OK:
		{
			GEngine->AddOnScreenDebugMessage(-1,3.0f,FColor::Blue,TEXT("Join Success"));
			break;
		}
		
	case EJoinResult::Error:
		{
			GEngine->AddOnScreenDebugMessage(-1,3.0f,FColor::Red,TEXT("Join Failed"));
			break;
		}

	case EJoinResult::MAX:
		{
			break;
		}
	}

	// �α��� ui
}
