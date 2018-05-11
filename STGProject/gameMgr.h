#pragma once
#include "baseScene.h"
#include <memory>
#include "board.h"
#include "player.h"
#include "enemy.h"
#include "bossEnemy.h"
#include "shot.h"

class gameMgr :public baseScene {
public:
	gameMgr();
	~gameMgr() = default;
	void update();
	void draw();

private:
	static int frame;
	std::shared_ptr<board> _board;
	std::shared_ptr<player> _player;
	std::shared_ptr<enemy> _enemy;
	std::shared_ptr<bossEnemy> _boss;
	std::shared_ptr<shot> _shot;
};