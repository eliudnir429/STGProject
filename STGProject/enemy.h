#pragma once
#include "baseObject.h"

class enemy :public baseObject{
public:
	enemy();
	~enemy() = default;
	void update();
	void draw();

private:
	static double _x, _y;
	static float angle;
	float speed = 1.5;
	int _img;
	static int count;
};