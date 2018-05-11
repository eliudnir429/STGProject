#include "gameMgr.h"
#include "DxLib.h"
#include "define.h"

int gameMgr::frame = 0;

gameMgr::gameMgr() {
	_board = std::make_shared<board>();
	_player = std::make_shared<player>();
	_enemy = std::make_shared<enemy>();
	_boss = std::make_shared<bossEnemy>((float)define::IN_W / 2.f, 0.f);
	_shot = std::make_shared<shot>();
}

void gameMgr::update() {
	frame++;

	_board->update();
	_player->update();
	_enemy->update();
	_boss->update();
	_shot->update();
}

void gameMgr::draw() {
	_board->draw();
	_player->draw();
	_enemy->draw();
	_boss->draw();
	_shot->draw();

	DrawFormatString(define::OUT_W + 50, 50, GetColor(255, 255, 255), "frame:%d", frame);
}
