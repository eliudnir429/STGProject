#include "playerShot.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

playerShot::playerShot(float x, float y) :abstractShot(x, y) {
	_img = LoadGraph("img/shot00.png");
	GetGraphSize(_img, &_width, &_height);

	_speed = 16.f;
	_angle = define::PI / 2.f*3.f;
	_hitRad = 30.f;
	_counter = 0;
}
