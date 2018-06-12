#include "enemy.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

enemy::enemy(float x, float y) {
	_img = LoadGraph("img/enemy00.png");
	getSize();

	_x = x;
	_y = y;
	_angle = define::PI / 2.f;
	_speed = 0.f;
	_hitRad = 20.f;
	_health = 20;
}