#pragma once
#include "task.h"

class shot :public task {
public:
	shot(float x, float y);
	~shot() = default;
	bool update() override;
	void draw() const override;
	bool isInside();
	void getCollisionArea(float& x, float& y, float& rad);

private:
	float _x, _y;
	float _angle;
	float _speed;
	float _hitRad;
	int _img;
	int _counter;
	int _width, _height;
};