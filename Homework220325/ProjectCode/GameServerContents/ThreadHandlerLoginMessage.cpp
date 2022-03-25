#include "PreCompile.h"
#include "ThreadHandlerLoginMessage.h"
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerString.h>
#include "GameServerUser.h"
#include <GameServerNet\DBConnecter.h>
#include "UserTable.h"
#include <GameServerCore\DBQueue.h>
#include <functional>

// DB�� �����ϴ���
// �����ϴ���
// ���������� ��� ��Ŷ�� ������ �ϱ���
// ���δ� �̾ȿ��� �������� �ϰ�
// ����� �ܺη� ��������� �ȵ˴ϴ�.

// ��� �̷��� �ϰ������ �����ϸ� ū�ϳ��ϴ�.
// �ܿ�� ���� �ƴ϶� �ڵ带 §����� �ǵ��� �ľ��ض�.
// ���� ��������� ���ϴ� �̴ϴ�.
ThreadHandlerLoginMessage::ThreadHandlerLoginMessage()
{

}

ThreadHandlerLoginMessage::~ThreadHandlerLoginMessage()
{

}

void ThreadHandlerLoginMessage::Start()
{
	if (nullptr == TCPSession_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	LoginResult_.Code = EGameServerCode::LoginError;
	DBWork(&ThreadHandlerLoginMessage::DBCheck);
}

void ThreadHandlerLoginMessage::DBCheck(/*GameEngineThread* _Thread*/)
{
	//std::string Name = GameServerThread::GetName();

	//UserTable_SelectIDToUserInfo SelectQuery(LoginMessage_->ID);
	//SelectQuery.DoQuery();

	//if (nullptr == SelectQuery.RowData)
	//{
	//	LoginResult_.Code = EGameServerCode::LoginError;
	//}
	//else 
	//{
	//	LoginResult_.Code = EGameServerCode::OK;
	//}

	//UserTable_InsertUserInfo Query = UserTable_InsertUserInfo("kk", "kk");
	//if (false == Query.DoQuery())
	//{
	//	int a = 0;
	//}


	//// INSERT INTO `userver2`.`user` (`ID`, `PW`) VALUES('c', 'c');

	//NetQueue::Queue(std::bind(&ThreadHandlerLoginMessage::ResultSend, shared_from_this()));

}

void ThreadHandlerLoginMessage::ResultSend()
{
	//std::shared_ptr<GameServerUser> NewUser = std::make_shared<GameServerUser>();
	//GameServerString::UTF8ToAnsi(LoginMessage_->ID, NewUser->ID);

	//TCPSession_->SetLink(NewUser);

	//GameServerSerializer Sr;
	//LoginResult_.Serialize(Sr);
	//TCPSession_->Send(Sr.GetData());

	//GameServerDebug::LogInfo("Login Result Out");

	// std::sheard_ptr<Section> Finds = GetALLSection();
	// Finds->PushSection(TCPSession_, 30)
}