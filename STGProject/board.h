#pragma once
#include "baseScene.h"

class board :public baseScene {
public:
	board() = default;
	~board() = default;
	void update();
	void draw();

private:
};