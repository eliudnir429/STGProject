#pragma once
#include "task.h"

class abstractEnemy : public task {
public:
	abstractEnemy(float x, float y);
	virtual ~abstractEnemy() = default;
	bool update() override;
	void draw() const override;
	void getSize();
protected:
	float _x, _y;
	float _angle;
	float _speed;
	int _width;
	int _height;
	int _img;
	int _counter;
	bool isInside();
};