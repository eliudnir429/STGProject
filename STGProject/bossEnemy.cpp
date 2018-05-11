#include "bossEnemy.h"
#include "DxLib.h"
#include "define.h"

bossEnemy::bossEnemy(float x, float y) : abstractEnemy(x, y) {
	_img = LoadGraph("img/enemy01.png");
	_angle = define::PI / 2.f;
	_speed = 2.f;
}