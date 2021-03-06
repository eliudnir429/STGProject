#pragma once
#include "task.h"

class effect :public task {
public:
	effect(float x, float y, float size);
	virtual ~effect() = default;
	bool update();
	void draw() const;
private:
	float _x, _y;
	float _speed;
	float _angle;
	float _size;
	int _img[11];
	int _counter;
	int _imgNum;
};