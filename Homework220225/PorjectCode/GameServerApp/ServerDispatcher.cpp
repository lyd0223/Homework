#include "PreCompile.h"																																							
#include "ServerDispatcher.h"																																						
#include <GameServerBase\GameServerDebug.h>																																			
																																													
#include "ThreadHandlerLoginMessage.h"																																			
#include "ThreadHandlerChatMessage.h"																																				
																																													
Dispatcher<TCPSession> Dis;																																							
																																													
template<typename MessageHandler, typename EMessageType>																																
void OnMessageProcess(std::shared_ptr<TCPSession> _Session, std::shared_ptr<GameServerMessage> _Message)																			
{																																													
	std::shared_ptr<EMessageType> ConvertMessage = std::dynamic_pointer_cast<EMessageType>(_Message);																					
	if (nullptr == ConvertMessage)																																					
	{																																												
		GameServerDebug::LogError("ConvertError");																																
		return;																																										
	}																																												
																																													
	std::shared_ptr<MessageHandler> Cmd = std::make_shared<MessageHandler>(_Session, ConvertMessage);																				
	Cmd->Start();																																									
}																																													
																																													
void DispatcherRegistration()																																						
{																																													
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::Login), std::bind(&OnMessageProcess<ThreadHandlerLoginMessage, LoginMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::Chat), std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, std::placeholders::_2));	
}																																													
#pragma once																									  
#include "CoreMinimal.h"																						  
																												  
#include "ThreadHandlerLoginResultMessage.h"																	  
#include "ThreadHandlerChatMessage.h"																			  
#include "ThreadHandlerServerDestroyMessage.h"																  
																												  
template<class MessageHandler, class EMessageType>															  
void OnMessageProcess(std::shared_ptr<GameServerMessage> _Message, UClientGameInstance* _Inst, UWorld* _World)	  
{																												  
	std::shared_ptr<EMessageType> ConvertMessage = std::static_pointer_cast<EMessageType>(_Message);				  
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
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::LoginResult), std::bind(&OnMessageProcess<ThreadHandlerLoginResultMessage, LoginResultMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::ServerDestroy), std::bind(&OnMessageProcess<ThreadHandlerServerDestroyMessage, ServerDestroyMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::MonsterCreate), std::bind(&OnMessageProcess<ThreadHandlerMonsterCreateMessage, MonsterCreateMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::Chat), std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, std::placeholders::_2));	
}																																													
