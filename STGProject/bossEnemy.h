#pragma once
#include "abstractEnemy.h"
#include <memory>
#include <DxLib.h>
#include <math.h>
#include "define.h"


class bossEnemy : public abstractEnemy {
public :
	bossEnemy(float x, float y);
	virtual ~bossEnemy() = default;
	bool update() override;
private:
};