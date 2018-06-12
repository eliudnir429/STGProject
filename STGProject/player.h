#pragma once
#include "task.h"
#include <memory>

class player :public task {
public:
	player();
	virtual ~player() = default;
	bool update();
	void draw() const override;
	bool isShoot();
	void getPosition(float& x, float& y);
private:
	void move();
	float _x, _y;
	int _img[16];
	int _counter;
};