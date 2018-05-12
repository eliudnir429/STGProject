#include "abstractEnemy.h"
#include <math.h>
#include <DxLib.h>

abstractEnemy::abstractEnemy(float x, float y) :
	_x(x),
	_y(y),
	_angle(0.0),
	_speed(0.0),
	_counter(0)
{
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