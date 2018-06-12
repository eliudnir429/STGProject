#pragma once
#include "task.h"

class abstractShot :public task {
public:
	abstractShot();
	virtual ~abstractShot() = default;
	bool update() override;
	void draw() const override;
	bool isInside();
protected:
	float _x, _y;
	float _angle;
	float _speed;
	float _hitRad;
	int _width, _height;
	int _img;
	int _counter;
};