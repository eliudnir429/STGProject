#include "enemy.h"
#include <DxLib.h>
#include "define.h"

enemy::enemy(float x, float y) : abstractEnemy(x, y) {
	_img = LoadGraph("img/enemy00.png");
	_angle = define::PI / 2.f;
	_speed = 1.5;
}