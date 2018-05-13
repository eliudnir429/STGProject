#pragma once
#include "task.h"
#include <memory>
#include "shot.h"
#include <list>

class player :public task {
public:
	player();
	virtual ~player() = default;
	bool update() override;
	void draw() const override;

private:
	void move();
	void shoot();
	float _x, _y;
	int _img[16];
	int _counter;
	std::shared_ptr<shot> _shot;
	std::list<std::shared_ptr<shot>> _list;
};