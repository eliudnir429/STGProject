#pragma once
#include "abstractEnemy.h"

class bossEnemy : public abstractEnemy {
public :
	bossEnemy(float x, float y);
	virtual ~bossEnemy() = default;
	bool update() override;
};