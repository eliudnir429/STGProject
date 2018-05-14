#pragma once
#include "task.h"
#include <memory>
#include <list>
#include "pShotMgr.h"

class player :public task {
public:
	player();
	virtual ~player() = default;
	bool update();
	void draw() const override;
private:
	void move();
	void shoot();
	float _x, _y;
	int _img[16];
	int _counter;
	std::shared_ptr<pShotMgr> _pShotMgr;
};