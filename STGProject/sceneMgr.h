#pragma once
#include <memory>
#include "task.h"

enum GAME_STATE {
	GAME_TITLE,
	GAME_MAIN,
	GAME_RESULT,
	GAME_CONFIG,
	GAME_EXIT,
};

class sceneMgr {
public:
	sceneMgr();
	~sceneMgr() = default;
	void update();
	void draw();
	static void changeState(GAME_STATE state);
	void changeScene();

private:
	static GAME_STATE _state;
	static bool sceneChangeFlag;
	std::shared_ptr<task> _pScene;
};