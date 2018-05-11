#include "bossEnemy.h"
#include "DxLib.h"
#include "define.h"

bossEnemy::bossEnemy(float x, float y) :_x(x), _y(y) {
	_img = LoadGraph("img/enemy01.png");
}

void bossEnemy::update() {
	_y += 1.0;
}

void bossEnemy::draw() {
	DrawRotaGraphF(_x, _y, 1.0, 0.0, _img, TRUE);
}