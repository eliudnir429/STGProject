#include "enemy.h"
#include "DxLib.h"
#include <math.h>
#include "define.h"
#include "gameMgr.h"

enemy::enemy() : _x(200), _y(200), _angle(0.0), _speed(1.5) {
	_img = LoadGraph("img/enemy00.png");
}

void enemy::update() {
	_counter++;
	_angle = PI * 2 / 120 * (_counter % 120);
	_x += cos(_angle)*_speed;
	_y += sin(_angle)*_speed;
}

void enemy::draw() {
	DrawGraph(_x, _y, _img, TRUE);
}