#pragma once
#include "task.h"
#include <list>
#include <memory>
#include <DxLib.h>
#include "define.h"
#include "abstractEnemy.h"
#include "bossEnemy.h"
#include "enemy.h"
#include "effectMgr.h"

class enemyMgr :public task {
public:
	enemyMgr();
	virtual ~enemyMgr() = default;
	bool update() override;
	void draw() const override;
	void addEnemy(float x, float y);
	std::list<std::shared_ptr<abstractEnemy>> _list;
private:
};