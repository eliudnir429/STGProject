#include "board.h"
#include "define.h"
#include <DxLib.h>

board::board() {
	_img = LoadGraph("img/board.png");
}

bool board::update() {
	return true;
}

void board::draw() const {
	DrawGraph(define::OUT_W, 0, _img, TRUE);
	drawFrame();
}

void board::drawFrame() const {
	int color = GetColor(255, 255, 255);
	const int x = define::IN_X;
	const int y = define::IN_Y;
	const int w = define::IN_W;
	const int h = define::IN_H;

	DrawLine(x, y, x + w, y, color);
	DrawLine(x, y, x, y + h, color);
	DrawLine(x + w, y, x + w, y + h, color);
	DrawLine(x, y + h, x + w, y + h, color);
}
