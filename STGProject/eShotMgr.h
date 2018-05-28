#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "abstractShot.h"

class eShotMgr :public task {
public:
	eShotMgr();
	virtual ~eShotMgr() = default;
	bool update();
	void draw() const;
	void makeShot(float x, float y, float speed, float angle);
	bool isHit();

	std::list<std::shared_ptr<abstractShot>> _list;
private:
};