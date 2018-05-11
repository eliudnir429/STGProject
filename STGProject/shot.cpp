#include "shot.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

shot::shot() :_x((float)define::OUT_W / 2.0), _y((float)define::OUT_H / 2.0), _angle(0.0), _speed(5.0) {
	_img = LoadGraph("img/shot00.png");
	_counter = 0;
}

void shot::update() {
	_counter++;
	_x += (float)cos(_angle)*_speed;
	_y += (float)sin(_angle)*_speed;
	_angle = define::PI * 2 / 60 * (_counter % 60);
}

void shot::draw() {
	DrawRotaGraphF(_x, _y, 1.0, 0.0, _img, TRUE);
}