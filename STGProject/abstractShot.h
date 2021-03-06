#pragma once
#include "task.h"

class abstractShot :public task {
public:
	abstractShot(float x, float y);
	virtual ~abstractShot() = default;
	bool update() override;
	void draw() const override;
	bool isInside();
	void getCollisionArea(float& x, float& y, float& rad);
	void getPosition(float& x, float& y);
protected:
	float _x, _y;
	float _angle;
	float _speed;
	float _hitRad;
	int _width, _height;
	int _img;
	int _counter;
};