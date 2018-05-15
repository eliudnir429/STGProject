#include "effect.h"
#include <DxLib.h>

effect::effect(float x, float y) :_x(x), _y(y), _speed(20.f) {
	LoadDivGraph("img/effect00.png", 11, 5, 3, 80, 80, _img, TRUE);
	_counter = 0;
	_imgNum = 0;
}

bool effect::update() {
	_counter++;
	if (_counter % 3 == 0) {
		_imgNum++;
	}

	if (_imgNum >= 11) {
		return false;
	}
	return true;
}

void effect::draw() const {
	DrawRotaGraphF(_x, _y, 1.0, 0.0, _img[_imgNum], TRUE);
}