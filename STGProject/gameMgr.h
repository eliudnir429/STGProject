#pragma once
#include "task.h"
#include "board.h"
#include "player.h"
#include "enemyMgr.h"
#include "pShotMgr.h"
#include "effectMgr.h"
#include "collisionDetect.h"

class gameMgr :public task {
public:
	gameMgr();
	~gameMgr() = default;
	bool update() override;
	void draw() const override;

private:
	static int frame;
	std::shared_ptr<board> _board;
	std::shared_ptr<player> _player;
	std::shared_ptr<enemyMgr> _enemyMgr;
	std::shared_ptr<pShotMgr> _pShotMgr;
	std::shared_ptr<effectMgr> _effectMgr;
	std::shared_ptr<collisionDetect> _collisionDetect;
};