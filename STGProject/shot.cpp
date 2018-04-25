#include "shot.h"
#include "DxLib.h"
#include "player.h"

shot_t shot::_shot[10] = {
	{ 0,300,0,0 },
	{ 0,300,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
};

shot::shot() {
	_img = LoadGraph("img/shot00.png");
}

void shot::update() {
	for (int i = 0; i < 10; i++) {
		if (player::getPlayerShotflag() == true) {
			_shot[i].y -= 10;
		}
	}
}

void shot::draw() {
	DrawFormatString(0, 20, GetColor(255, 255, 255), "shot::draw()");
	for (int i = 0; i < 10; i++) {
		DrawGraph(_shot[i].x, _shot[i].y, _img, TRUE);
	}
}