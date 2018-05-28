#pragma once
#include "task.h"
#include <memory>
#include "eShotMgr.h"

class abstractEnemy : public task {
public:
	abstractEnemy(float x, float y, std::shared_ptr<eShotMgr> eShotMgr);
	virtual ~abstractEnemy() = default;
	bool update() override;
	void draw() const override;
	void getSize();
	void getCollisionArea(float& x, float& y, float& rad);
	void damage();
	bool isAlive();
	void getPosition(float& x, float& y);
	virtual void shoot(float x, float y, float speed, float angle);
protected:
	float _x, _y;
	float _angle;
	float _speed;
	float _hitRad;
	int _width, _height;
	int _img;
	int _counter;
	int _health;
	std::shared_ptr<eShotMgr> _eShotMgr;
	bool isInside();
};