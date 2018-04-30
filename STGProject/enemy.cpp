#include "enemy.h"
#include "DxLib.h"
#include <math.h>
#include "define.h"
#include "gameMgr.h"

double enemy::_x = 100.0;
double enemy::_y = 100.0;
float enemy::angle = 0.0f;
int enemy::count = 0;

enemy::enemy() {
	_img = LoadGraph("img/enemy00.png");
}

void enemy::update() {
	_x += cos(angle)*speed;
//	_y += sin(angle)*speed;

	if (gameMgr::getCurrentFrame() % 12 == 0) {

		if ((count % 24) < 12) {
			angle = (PI * 2) / (count % 12 + 1);
		}
		if ((count % 24) >= 12) {
			angle = (PI * 2) / (12 - count % 12);
		}
		count++;
	}
}

void enemy::draw() {
	DrawGraph(_x, _y, _img, TRUE);
	DrawFormatString(0, 400, GetColor(255, 255, 255), "%lf,%lf", _x, _y);
}