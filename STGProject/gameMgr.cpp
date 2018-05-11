#include "gameMgr.h"
#include "DxLib.h"
#include <iostream>

int gameMgr::frame = 0;

gameMgr::gameMgr() {
	_player = std::make_shared<player>();
	_enemy = std::make_shared<enemy>();
	_boss = std::make_shared<bossEnemy>(640.f, 0.f);
}

void gameMgr::update() {
	frame++;

	_player->update();
	_enemy->update();
	_boss->update();
}

void gameMgr::draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "frame:%d", frame);

	_player->draw();
	_enemy->draw();
	_boss->draw();
}
