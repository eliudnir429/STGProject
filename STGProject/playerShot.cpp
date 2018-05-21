#include "playerShot.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

playerShot::playerShot(float x, float y) :abstractShot(x, y) {
	_speed = 16.f;
	_angle = define::PI / 2.f*3.f;
	_hitRad = 50.f;
	_counter = 0;
	_img = LoadGraph("img/shot00.png");
	GetGraphSize(_img, &_width, &_height);
}
