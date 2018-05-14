#include "gameMgr.h"
#include "DxLib.h"
#include "define.h"

int gameMgr::frame = 0;

gameMgr::gameMgr() {
	_board = std::make_shared<board>();
	_player = std::make_shared<player>();
	_enemyMgr = std::make_shared<enemyMgr>();
}

void gameMgr::update() {
	frame++;
	
	_board->update();
	_player->update();
	_enemyMgr->update();
}

void gameMgr::draw() {
	_board->draw();
	_player->draw();
	_enemyMgr->draw();

	DrawFormatString(define::OUT_W + 50, 50, GetColor(255, 255, 255), "frame:%d", frame);
	DrawFormatString(define::OUT_W + 50, 100, GetColor(255, 255, 255), "time:%d", frame / 60);
}
