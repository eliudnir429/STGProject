#pragma once
#include "baseScene.h"

enum GAME_STATE {
	GAME_TITLE,
	GAME_MAIN,
	GAME_RESULT,
	GAME_CONFIG,
	GAME_EXIT,
};

class sceneMgr {
public:
	sceneMgr() = default;
	~sceneMgr();
	static void setScene(GAME_STATE);
	void changeScene();
	void update();
	void draw();

private:
	static GAME_STATE state;
	baseScene* pScene;
};