#pragma once
#include "baseScene.h"
#include "baseObject.h"

class gameMgr :public baseScene {
public:
	gameMgr();
	~gameMgr() = default;
	void update();
	void draw();

private:
	baseObject* _player;
	baseObject* _shot;
};