#pragma once
#include "task.h"

class abstractEnemy : public task {
public:
	abstractEnemy(float x, float y);
	virtual ~abstractEnemy() = default;
	bool update() override;
	void draw() const override;
	void getSize();
	void getCollisionArea(float& x, float& y, float& rad);
protected:
	float _x, _y;
	float _angle;
	float _speed;
	float _hitRad;
	int _width, _height;
	int _img;
	int _counter;
	bool isInside();
};