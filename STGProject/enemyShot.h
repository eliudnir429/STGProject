#pragma once
#include "abstractShot.h"

class enemyShot :public  abstractShot {
public:
	enemyShot(float x, float y, float speed, float angle);
	virtual ~enemyShot() = default;
};