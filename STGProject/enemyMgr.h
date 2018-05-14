#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "abstractEnemy.h"
#include "effect.h"

class enemyMgr :public task {
public:
	enemyMgr();
	virtual ~enemyMgr() = default;
	bool update() override;
	void draw() const override;
private:
	std::list<std::shared_ptr<abstractEnemy>> _list;
	std::list<std::shared_ptr<effect>> _eList;
};