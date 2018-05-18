#include "abstractShot.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

abstractShot::abstractShot(float x, float y) :
	_x(x),
	_y(y),
	_angle(0.f),
	_speed(0.f),
	_hitRad(50.f){
}

bool abstractShot::update() {
	_counter++;

	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
	return isInside();
}

void abstractShot::draw() const {
	DrawRotaGraphF(_x, _y, 0.5, 0.0, _img, TRUE);
}

bool abstractShot::isInside() {
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

void abstractShot::getCollisionArea(float& x, float& y, float& rad) {
	x = _x;
	y = _y;
	rad = _hitRad;
}