#pragma once
#include "baseObject.h"

class bossEnemy :public baseObject {
public :
	bossEnemy(float x, float y);
	~bossEnemy() = default;
	void update();
	void draw();

protected:
	float _x, _y;
	float _angle;
	float _speed;
	int _img;
	int _counter;
};