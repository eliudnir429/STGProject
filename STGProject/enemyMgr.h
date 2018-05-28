#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "abstractEnemy.h"
#include "effectMgr.h"
#include "eShotMgr.h"

class enemyMgr :public task {
public:
	enemyMgr(std::shared_ptr<effectMgr> effectMgr, std::shared_ptr<eShotMgr> eShotMgr);
	virtual ~enemyMgr() = default;
	bool update() override;
	void draw() const override;
	std::list<std::shared_ptr<abstractEnemy>> _list;
private:
	std::shared_ptr<effectMgr> _effectMgr;
	std::shared_ptr<eShotMgr> _eShotMgr;
};