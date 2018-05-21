#include "abstractEnemy.h"
#include <math.h>
#include <DxLib.h>
#include "define.h"

abstractEnemy::abstractEnemy(float x, float y) {
	_x = x;
	_y = y;
	_counter = 0;
}

bool abstractEnemy::update() {
	_counter++;
	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
	return true;
}

void abstractEnemy::draw() const {
	DrawRotaGraphF(_x, _y, 1.0, 0.0, _img, TRUE);
}

void abstractEnemy::getSize() {
	GetGraphSize(_img, &_width, &_height);
}

bool abstractEnemy::isInside() {
	if (_counter < 60) {
		return true;
	}
	if (_x < -_width / 2 || define::OUT_W + _width / 2 < _x || _y < -_height / 2 || define::OUT_H + _height / 2 < _y) {
		return false;
	}
	return true;
}

void abstractEnemy::getCollisionArea(float& x, float& y, float& rad) {
	x = _x;
	y = _y;
	rad = _hitRad;
}