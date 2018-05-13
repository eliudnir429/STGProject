#include "shot.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

shot::shot(float x, float y) :_x(x), _y(y), _angle(define::PI / 2.f*3.f), _speed(12.f) {
	_img = LoadGraph("img/shot00.png");
	_counter = 0;
}

bool shot::update() {
	_counter++;

	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
	return true;
}

void shot::draw() const {
	DrawRotaGraphF(_x, _y, 0.5, 0.0, _img, TRUE);
}