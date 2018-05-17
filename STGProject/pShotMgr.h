#pragma once
#include "task.h"
#include <memory>
#include <list>
#include "player.h"
#include "enemyMgr.h"
#include "playerShot.h"
#include "collisionDetect.h"

class pShotMgr :public task {
public:
	pShotMgr(const std::shared_ptr<player>& player,
			const std::shared_ptr<enemyMgr>& enemyMgr);
	virtual ~pShotMgr() = default;
	bool update();
	void draw() const override;
	bool isHit();
	void makeShot();
private:
	std::list<std::shared_ptr<playerShot>> _list;
	std::shared_ptr<player> _player;
	std::shared_ptr<enemyMgr> _enemyMgr;
//	std::shared_ptr<collisionDetect> _collisionDetect;
	float _playerX, _playerY;
};