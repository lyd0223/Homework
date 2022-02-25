#include <GameServerBase/GameServerFile.h>
#include <GameServerBase/GameServerDirectory.h>
#include <GameServerBase/GameServerString.h>
#include <GameServerBase/GameServerDebug.h>

#pragma comment(lib, "GameServerBase.lib")




class MemberInfo
{
public:
	std::string MemberText;
	std::string Type;
	std::string Name;
};

class MessageInfo
{
public:
	std::string Name;
	std::vector<MemberInfo> Member;
};

void SerializerTypeCheck(std::string& _Text, MemberInfo& _MemberInfo)
{
	if (_MemberInfo.Type == "std::string")
	{
		_Text += "        _Serializer << " + _MemberInfo.Name + ";\n";
	}
	else if (_MemberInfo.Type == "int")
	{
		_Text += "        _Serializer << " + _MemberInfo.Name + ";\n";
	}
	else
	{
		if (_MemberInfo.Type[0] == 'E')
		{
			_Text += "        _Serializer<<static_cast<int>(" + _MemberInfo.Name + ");\n";
		}
		else
		{
			GameServerDebug::AssertDebugMsg("파악할수 없는 타입이 체크되었습니다. Name : " + _MemberInfo.Name + " Type : " + _MemberInfo.Type);
		}
	}
}

void DeSerializerTypeCheck(std::string& _Text, MemberInfo& _MemberInfo)
{
	if (_MemberInfo.Type == "std::string")
	{
		_Text += "        _Serializer >> " + _MemberInfo.Name + ";\n";
	}
	else if (_MemberInfo.Type == "int")
	{
		_Text += "        _Serializer >> " + _MemberInfo.Name + ";\n";
	}
	else
	{
		if (_MemberInfo.Type[0] == 'E')
		{
			_Text += "        _Serializer>>static_cast<int>(" + _MemberInfo.Name + ");\n";
		}
		else
		{
			GameServerDebug::AssertDebugMsg("파악할수 없는 타입이 체크되었습니다. Name : " + _MemberInfo.Name + " Type : " + _MemberInfo.Type);
		}
	}
}



void MessageHeaderCreate(std::vector<MessageInfo>& _Collection, std::string& _Text)
{
	std::string MessageText;

	MessageText += "#pragma once\n";
	MessageText += "#include \"GameServerMessage.h\"\n";
	MessageText += "\n";


	for (size_t i = 0; i < _Collection.size(); i++)
	{
		MessageText += "class " + _Collection[i].Name + "Message : public GameServerMessage                    \n";
		MessageText += "{                                                               \n";
		MessageText += "public:                                                         \n";

		std::vector<MemberInfo>& MemberList = _Collection[i].Member;

		for (size_t m = 0; m < MemberList.size(); m++)
		{
			MessageText += "\t" + MemberList[m].MemberText + ";\n";
		}

		MessageText += "                                                                \n";
		MessageText += "public:                                                         \n";
		MessageText += "    " + _Collection[i].Name + "Message()                                               \n";
		MessageText += "        : GameServerMessage(EMessageType::" + _Collection[i].Name + ")                    \n";
		for (size_t m = 0; m < MemberList.size(); m++)
		{
			MessageText += "        , " + MemberList[m].Name + "()\n";
		}
		MessageText += "    {                                                           \n";
		MessageText += "                                                                \n";
		MessageText += "    }                                                           \n";
		MessageText += "                                                                \n";
		MessageText += "    virtual ~" + _Collection[i].Name + "Message() {}                                   \n";
		MessageText += "                                                                \n";
		MessageText += "    virtual int SizeCheck()                                     \n";
		MessageText += "    {                                                           \n";
		if (0 != MemberList.size())
		{
			MessageText += "\t\treturn ";

			for (size_t m = 0; m < MemberList.size(); m++)
			{
				MessageText += "DataSizeCheck(" + MemberList[m].Name + ")";
				MessageText += m != MemberList.size() - 1 ? " + " : ";\n";
			}
		}
		else
		{
			MessageText += "\t\treturn 0;";
		}
		MessageText += "    }                                                           \n";
		MessageText += "                                                                \n";
		MessageText += "    void Serialize(GameServerSerializer& _Serializer)           \n";
		MessageText += "    {                                                           \n";
		MessageText += "        GameServerMessage::Serialize(_Serializer);              \n";
		for (size_t m = 0; m < MemberList.size(); m++)
		{
			SerializerTypeCheck(MessageText, MemberList[m]);
		}
		MessageText += "\n";
		MessageText += "    }                                                           \n";
		MessageText += "                                                                \n";
		MessageText += "    void DeSerialize(GameServerSerializer& _Serializer)         \n";
		MessageText += "    {                                                           \n";
		MessageText += "        GameServerMessage::DeSerialize(_Serializer);            \n";
		for (size_t m = 0; m < MemberList.size(); m++)
		{
			DeSerializerTypeCheck(MessageText, MemberList[m]);
		}
		MessageText += "\n";
		MessageText += "    }                                                           \n";
		MessageText += "};                                                              \n";
		MessageText += "\n";
	}

	_Text = MessageText;
}

void MessageReflection(std::vector<MessageInfo>& _Collection, const std::string& _Code)
{
	std::vector<std::string> ClientMessageString = GameServerString::split(_Code, '|');
	for (size_t i = 0; i < ClientMessageString.size(); i++)
	{
		if (ClientMessageString[i] == "")
		{
			continue;
		}

		std::vector<std::string> MemberAndName = GameServerString::split(ClientMessageString[i], '-');

		std::string& Name = MemberAndName[0];

		MessageInfo Info;
		Info.Name = Name;

		if (1 >= MemberAndName.size())
		{
			_Collection.push_back(Info);
			continue;
		}


		std::string& MmeberInfo = MemberAndName[1];


		std::vector<std::string> Members = GameServerString::split(MmeberInfo, ';');

		for (size_t i = 0; i < Members.size(); i++)
		{
			MemberInfo NewInfo;

			NewInfo.MemberText = Members[i];

			GameServerString::ClearText(NewInfo.MemberText);

			if (NewInfo.MemberText == "")
			{
				continue;
			}

			std::vector<std::string> TypeAndName = GameServerString::split(NewInfo.MemberText, ' ');

			NewInfo.Type = TypeAndName[0];
			NewInfo.Name = TypeAndName[1];

			Info.Member.push_back(NewInfo);

		}

		_Collection.push_back(Info);
	}
}

//텍스트
std::string EnumFileText = "";
std::string ConvertFileText = "";
std::string ClientToServerText = "";
std::string ServerToClientText = "";
std::string ServerAndClientText = "";
std::string DisText = "";

std::string ClientSerializerHeaderText = "";
std::string ClientSerializerCppText = "";
std::string ClientGameServerMessageHeaderText = "";
std::string ClientServerToClientHeaderText = "";
std::string ClientClientToServerHeaderText = "";
std::string ClientServerAndClientHeaderText = "";
std::string ClientMessagesHeaderText = "";
std::string ClientMessagesTypeEnumText = "";
std::string ClientMessageConverterHeaderText = "";
std::string ClientMessageConverterCppText = "";
std::string ClientDisText = "";

void SaveFile(GameServerDirectory& _FileDir, const std::string& _FileName, const std::string& _Text)
{
	std::string SavePath = _FileDir.PathToPlusFileName(_FileName);
	GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
	SaveFile.Write(_Text.c_str(), _Text.size());
}

int main()
{
	std::vector<MessageInfo> AllMessage;
	std::vector<MessageInfo> ClientMessage;
	std::vector<MessageInfo> ServerMessage;
	std::vector<MessageInfo> ServerClientMessage;

	// 만들고 나면 다 단순복사가 됩니다 ok?
	{
		GameServerDirectory LoadDir;
		LoadDir.MoveParent();
		LoadDir.MoveChild("GameServerMessage\\Info");
		{
			GameServerFile LoadFile = { LoadDir.PathToPlusFileName("MessageClient.txt"), "rt" };
			std::string Code = LoadFile.GetString();

			MessageReflection(ClientMessage, Code);
			int a = 0;
		}

		{
			GameServerFile LoadFile = { LoadDir.PathToPlusFileName("MessageServer.txt"), "rt" };
			std::string Code = LoadFile.GetString();

			MessageReflection(ServerMessage, Code);
			int a = 0;
		}

		{
			GameServerFile LoadFile = { LoadDir.PathToPlusFileName("MessageServerAndClient.txt"), "rt" };
			std::string Code = LoadFile.GetString();

			MessageReflection(ServerClientMessage, Code);
			int a = 0;
		}

		for (size_t i = 0; i < ClientMessage.size(); i++)
		{
			AllMessage.push_back(ClientMessage[i]);
		}
		for (size_t i = 0; i < ServerMessage.size(); i++)
		{
			AllMessage.emplace_back(ServerMessage[i]);
		}
		for (size_t i = 0; i < ServerClientMessage.size(); i++)
		{
			AllMessage.emplace_back(ServerClientMessage[i]);
		}


	}


	/////////////////////////////////// 서버 파일생성
	{
		GameServerDirectory FileDir;
		FileDir.MoveParent("Homework220225");
		FileDir.MoveChild("PorjectCode//GameServerMessage");
		{
			///ENUMFILE CREATE////////////////////////////////////////////////////////////////////////////

			EnumFileText += "#pragma once\n\nenum class EMessageType \n{\n";

			for (size_t i = 0; i < AllMessage.size(); i++)
			{
				EnumFileText += "\t" + AllMessage[i].Name + ",\n";
			}

			EnumFileText += "\t";
			EnumFileText += "MAX";
			EnumFileText += "\n";
			EnumFileText += "};";

			///////////////////////////////////////////////////////////////////////////////
		}

		{
			///CONVERT FILE CREATE////////////////////////////////////////////////////////////////////////////

			ConvertFileText = "#include \"PreCompile.h\"\n";
			ConvertFileText += "#include \"MessageConverter.h\"\n";
			ConvertFileText += "#include <memory>\n";
			ConvertFileText += "MessageConverter::MessageConverter(const std::vector<unsigned char>&_Buffer)\n";
			ConvertFileText += "\t: m_Buffer(_Buffer)\n";
			ConvertFileText += "{\n";
			ConvertFileText += "\tGameServerSerializer Sr = GameServerSerializer(m_Buffer);\n";
			ConvertFileText += "\n";
			ConvertFileText += "\tEMessageType Type;\n";
			ConvertFileText += "\tmemcpy_s(&Type, sizeof(EMessageType), &m_Buffer[0], sizeof(EMessageType));\n";
			ConvertFileText += "\tswitch (Type)\n\t{\n";

			for (size_t i = 0; i < AllMessage.size(); i++)
			{
				ConvertFileText += "\tcase EMessageType::" + AllMessage[i].Name + ":\n";
				ConvertFileText += "\t\tm_Message = std::make_shared<" + AllMessage[i].Name + "Message>();\n";
				ConvertFileText += "\t\tbreak;\n";
			}

			ConvertFileText += "\tdefault:\n\t\treturn;\n\t}\n\tm_Message->DeSerialize(Sr);\n}";



			///////////////////////////////////////////////////////////////////////////////
		}

		///Message Header////////////////////////////////////////////////////////////////////////////
		{

			MessageHeaderCreate(ClientMessage, ClientToServerText);

			MessageHeaderCreate(ServerMessage, ServerToClientText);

			MessageHeaderCreate(ServerClientMessage, ServerAndClientText);

		}
		///////////////////////////////////////////////////////////////////////////////


		{
			///DisFile CREATE////////////////////////////////////////////////////////////////////////////

			GameServerDirectory FileDir;
			FileDir.MoveParent("Homework220225");
			FileDir.MoveChild("PorjectCode//GameServerApp");

			DisText += "#include \"PreCompile.h\"																																							\n";
			DisText += "#include \"ServerDispatcher.h\"																																						\n";
			DisText += "#include <GameServerBase\\GameServerDebug.h>																																			\n";
			DisText += "																																													\n";
			DisText += "#include \"ThreadHandlerLoginMessage.h\"																																			\n";
			DisText += "#include \"ThreadHandlerChatMessage.h\"																																				\n";
			DisText += "																																													\n";
			DisText += "Dispatcher<TCPSession> Dis;																																							\n";
			DisText += "																																													\n";
			DisText += "template<typename MessageHandler, typename EMessageType>																																\n";
			DisText += "void OnMessageProcess(std::shared_ptr<TCPSession> _Session, std::shared_ptr<GameServerMessage> _Message)																			\n";
			DisText += "{																																													\n";
			DisText += "	std::shared_ptr<EMessageType> ConvertMessage = std::dynamic_pointer_cast<EMessageType>(_Message);																					\n";
			DisText += "	if (nullptr == ConvertMessage)																																					\n";
			DisText += "	{																																												\n";
			DisText += "		GameServerDebug::LogError(\"ConvertError\");																																\n";
			DisText += "		return;																																										\n";
			DisText += "	}																																												\n";
			DisText += "																																													\n";
			DisText += "	std::shared_ptr<MessageHandler> Cmd = std::make_shared<MessageHandler>(_Session, ConvertMessage);																				\n";
			DisText += "	Cmd->Start();																																									\n";
			DisText += "}																																													\n";
			DisText += "																																													\n";
			DisText += "void DispatcherRegistration()																																						\n";
			DisText += "{																																													\n";
			for (size_t i = 0; i < ClientMessage.size(); i++)
			{
				DisText += "	Dis.AddHandler(static_cast<uint32_t>(EMessageType::" + ClientMessage[i].Name + "), std::bind(&OnMessageProcess<ThreadHandler" + ClientMessage[i].Name + "Message, " + ClientMessage[i].Name + "Message>, std::placeholders::_1, std::placeholders::_2));	\n";
			}

			for (size_t i = 0; i < ServerClientMessage.size(); i++)
			{
				DisText += "	Dis.AddHandler(static_cast<uint32_t>(EMessageType::" + ServerClientMessage[i].Name + "), std::bind(&OnMessageProcess<ThreadHandler" + ServerClientMessage[i].Name + "Message, " + ServerClientMessage[i].Name + "Message>, std::placeholders::_1, std::placeholders::_2));	\n";
			}
			DisText += "}																																													\n";

		}

	}


	/////////////////////////////////////////////////////////////// 언리얼로 수정 파일 이동.
	{
		GameServerDirectory FileDir;
		FileDir.MoveParent();
		FileDir.MoveChild("GameServerBase");

		GameServerDirectory SaveDir;
		SaveDir.MoveParent("Homework220225");
		SaveDir.MoveChild("UnrealClient\\Source\\UnrealClient\\Message");

		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("GameServerSerializer.h"), "rt" };
			ClientSerializerHeaderText = LoadFile.GetString();
		}

		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("GameServerSerializer.cpp"), "rt" };
			ClientSerializerCppText = LoadFile.GetString();
			ClientSerializerCppText.erase(0, strlen("#include \"PreCompile.h\"") + 1);

		}
	}


	{
		GameServerDirectory FileDir;
		FileDir.MoveParent("Homework220225");
		FileDir.MoveChild("PorjectCode//GameServerMessage");

		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("GameServerMessage.h"), "rt" };
			ClientGameServerMessageHeaderText = LoadFile.GetString();

			ClientGameServerMessageHeaderText.replace(ClientGameServerMessageHeaderText.find("#include <GameServerBase/GameServerSerializer.h>\n")
				, strlen("#include <GameServerBase/GameServerSerializer.h>\n"), "#include \"GameServerSerializer.h\"\n");

		}


		{
			ClientServerToClientHeaderText = ServerToClientText;


		}



		{
			ClientClientToServerHeaderText = ClientToServerText;

		}


		{
			ClientServerAndClientHeaderText = ServerAndClientText;

		}


		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("Messages.h"), "rt" };
			ClientMessagesHeaderText = LoadFile.GetString();


			//Code.replace(Code.find("#include <GameServerBase/GameServerSerializer.h>\n")
			//    , strlen("#include <GameServerBase/GameServerSerializer.h>\n"), "#include \"GameServerSerializer.h\"\n");

		}

		{
			ClientMessagesTypeEnumText = EnumFileText;

		}


		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("MessageConverter.h"), "rt" };
			ClientMessageConverterHeaderText = LoadFile.GetString();

		}

		{
			ClientMessageConverterCppText = ConvertFileText;

			ClientMessageConverterCppText.erase(0, strlen("#include \"PreCompile.h\"") + 1);


		}


		{
			///DisFile CREATE////////////////////////////////////////////////////////////////////////////
			DisText += "#pragma once																									  \n";
			DisText += "#include \"CoreMinimal.h\"																						  \n";
			DisText += "																												  \n";
			DisText += "#include \"ThreadHandlerLoginResultMessage.h\"																	  \n";
			DisText += "#include \"ThreadHandlerChatMessage.h\"																			  \n";
			DisText += "#include \"ThreadHandlerServerDestroyMessage.h\"																  \n";
			DisText += "																												  \n";
			DisText += "template<class MessageHandler, class EMessageType>															  \n";
			DisText += "void OnMessageProcess(std::shared_ptr<GameServerMessage> _Message, UClientGameInstance* _Inst, UWorld* _World)	  \n";
			DisText += "{																												  \n";
			DisText += "	std::shared_ptr<EMessageType> ConvertMessage = std::static_pointer_cast<EMessageType>(_Message);				  \n";
			DisText += "	if (nullptr == ConvertMessage)																				  \n";
			DisText += "	{																											  \n";
			DisText += "		return;																									  \n";
			DisText += "	}																											  \n";
			DisText += "																												  \n";
			DisText += "	MessageHandler Cmd = MessageHandler(ConvertMessage);														  \n";
			DisText += "	Cmd.Init(_Inst, _World);																					  \n";
			DisText += "	Cmd.Start();																								  \n";
			DisText += "}																												  \n";
			DisText += "																												  \n";
			DisText += "void CheckHandler(Diapatchar& Dis, class UClientGameInstance* Inst, UWorld* World)								  \n";
			DisText += "{														\n";
			for (size_t i = 0; i < ServerMessage.size(); i++)
			{
				DisText += "	Dis.AddHandler(static_cast<uint32_t>(EMessageType::" + ServerMessage[i].Name + "), std::bind(&OnMessageProcess<ThreadHandler" + ServerMessage[i].Name + "Message, " + ServerMessage[i].Name + "Message>, std::placeholders::_1, std::placeholders::_2));	\n";
			}

			for (size_t i = 0; i < ServerClientMessage.size(); i++)
			{
				DisText += "	Dis.AddHandler(static_cast<uint32_t>(EMessageType::" + ServerClientMessage[i].Name + "), std::bind(&OnMessageProcess<ThreadHandler" + ServerClientMessage[i].Name + "Message, " + ServerClientMessage[i].Name + "Message>, std::placeholders::_1, std::placeholders::_2));	\n";
			}
			DisText += "}																																													\n";

		}

		//ServerSave
		{
			GameServerDirectory SaveDir;
			SaveDir.MoveParent("Homework220225");
			SaveDir.MoveChild("PorjectCode//GameServerMessage");

			SaveFile(SaveDir, "MessageTypeEnum.h", EnumFileText);
			SaveFile(SaveDir, "MessageConverter.cpp", ConvertFileText);
			SaveFile(SaveDir, "ClientToServer.h", ClientToServerText);
			SaveFile(SaveDir, "ServerToClient.h", ServerToClientText);
			SaveFile(SaveDir, "ServerAndClient.h", ServerAndClientText);
		}
		{
			GameServerDirectory SaveDir;
			SaveDir.MoveParent("Homework220225");
			SaveDir.MoveChild("PorjectCode//GameServerApp");

			SaveFile(SaveDir, "ServerDispatcher.cpp", DisText);
		}

		//Client Save
		{
			GameServerDirectory SaveDir;
			SaveDir.MoveParent("Homework220225");
			SaveDir.MoveChild("UnrealClient\\Source\\UnrealClient\\Message");

			SaveFile(SaveDir, "GameServerSerializer.h", ClientSerializerHeaderText);
			SaveFile(SaveDir, "GameServerSerializer.cpp", ClientSerializerCppText);
			SaveFile(SaveDir, "GameServerMessage.h", ClientGameServerMessageHeaderText);
			SaveFile(SaveDir, "ServerToClient.h", ClientServerToClientHeaderText);
			SaveFile(SaveDir, "ClientToServer.h", ClientClientToServerHeaderText);
			SaveFile(SaveDir, "ServerAndClient.h", ClientServerAndClientHeaderText);
			SaveFile(SaveDir, "Messages.h", ClientMessagesHeaderText);
			SaveFile(SaveDir, "MessageTypeEnum.h", ClientMessagesTypeEnumText);
			SaveFile(SaveDir, "MessageConverter.h", ClientMessageConverterHeaderText);
			SaveFile(SaveDir, "MessageConverter.cpp", ClientMessageConverterCppText);
			SaveFile(SaveDir, "HandlerHeader.h", DisText);

		}
		return 0;

	}
}
