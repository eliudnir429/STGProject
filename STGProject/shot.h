#pragma once
#include "baseObject.h"

class shot :public baseObject {
public:
	shot();
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