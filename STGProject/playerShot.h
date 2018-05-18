#pragma once
#include "abstractShot.h"

class playerShot :public abstractShot {
public:
	playerShot(float x, float y);
	~playerShot() = default;
	bool update() override;
	void draw() const override;
	bool isInside();
private:
	float _x, _y;
	float _angle;
	float _speed;
	float _hitRad;
	int _img;
	int _counter;
	int _width, _height;
};