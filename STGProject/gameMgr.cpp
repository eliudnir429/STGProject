#include "gameMgr.h"
#include "DxLib.h"
#include "player.h"
#include "shot.h"
#include "enemy.h"

int gameMgr::frame = 0;

gameMgr::gameMgr() {
	_player = new player();
//	_shot = new shot();
	_enemy = new enemy();
}

gameMgr::~gameMgr() {
	delete _player;
	delete _enemy;
}

void gameMgr::update() {
	_player->update();
//	_shot->update();
	_enemy->update();

	frame++;
}

void gameMgr::draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "frame:%d", frame);
	_player->draw();
//	_shot->draw();
	_enemy->draw();
}

int gameMgr::getCurrentFrame() {
	return frame;
}
