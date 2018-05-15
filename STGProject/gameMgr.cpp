#include "gameMgr.h"
#include "DxLib.h"
#include "define.h"

int gameMgr::frame = 0;

gameMgr::gameMgr() {
	_board = std::make_shared<board>();
	_player = std::make_shared<player>();
	_enemyMgr = std::make_shared<enemyMgr>();
	_pShotMgr = std::make_shared<pShotMgr>(_player, _enemyMgr);
	_effectMgr = std::make_shared<effectMgr>();
	_collisionDetect = std::make_shared<collisionDetect>(_player,_enemyMgr,_pShotMgr,_effectMgr);
}

void gameMgr::update() {
	frame++;
	
	_board->update();
	_player->update();
	_enemyMgr->update();
	_pShotMgr->update();
	_effectMgr->update();
}

void gameMgr::draw() {
	_board->draw();
	_player->draw();
	_enemyMgr->draw();
	_pShotMgr->draw();
	_effectMgr->draw();

	DrawFormatString(define::OUT_W + 50, 50, GetColor(255, 255, 255), "frame:%d", frame);
	DrawFormatString(define::OUT_W + 50, 100, GetColor(255, 255, 255), "time:%d", frame / 60);
}
