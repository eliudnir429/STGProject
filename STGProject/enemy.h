#pragma once
#include "abstractEnemy.h"

class enemy :public abstractEnemy{
public:
	enemy(float x, float y, std::shared_ptr<eShotMgr> eShotMgr);
	virtual ~enemy() = default;
};