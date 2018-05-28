#pragma once
#include "abstractEnemy.h"
#include <memory>

class bossEnemy : public abstractEnemy {
public :
	bossEnemy(float x, float y, std::shared_ptr<eShotMgr> eShotMgr);
	virtual ~bossEnemy() = default;
	bool update() override;
};