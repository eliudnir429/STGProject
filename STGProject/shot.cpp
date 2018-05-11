#include "shot.h"
#include "DxLib.h"
#include "player.h"

shot::shot() {
	_img = LoadGraph("img/shot00.png");
}

void shot::update() {

}

void shot::draw() {
	DrawFormatString(0, 20, GetColor(255, 255, 255), "shot::draw()");
}