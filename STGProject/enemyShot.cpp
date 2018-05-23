#include "enemyShot.h"
#include <DxLib.h>
#include "define.h"

enemyShot::enemyShot(float x, float y) :abstractShot(x, y) {
	_img = LoadGraph("img/shot01.png");
	GetGraphSize(_img, &_width, &_height);

	_speed = 10.f;
	_angle = define::PI / 2.f*1.f;
	_hitRad = 30.f;
	_counter = 0;
}