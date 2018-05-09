#pragma once
#include "baseScene.h"
#include "baseObject.h"
#include <memory>

class gameMgr :public baseScene {
public:
	gameMgr();
	~gameMgr();
	void update();
	void draw();
	static int getCurrentFrame();

private:
	static int frame;
	baseObject* _player;
	baseObject* _shot;
	baseObject* _enemy;
	std::shared_ptr<baseObject> _boss;
};