#include "bossEnemy.h"
#include "DxLib.h"
#include "define.h"
#include <math.h>

bossEnemy::bossEnemy(float x, float y) : abstractEnemy(x, y){
	_img = LoadGraph("img/enemy01.png");
	getSize();
	_angle = define::PI / 2.f;
	_speed = 2.f;
	_hitRad = 70.f;
	_health = 50;
}

bool bossEnemy::update() {
	_counter++;
	if (_counter <= 120) {
		
	}
	if (120 < _counter&&_counter <= 240) {
		_speed = 0.0;
	}
	if (240 < _counter) {
		_angle = define::PI / 2.f*3.f;
		_speed = 2.f;
	}
	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;

	return isInside();
}