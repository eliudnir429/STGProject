#pragma once
#include "abstractEnemy.h"
#include <memory>
#include "collisionJud.h"

class bossEnemy : public abstractEnemy {
public :
	bossEnemy(float x, float y);
	virtual ~bossEnemy() = default;
	bool update() override;
private:
	float _hitRange;
	std::shared_ptr<collisionJud> _collision;
};