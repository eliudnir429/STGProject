#include "enemy.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

enemy::enemy(float x, float y) : abstractEnemy(x, y) {
	_img = LoadGraph("img/enemy00.png");
	getSize();
	_angle = define::PI / 2.f;
	_speed = 1.5;
	_hitRad = 5.f;
}

bool enemy::update() {
	_counter++;
	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
	return isInside();
}