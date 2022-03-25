#include "PreCompile.h"
#include "StudyGameServerCore.h"
#include <GameServerNet\TCPSession.h>
#include <GameServerMessage\Messages.h>
#include "ServerDispatcher.h"

StudyGameServerCore::StudyGameServerCore()
{
}

StudyGameServerCore::~StudyGameServerCore()
{
}

void StudyGameServerCore::UserStart()
{
	DispatcherRegistration();
	// ���ε� ��ų�� ����?
	SetAcceptCallBack(StudyGameServerCore::AcceptEvent);

	// ������ ��
	// AddSection("Ű�� ������ �Ѵ�.", 30);

	// ���� ������ �ο��� ���� �ľ��ؼ� ����� �ø���
	
	// Section* Ptr = GetSection();
	// Ptr->UserCount();
	// AddSection("Ű�� ������ �Ѵ�.", 30);
	// AddSection<Lobby>("�κ�", -1);
	// AddSection<PlayRoom>("�κ�", 30);

}

void StudyGameServerCore::AcceptEvent(std::shared_ptr<TCPSession> _User)
{
	_User->SetRecvCallBack(RecvEvent);

	_User->SetCloseCallBack(CloseEvent);

	std::string LogText = std::to_string(static_cast<int>(_User->GetSocket()));
	GameServerDebug::LogInfo(LogText + "Connect.");
	// FindSection("�κ�");
}


void StudyGameServerCore::RecvEvent(std::shared_ptr<TCPSession> _S, const std::vector<unsigned char>& _Value)
{
	MessageConverter Converter = MessageConverter(_Value);

	if (false == Converter.IsVailed())
	{
		GameServerDebug::AssertDebugMsg("Convert Error");
		return;
	}

	// n�ʵ��� ������ ������ ������ Ŀ�ؼǵ� ���� Ŀ�ؼ��̶�� ���� �߶󳻾� �Ѵ�.
	MessageHandler<TCPSession> Handler;
	std::string MessageCode = std::to_string(Converter.GetMessageIdUint());
	GameServerDebug::LogInfo(MessageCode + " Message In");
	if (false == Dis.GetHandler(Converter.GetMessageIdUint(), Handler))
	{
		// ���⼭�� �޼����� �߸�ó���� �ð��� 
		GameServerDebug::AssertDebugMsg("Message Error");
		return;
	}
	Handler(_S, Converter.GetServerMessage());

}

void StudyGameServerCore::CloseEvent(std::shared_ptr<TCPSession> _S)
{
	std::string LogText = std::to_string(static_cast<int>(_S->GetSocket()));
	GameServerDebug::LogInfo(LogText + "Connect End.");
}

