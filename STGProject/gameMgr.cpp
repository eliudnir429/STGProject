#include "gameMgr.h"
#include "DxLib.h"
#include "player.h"
#include "shot.h"
#include "enemy.h"
#include "bossEnemy.h"

int gameMgr::frame = 0;

gameMgr::gameMgr() {
	_player = new player();
//	_shot = new shot();
	_enemy = new enemy();
	_boss = std::make_shared<bossEnemy>(100.f, 100.f);
}

gameMgr::~gameMgr() {
	delete _player;
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
