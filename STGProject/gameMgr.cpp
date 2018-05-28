#include "gameMgr.h"
#include <DxLib.h>
#include "define.h"

int gameMgr::frame = 0;

gameMgr::gameMgr() {
	_board = std::make_shared<board>();
	_effectMgr = std::make_shared<effectMgr>();

	_eShotMgr = std::make_shared<eShotMgr>();
	_enemyMgr = std::make_shared<enemyMgr>(_eShotMgr, _effectMgr);

	_pShotMgr = std::make_shared<pShotMgr>(_enemyMgr, _effectMgr);
	_player = std::make_shared<player>(_pShotMgr);
}

bool gameMgr::update() {
	frame++;
	
	_board->update();
	_effectMgr->update();

	_eShotMgr->update();
	_enemyMgr->update();

	_pShotMgr->update();
	_player->update();

	return true;
}

void gameMgr::draw() const {
	_board->draw();
	_effectMgr->draw();

	_eShotMgr->draw();
	_enemyMgr->draw();

	_pShotMgr->draw();
	_player->draw();

	DrawFormatString(define::OUT_W + 50, 50, GetColor(255, 255, 255), "frame:%d", frame);
	DrawFormatString(define::OUT_W + 50, 100, GetColor(255, 255, 255), "time:%d", frame / 60);
}
