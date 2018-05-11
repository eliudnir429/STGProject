#pragma once
#include "baseScene.h"
#include "baseObject.h"
#include <memory>
#include "player.h"
#include "enemy.h"
#include "bossEnemy.h"

class gameMgr :public baseScene {
public:
	gameMgr();
	~gameMgr() = default;
	void update();
	void draw();

private:
	static int frame;
	std::shared_ptr<player> _player;
	std::shared_ptr<enemy> _enemy;
	std::shared_ptr<bossEnemy> _boss;
};