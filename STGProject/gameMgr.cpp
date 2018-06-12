#include "gameMgr.h"
#include <DxLib.h>
#include "define.h"

int gameMgr::frame = 0;

gameMgr::gameMgr() {
	_board = std::make_shared<board>();
//	_effectMgr = std::make_shared<effectMgr>();

	_enemyMgr = std::make_shared<enemyMgr>();
	_player = std::make_shared<player>();
	_shotMgr = std::make_shared<shotMgr>();

	_shotMgr->initialize(_player, _enemyMgr);
}

bool gameMgr::update() {
	_board->update();
//	_effectMgr->update();

	_enemyMgr->update();
	_player->update();
	_shotMgr->update();

	frame++;
	return true;
}

void gameMgr::draw() const {
	_board->draw();
//	_effectMgr->draw();

	_enemyMgr->draw();
	_player->draw();
	_shotMgr->draw();

	DrawFormatString(define::OUT_W + 50, 50, GetColor(255, 255, 255), "frame:%d", frame);
	DrawFormatString(define::OUT_W + 50, 100, GetColor(255, 255, 255), "time:%d", frame / 60);
}
