#include "board.h"
#include "define.h"
#include <DxLib.h>

void board::update() {
	
}

void board::draw() {
	int color = GetColor(0, 64, 128);
	const int x = define::IN_X;
	const int y = Define::IN_Y;
	const int w = Define::IN_W;
	const int h = Define::IN_H;

	DrawLine(x, y, x + w, y, color);
	DrawLine(x, y, x, y + h, color);
	DrawLine(x + w, y, x + w, y + h, color);
	DrawLine(x, y + h, x + w, y + h, color);
}
