#pragma once
#include "abstractShot.h"

class enemyShot :public  abstractShot {
	enemyShot(float x, float y);
	virtual ~enemyShot() = default;
};