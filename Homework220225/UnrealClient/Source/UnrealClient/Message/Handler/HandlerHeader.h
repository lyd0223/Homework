#pragma once																									  
#include "CoreMinimal.h"																						  
																												  
#include "ThreadHandlerLoginResultMessage.h"																	  
#include "ThreadHandlerChatMessage.h"																			  
#include "ThreadHandlerServerDestroyMessage.h"																  
																												  
template<typename MessageHandler, typename MessageType>															  
void OnMessageProcess(std::shared_ptr<GameServerMessage> _Message, UClientGameInstance* _Inst, UWorld* _World)	  
{																												  
	std::shared_ptr<MessageType> ConvertMessage = std::static_pointer_cast<MessageType>(_Message);				  
	if (nullptr == ConvertMessage)																				  
	{																											  
		return;																									  
	}																											  
																												  
	MessageHandler Cmd = MessageHandler(ConvertMessage);														  
	Cmd.Init(_Inst, _World);																					  
	Cmd.Start();																								  
}																												  
																												  
void CheckHandler(Diapatchar& Dis, class UClientGameInstance* Inst, UWorld* World)								  
{														
	Dis.AddHandler(static_cast<uint32_t>(MessageId::LoginResult), std::bind(&OnMessageProcess<ThreadHandlerLoginResultMessage, LoginResultMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::ServerDestroy), std::bind(&OnMessageProcess<ThreadHandlerServerDestroyMessage, ServerDestroyMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::MonsterCreate), std::bind(&OnMessageProcess<ThreadHandlerMonsterCreateMessage, MonsterCreateMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(MessageId::Chat), std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, std::placeholders::_2));	
}																																													
