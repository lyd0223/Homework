#pragma once
#include "GameServerMessage.h"

class LoginResultMessage : public GameServerMessage                    
{                                                               
public:                                                         
	EGameServerCode Code;
                                                                
public:                                                         
    LoginResultMessage()                                               
        : GameServerMessage(EMessageType::LoginResult)                    
        , Code()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~LoginResultMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(Code);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer<<static_cast<int>(Code);

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer>>static_cast<int>(Code);

    }                                                           
};                                                              

class ServerDestroyMessage : public GameServerMessage                    
{                                                               
public:                                                         
                                                                
public:                                                         
    ServerDestroyMessage()                                               
        : GameServerMessage(EMessageType::ServerDestroy)                    
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~ServerDestroyMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return 0;    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            

    }                                                           
};                                                              

class MonsterCreateMessage : public GameServerMessage                    
{                                                               
public:                                                         
                                                                
public:                                                         
    MonsterCreateMessage()                                               
        : GameServerMessage(EMessageType::MonsterCreate)                    
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~MonsterCreateMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return 0;    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            

    }                                                           
};                                                              

