#pragma once
#include "task.h"
#include <memory>
#include <math.h>
#include <DxLib.h>
#include "define.h"

class abstractEnemy : public task {
public:
	abstractEnemy();
	virtual ~abstractEnemy() = default;
	bool update() override;
	void draw() const override;

	void getSize();
	void getPosition(float& x, float& y);

	bool isShoot();
protected:
	float _x, _y;
	float _angle;
	float _speed;
	float _hitRad;
	int _width, _height;
	int _health;

	int _img;
	int _counter;
	bool shot;

	bool isInside();
};