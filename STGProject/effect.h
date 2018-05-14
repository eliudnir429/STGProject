#pragma once
#include "task.h"

class effect :public task {
public:
	effect(float x, float y);
	virtual ~effect() = default;
	bool update();
	void draw() const;
private:
	float _x, _y;
	float _speed;
	int _img[11];
	int _counter;
	int _imgNum;
};