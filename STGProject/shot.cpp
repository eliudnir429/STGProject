#include "shot.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

shot::shot(float x, float y, float angle, float speed) :_x(x), _y(y), _angle(angle), _speed(speed) {
	_img = LoadGraph("img/shot00.png");
	_counter = 0;
}

void shot::update() {
	_counter++;
	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
}

void shot::draw() {
	DrawRotaGraphF(_x, _y, 1.0, 0.0, _img, TRUE);
}