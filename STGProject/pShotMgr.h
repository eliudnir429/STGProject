#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "shot.h"

class pShotMgr :public task {
public:
	pShotMgr() = default;
	virtual ~pShotMgr() = default;
	bool update();
	void draw() const;
	void makeShot(float x, float y);
private:
	std::list<std::shared_ptr<shot>> _list;
};