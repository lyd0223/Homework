#include "PreCompile.h"
#include "ThreadHandlerJoinMessage.h"
#include "UserTable.h"
#include <GameServerCore\NetQueue.h>
#include <functional>
#include <GameServerCore\DBQueue.h>

ThreadHandlerJoinMessage::ThreadHandlerJoinMessage()
{

}

ThreadHandlerJoinMessage::~ThreadHandlerJoinMessage()
{

}

void ThreadHandlerJoinMessage::Start()
{
	if (nullptr == TCPSession_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	JoinResultMessage_.JoinResult = EJoinResult::Error;
	DBWork(&ThreadHandlerJoinMessage::DBCheck);
}

void ThreadHandlerJoinMessage::DBCheck(/*GameEngineThread* _Thread*/)
{
	//std::string Name = GameServerThread::GetName();

	UserTable_InsertUserInfo InsertUserInfo(Message_->ID, Message_->PW);
	int result = InsertUserInfo.DoQuery();
	
	JoinResultMessage_.JoinResult = result == true ? EJoinResult::OK : EJoinResult::Error;

	NetQueue::Queue(std::bind(&ThreadHandlerJoinMessage::ResultSend, std::dynamic_pointer_cast<ThreadHandlerJoinMessage>(shared_from_this())));
}

void ThreadHandlerJoinMessage::ResultSend()
{
	//std::shared_ptr<GameServerUser> NewUser = std::make_shared<GameServerUser>();
	//GameServerString::UTF8ToAnsi(LoginMessage_->ID, NewUser->ID);

	//TCPSession_->SetLink(NewUser);

	GameServerSerializer Sr;
	JoinResultMessage_.Serialize(Sr);
	TCPSession_->Send(Sr.GetData());

	GameServerDebug::LogInfo("Join Result Send Success");
}