#pragma once
#include "baseObject.h"

class player :public baseObject {
public:
	player();
	~player() = default;
	void update();
	void draw();
	static bool getPlayerShotflag();

private:
	static int x, y;
	int width, height;
	int img;
	static bool playerShotFlag;

};