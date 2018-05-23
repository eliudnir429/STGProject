#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "abstractShot.h"
#include "enemyMgr.h"

class eShotMgr :public task {
public:
	eShotMgr(std::shared_ptr<enemyMgr> enemyMgr);
	virtual ~eShotMgr() = default;
	bool update();
	void draw() const;
	void makeShot();
	bool isHit();

	std::list<std::shared_ptr<abstractShot>> _list;
private:
	std::shared_ptr<enemyMgr> _enemyMgr;
};