#include "playerShot.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

playerShot::playerShot(float x, float y) {
	_img = LoadGraph("img/shot00.png");
	GetGraphSize(_img, &_width, &_height);

	_x = x;
	_y = y;
	_speed = 16.f;
	_angle = define::PI / 2.f*3.f;
	_hitRad = 30.f;
	_counter = 0;
}
