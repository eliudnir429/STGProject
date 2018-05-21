#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "abstractEnemy.h"
#include "effectMgr.h"

class enemyMgr :public task {
public:
	enemyMgr(std::shared_ptr<effectMgr> effectMgr);
	virtual ~enemyMgr() = default;
	bool update() override;
	void draw() const override;
	std::list<std::shared_ptr<abstractEnemy>> _list;
private:
	std::shared_ptr<effectMgr> _effectMgr;
};