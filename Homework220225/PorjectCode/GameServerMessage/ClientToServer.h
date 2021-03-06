#pragma once
#include "GameServerMessage.h"

class LoginMessage : public GameServerMessage                    
{                                                               
public:                                                         
	std::string ID;
	std::string PW;
                                                                
public:                                                         
    LoginMessage()                                               
        : GameServerMessage(EMessageType::Login)                    
        , ID()
        , PW()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~LoginMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(ID) + DataSizeCheck(PW);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer << ID;
        _Serializer << PW;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer >> ID;
        _Serializer >> PW;

    }                                                           
};                                                              

