#include "bossEnemy.h"
#include "DxLib.h"
#include "define.h"

bossEnemy::bossEnemy(float x, float y):_x(x) {
//	_x = x;
	_y = y;
	_img = LoadGraph("img/enemy01.png");
}

void bossEnemy::update() {
	_x += 1.0;
}

void bossEnemy::draw() {
	DrawGraph(_x, _y, _img, TRUE);
}