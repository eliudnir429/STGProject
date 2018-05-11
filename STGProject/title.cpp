#include "title.h"
#include "DxLib.h"
#include "keyboard.h"
#include "sceneMgr.h"

int title::selectNum = 0;

title::title() {
	titleElements[0] = { 80,100,"NEW GAME" };
	titleElements[1] = { 100,150,"CONTINUE" };
	titleElements[2] = { 100,200,"CONFIG" };
	titleElements[3] = { 100,250,"EXIT" };
}

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
		sceneMgr::changeState(GAME_MAIN);
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