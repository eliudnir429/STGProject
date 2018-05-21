#pragma once
#include "abstractShot.h"

class playerShot :public abstractShot {
public:
	playerShot(float x, float y);
	~playerShot() = default;
};