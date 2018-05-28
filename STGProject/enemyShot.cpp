#include "enemyShot.h"
#include <DxLib.h>
#include "define.h"

enemyShot::enemyShot(float x, float y, float speed, float angle) :abstractShot(x, y) {
	_img = LoadGraph("img/shot01.png");
	GetGraphSize(_img, &_width, &_height);

	_speed = speed;
	_angle = angle;
	_hitRad = 30.f;
	_counter = 0;
}