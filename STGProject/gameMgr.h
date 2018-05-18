#pragma once
#include "task.h"
#include "board.h"
#include "player.h"
#include "enemyMgr.h"
#include "pShotMgr.h"
#include "effectMgr.h"

class gameMgr :public task {
public:
	gameMgr();
	~gameMgr() = default;
	bool update();
	void draw() const;

private:
	static int frame;
	std::shared_ptr<board> _board;
	std::shared_ptr<player> _player;
	std::shared_ptr<enemyMgr> _enemyMgr;
	std::shared_ptr<pShotMgr> _pShotMgr;
	std::shared_ptr<effectMgr> _effectMgr;
};