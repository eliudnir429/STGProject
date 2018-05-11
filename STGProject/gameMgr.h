#pragma once
#include "baseScene.h"
#include <memory>
#include "board.h"
#include "player.h"
#include "enemyMgr.h"
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
	std::shared_ptr<enemyMgr> _enemyMgr;
	std::shared_ptr<shot> _shot;
};