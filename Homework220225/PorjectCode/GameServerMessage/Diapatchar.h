#pragma once
#include <memory>
#include <functional>
#include "Messages.h"
#include "GameServerNet/TCPSession.h"

// OWNER �� ��Ŷ�� ���� ����
template<class OWNER>
using  MessageHandler = std::function<void(std::shared_ptr<OWNER>, std::shared_ptr<GameServerMessage>)>;

// ��κ��� ������ ó����
// � ��Ŷ�� �޾Ҿ�
// �� ��Ŷ�� ó���ؾ� �ϴµ�.
// ������ ȹ�� ��Ŷ�� �޾Ҿ�
// 1. ����������db�� ���ϴ�.
//     �� �������� ������ �������̾�? 
//     ��ŷ�ϰų� �� �̷� ������ �ƴϾ�?

// 2. ĳ����db�� ���ϴ�.
//     �� ������ �������� ĳ���Ϳ��� �־�����.
//     => ĳ������ ������ �����Ѵ�.

// 3. ĳ���Ϳ��� �ٽ� ��ó�� �ƾ��
//    �����ϴ�.

// �� �޼��� ����ó�� ������
//    �̷��� �پ��� �����带 �ѳ����
//    ���� �ܰ踦 ���ľ��ϴ� ����
//    �ϳ��� Ŭ�������� Ȯ���Ҽ� �ְ� ���ִ� �뵵.

// ÷�� : 
template<class OWNER>
class Diapatchar final
{
private: // Member Var
	std::unordered_map<uint32_t, MessageHandler<OWNER>> Handlers_;

public: // Default
	Diapatchar() {}
	~Diapatchar() {}

	bool AddHandler(uint32_t Id, const MessageHandler<OWNER> Handler)	{
		auto Result = Handlers_.insert(std::make_pair(Id, Handler));

		return Result.second;
	}

	bool GetHandler(uint32_t Id, MessageHandler<OWNER>& _Handler) 
	{
		auto Iter = Handlers_.find(Id);

		if (Iter == Handlers_.end())
		{
			return false;
		}

		_Handler = Iter->second;


		return true;
	}


	Diapatchar(const Diapatchar& _Other) = delete;
	Diapatchar(Diapatchar&& _Other) noexcept = delete; 

protected:
	Diapatchar& operator=(const Diapatchar& _Other) = delete;
	Diapatchar& operator=(Diapatchar&& _Other) = delete;

private:

public: // Member Function
};

