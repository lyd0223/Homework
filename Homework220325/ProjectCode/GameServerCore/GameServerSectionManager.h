#pragma once
#include <vector>
#include <GameServerBase\GameServerThread.h>
#include <unordered_map>
#include "GameServerSection.h"
// ���� :
class GameServerSectionManager
{
public:
	// constrcuter destructer
	GameServerSectionManager();
	~GameServerSectionManager();

	// delete Function
	GameServerSectionManager(const GameServerSectionManager& _Other) = delete;
	GameServerSectionManager(GameServerSectionManager&& _Other) noexcept = delete;
	GameServerSectionManager& operator=(const GameServerSectionManager& _Other) = delete;
	GameServerSectionManager& operator=(GameServerSectionManager&& _Other) noexcept = delete;

protected:

private:
	// ������ 100����� �����尡 100���� �Ǵ°� �ƴմϴ�.
	// �����ϱ� ���ٰ� ȿ���� ������ �ƴϾ�.
	// ��ΰ� ������ ����ֱ⸦ �ٷ��� �ϰų�
	// �Ѹʿ� ���� ������ �ֱ⸦ �ٶ�� �ȵ���?
	// 
	// ������ 10�� ���� 100���� ���� ó���ϴ� ����� �˴ϴ�.
	// Post��.
	// ���������� ������ �˴ϴ�.

	std::vector<std::shared_ptr<GameServerThread>> SecitonThread_;

	// ������ �߰��ϴ� ������ŭ�� ���� �ɾ�� �մϴ�.
	// -1�̸� �뿡 �� ���� ������.
	std::unordered_map<uint32_t, std::shared_ptr<GameServerSection>> AllSeciton_;


};

