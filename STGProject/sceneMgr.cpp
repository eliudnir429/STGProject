#include "sceneMgr.h"
#include "title.h"
#include "gameMgr.h"

GAME_STATE sceneMgr::_state = GAME_TITLE;
bool sceneMgr::sceneChangeFlag = false;

sceneMgr::sceneMgr() {
	_pScene = std::make_shared<title>();
}	

void sceneMgr::update() {
	if (sceneChangeFlag) {
		changeScene();
	}
	_pScene->update();
}

void sceneMgr::draw() {
	_pScene->draw();
}

void sceneMgr::changeState(GAME_STATE state) {
	_state = state;
	sceneChangeFlag = true;
}

void sceneMgr::changeScene() {
	switch (_state)
	{
	case GAME_TITLE:
		_pScene = std::make_shared<title>();
		break;
	case GAME_MAIN:
		_pScene = std::make_shared<gameMgr>();
		break;
	case GAME_RESULT:
		break;
	case GAME_CONFIG:
		break;
	case GAME_EXIT:
		break;
	default:
		break;
	}
	sceneChangeFlag = false;
}