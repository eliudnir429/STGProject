#pragma once
#include "abstractEnemy.h"

class enemy :public abstractEnemy{
public:
	enemy(float	x, float y);
	virtual ~enemy() = default;
	bool update() override;
};