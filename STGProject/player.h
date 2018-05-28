#pragma once
#include "task.h"
#include <memory>
#include "pShotMgr.h"

class player :public task {
public:
	player(std::shared_ptr<pShotMgr> pShotMgr);
	virtual ~player() = default;
	bool update();
	void draw() const override;
	void getPosition(float& x, float& y);
private:
	void move();
	void shoot();
	float _x, _y;
	int _img[16];
	int _counter;
	std::shared_ptr<pShotMgr> _pShotMgr;
};