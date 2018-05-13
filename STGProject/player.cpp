#include "player.h"
#include "DxLib.h"
#include "keyboard.h"
#include "define.h"

player::player() :_x((float)(define::IN_W / 2.0)), _y((float)define::IN_H) {
	LoadDivGraph("img/player00.png", 16, 4, 4, 64, 64, _img, TRUE);
	_counter = 0;
}

bool player::update() {
	_counter++;
	keyboardUpdate();
	move();
	shoot();
	for (auto it : _list) {
		it->update();
	}
	return true;
}

void player::draw() const {
	DrawFormatString(define::OUT_W + 50, 200, GetColor(255, 255, 255), "shot : %d", _list.size());
	if (keyboardGet(KEY_INPUT_RIGHT) > 0) {
		DrawRotaGraphF(_x, _y, 1.0, 0.0, _img[10], TRUE);
	}
	else if (keyboardGet(KEY_INPUT_LEFT) > 0) {
		DrawRotaGraphF(_x, _y, 1.0, 0.0, _img[9], TRUE);
	}
	else {
		DrawRotaGraphF(_x, _y, 1.0, 0.0, _img[8], TRUE);
	}
	for (auto it : _list) {
		it->draw();
	}

}

void player::move() {
	float moveX = 0, moveY = 0;

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

void player::shoot() {
	if (keyboardGet(KEY_INPUT_Z) > 0 && _counter % 6 == 0) {
		_list.emplace_back(std::make_shared<shot>(_x, _y));
	}
}