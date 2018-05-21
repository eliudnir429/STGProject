#pragma once
#include "task.h"
#include <memory>
#include "enemyMgr.h"

class abstractShot :public task {
public:
	abstractShot(float x, float y);
	~abstractShot() = default;
	bool update() override;
	void draw() const override;
	bool isInside();
	bool isHit();
	void getCollisionArea(float& x, float& y, float& rad);
protected:
	float _x, _y;
	float _angle;
	float _speed;
	float _hitRad;
	int _img;
	int _counter;
	int _width, _height;
	std::shared_ptr<enemyMgr> _enemyMgr;
};