#include "title.h"
#include "DxLib.h"
#include "keyboard.h"
#include "sceneMgr.h"

int title::selectNum = 0;

void title::update() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "selectNum[%d]", selectNum);

	keyboardUpdate();
	if (keyboardGet(KEY_INPUT_DOWN) == 1) {
		selectNum = (selectNum + 1) % MENU_NUM;
	}
	if (keyboardGet(KEY_INPUT_UP) == 1) {
		selectNum = (selectNum + 1) % MENU_NUM;
	}
	if (keyboardGet(KEY_INPUT_Z) == 1) {
		switch (selectNum) {
		case 0:
			sceneMgr::setScene(GAME_MAIN);
			break;

		case 1:
			sceneMgr::setScene(GAME_CONFIG);
			break;

		case 2:
			sceneMgr::setScene(GAME_EXIT);
			break;

		default:
			break;
		}
	}
	for (int i = 0; i < MENU_NUM; i++) {
		if (selectNum == i) {
			titleElements[i].x = 80;
		}
		else {
			titleElements[i].x = 100;

		}
	}
}

void title::draw() {
	for (int i = 0; i < MENU_NUM; i++) {
		DrawFormatString(titleElements[i].x, titleElements[i].y, GetColor(255, 255, 255), titleElements[i].name);
	}
}