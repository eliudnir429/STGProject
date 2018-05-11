#pragma once
#include "baseObject.h"

class shot :public baseObject {
public:
	shot(float x, float y, float angle, float speed);
	~shot() = default;
	void update();
	void draw();

private:
	float _x, _y;
	float _angle;
	float _speed;
	int _img;
	int _counter;
};