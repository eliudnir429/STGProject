#pragma once
#include "task.h"
#include <memory>
#include "shot.h"
#include "abstractEnemy.h"

class collisionJud :public task {
public:
	collisionJud(std::shared_ptr<shot> shot, std::shared_ptr<abstractEnemy> enemy);
	virtual ~collisionJud() = default;
	bool update();
	void draw() const;
private:
	float _x, _y;
	float _rad;
	float _shotX, _shotY;
	float _shotRad;
	float _enemyX, _enemyY;
	float _enemyRad;
};