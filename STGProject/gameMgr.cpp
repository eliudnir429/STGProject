#include "gameMgr.h"
#include "DxLib.h"
#include "shot.h"
#include "enemy.h"
#include "bossEnemy.h"
#include <iostream>

int gameMgr::frame = 0;

gameMgr::gameMgr() {
	DrawFormatString(100, 100, GetColor(255, 255, 255), "gamemgr called");
	_player = std::make_shared<player>();
//	_shot = new shot();
	_enemy = new enemy();
	_boss = std::make_shared<bossEnemy>(640.f, 0.f);
}

gameMgr::~gameMgr() {
	delete _enemy;
}

void gameMgr::update() {
	_player->update();
//	_shot->update();
	_enemy->update();
	_boss->update();

	frame++;
}

void gameMgr::draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "frame:%d", frame);
	_player->draw();
//	_shot->draw();
	_enemy->draw();
	_boss->draw();
}

int gameMgr::getCurrentFrame() {
	return frame;
}
