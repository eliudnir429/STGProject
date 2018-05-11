#pragma once
#include "baseObject.h"

class enemy :public baseObject{
public:
	enemy();
	~enemy() = default;
	void update();
	void draw();

private:
	float _x, _y;
	float _angle;
	float _speed;
	int _img;
	int _counter;
};