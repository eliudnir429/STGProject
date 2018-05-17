#include "playerShot.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

playerShot::playerShot(float x, float y) : abstractShot(x, y) {
	_img = LoadGraph("img/shot00.png");
	GetGraphSize(_img, &_width, &_height);
	_x = x;
	_y = y;
	_angle = define::PI / 2.f*3.f;
	_speed = 16.f;
	_counter = 0;
	_hitRad = 50.f;
}

bool playerShot::update() {
	_counter++;
	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
	return isInside();
}

void playerShot::draw() const {
	DrawRotaGraphF(_x, _y, 0.5, 0.0, _img, TRUE);
}

bool playerShot::isInside() {
	if (_counter < 60) {
		return true;
	}
	if (_x < -_width / 2 ||
		define::OUT_W + _width / 2 < _x ||
		_y < -_height / 2 ||
		define::OUT_H + _height / 2 < _y) {
		return false;
	}
	return true;
}