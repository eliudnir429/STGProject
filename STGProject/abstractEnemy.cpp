#include "abstractEnemy.h"

abstractEnemy::abstractEnemy() {
	_x = 0;
	_y = 0;
	_angle = 0;
	_speed = 0;
	_hitRad = 0;
	_width = 0;
	_height = 0;
	_health = 0;

	_img = 0;
	_counter = 0;
	shot = false;

}

bool abstractEnemy::update() {
	if (!isInside()) return false;

	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
	_counter++;
	return true;
}

void abstractEnemy::draw() const {
	DrawRotaGraphF(_x, _y, 1.0, 0.0, _img, TRUE);
}

void abstractEnemy::getSize() {
	GetGraphSize(_img, &_width, &_height);
}
void abstractEnemy::getPosition(float& x, float& y) {
	x = _x;
	y = _y;
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
//shot‚ð•Ô‚·
bool abstractEnemy::isShoot() {
	return shot;
}