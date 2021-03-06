#include "player.h"
#include "define.h"
#include <DxLib.h>
#include "keyboard.h"

player::player() :_x((float)(define::IN_W / 2.0)), _y((float)define::IN_H) {
	LoadDivGraph("img/player00.png", 16, 4, 4, 64, 64, _img, TRUE);
	_counter = 0;
}

bool player::update() {
	_counter++;
	keyboardUpdate();
	move();
	return true;
}

void player::draw() const {
	if (keyboardGet(KEY_INPUT_RIGHT) > 0) {
		DrawRotaGraphF(_x, _y, 1.0, 0.0, _img[10], TRUE);
	}
	else if (keyboardGet(KEY_INPUT_LEFT) > 0) {
		DrawRotaGraphF(_x, _y, 1.0, 0.0, _img[9], TRUE);
	}
	else {
		DrawRotaGraphF(_x, _y, 1.0, 0.0, _img[8], TRUE);
	}
}

void player::move() {
	float moveX = 0, moveY = 0;

	if (keyboardGet(KEY_INPUT_UP) > 0 && _y > define::IN_Y) {
		moveY -= 5;
	}
	if (keyboardGet(KEY_INPUT_DOWN) > 0 && _y < define::IN_H) {
		moveY += 5;
	}
	if (keyboardGet(KEY_INPUT_RIGHT) > 0 && _x < define::IN_W) {
		moveX += 5;
	}
	if (keyboardGet(KEY_INPUT_LEFT) > 0 && _x > define::IN_X) {
		moveX -= 5;
	}
	_x += moveX;
	_y += moveY;
}

bool player::isShoot() {
	if (keyboardGet(KEY_INPUT_Z) > 0 && _counter % 4 == 0) {
		return true;
	}
	return false;
}

void player::getPosition(float& x, float& y) {
	x = _x;
	y = _y;
}