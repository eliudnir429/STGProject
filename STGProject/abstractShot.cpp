#include "abstractShot.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

abstractShot::abstractShot() {
	_x = 0;
	_y = 0;
	_angle = 0;
	_speed = 0;
	_hitRad = 0;
	_width = 0;
	_height = 0;
	_img = 0;
	_counter = 0;
}

bool abstractShot::update() {
	if (!isInside()) return false;

	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
	_counter++;

	return true;
}

void abstractShot::draw() const {
	DrawRotaGraphF(_x, _y, 1.0, 0.0, _img, TRUE);
}

bool abstractShot::isInside() {
	if (_counter < 30) {
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