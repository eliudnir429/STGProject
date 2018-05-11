#include "player.h"
#include "DxLib.h"
#include "keyboard.h"
#include "define.h"

player::player() :_x(WINDOW_W / 2), _y(WINDOW_H) {
	_img = LoadGraph("img/shot00.png");
}

bool player::update() {
	move();
	return true;
}

void player::draw() const {
	DrawRotaGraphF(_x, _y, 1.0, 1.0, _img, TRUE);
}

void player::move() {
	float moveX = 0, moveY = 0;

	keyboardUpdate();
	if (keyboardGet(KEY_INPUT_UP) > 0) {
		moveY -= 5;
	}
	if (keyboardGet(KEY_INPUT_DOWN) > 0) {
		moveY += 5;
	}
	if (keyboardGet(KEY_INPUT_RIGHT) > 0) {
		moveX += 5;
	}
	if (keyboardGet(KEY_INPUT_LEFT) > 0) {
		moveX -= 5;
	}
	_x += moveX;
	_y += moveY;
}