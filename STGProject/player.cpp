#include "player.h"
#include "DxLib.h"
#include "keyboard.h"

int player::x = 0;
int player::y = 200;
bool player::playerShotFlag = false;

player::player() {
	img = LoadGraph("img/shot00.png");
}

void player::update() {
	keyboardUpdate();

	if (keyboardGet(KEY_INPUT_UP) > 0) {
		y -= 5;
	}
	if (keyboardGet(KEY_INPUT_DOWN) > 0) {
		y += 5;
	}
	if (keyboardGet(KEY_INPUT_RIGHT) > 0) {
		x += 5;
	}
	if (keyboardGet(KEY_INPUT_LEFT) > 0) {
		x -= 5;
	}

	if (keyboardGet(KEY_INPUT_Z) > 0) {
		playerShotFlag = true;
		DrawFormatString(0, 20, GetColor(255, 255, 255), "shoot");
	}
	if (keyboardGet(KEY_INPUT_Z) == 0) {
		playerShotFlag = false;
		DrawFormatString(0, 20, GetColor(255, 255, 255), "no shoot");
	}
}

void player::draw() {
	DrawFormatString(0, 40, GetColor(255, 255, 255), "player::draw()");
	DrawGraph(x, y, img, TRUE);
}

bool player::getPlayerShotflag() {
	return playerShotFlag;
}