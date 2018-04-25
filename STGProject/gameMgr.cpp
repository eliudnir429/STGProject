#include "gameMgr.h"
#include "player.h"
#include "shot.h"

gameMgr::gameMgr() {
	_player = new player();
	_shot = new shot();
}

void gameMgr::update() {
	_player->update();
	_shot->update();
}

void gameMgr::draw() {
	_player->draw();
	_shot->draw();
}