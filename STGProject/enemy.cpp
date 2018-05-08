#include "enemy.h"
#include "DxLib.h"
#include <math.h>
#include "define.h"
#include "gameMgr.h"

double enemy::_x = 100.0;
double enemy::_y = 100.0;
float enemy::angle = 0.0f;
int enemy::counter = 0;

enemy::enemy() {
	_img = LoadGraph("img/enemy00.png");
}

void enemy::update() {
	counter++;

	angle = PI * 2 / 120 * counter;

	_x += cos(angle)*speed;
	_y += sin(angle)*speed;
}

void enemy::draw() {
	DrawGraph(_x, _y, _img, TRUE);
	DrawFormatString(0, 400, GetColor(255, 255, 255), "%lf,%lf", _x, _y);
}