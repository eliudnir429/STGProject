#include "bossEnemy.h"

bossEnemy::bossEnemy(float x, float y) {
	_img = LoadGraph("img/enemy01.png");
	getSize();

	_x = x;
	_y = y;
	_angle = define::PI / 2.f;
	_speed = 2.f;
	_hitRad = 70.f;
	_health = 50;
}

bool bossEnemy::update() {
	if (!isInside()) return false;

	if (_counter <= 120) {
		
	}
	if (120 < _counter&&_counter <= 240) {
		_speed = 0.0;
		if (_counter % 5 == 0) {
			shot = true;
		}
		else {
			shot = false;
		}
	}
	if (240 < _counter) {
		shot = false;
		_angle = define::PI / 2.f*3.f;
		_speed = 2.f;
	}
	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
	_counter++;

	return true;
}