#pragma once
#include "Task.h"

class player :public task {
public:
	player();
	virtual ~player() = default;
	bool update() override;
	void draw() const override;

private:
	void move();

	float _x, _y;
	int _img;
};