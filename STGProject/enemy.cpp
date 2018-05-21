#include "enemy.h"
#include <DxLib.h>
#include "define.h"
#include <math.h>

enemy::enemy(float x, float y) : abstractEnemy(x, y) {
	_img = LoadGraph("img/enemy00.png");
	getSize();
	_angle = define::PI / 2.f;
	_speed = 0.f;
	_hitRad = 5.f;
	_health = 20;
}