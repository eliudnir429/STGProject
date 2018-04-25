#include "sceneMgr.h"
#include "title.h"
#include "gameMgr.h"

GAME_STATE sceneMgr::state = GAME_TITLE;

sceneMgr::~sceneMgr()
{
	delete pScene;
}

void sceneMgr::setScene(GAME_STATE tmp) {
	sceneMgr::state = tmp;
}

void sceneMgr::changeScene() {
	switch (state) {
	case GAME_TITLE:
		pScene = new title();
		break;

	case GAME_MAIN:
		pScene = new gameMgr();
		break;

	case GAME_RESULT:
		break;

	default:
		break;
	}
}

void sceneMgr::update() {
	changeScene();
	pScene->update();
}

void sceneMgr::draw() {
	pScene->draw();
}