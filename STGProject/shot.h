#pragma once
#include "task.h"

class shot :public task {
public:
	shot(float x, float y);
	~shot() = default;
	bool update() override;
	void draw() const override;

private:
	float _x, _y;
	float _angle;
	float _speed;
	int _img;
	int _counter;
};