#pragma once
#include "task.h"
#include <memory>
#include "player.h"
#include "enemyMgr.h"
#include "pShotMgr.h"
#include "effectMgr.h"

class collisionDetect {
public:
	collisionDetect(const std::shared_ptr<player>& player, const std::shared_ptr<enemyMgr>& enemyMgr, const std::shared_ptr<pShotMgr>& pShotMgr, const std::shared_ptr<effectMgr>& effectMgr);
	~collisionDetect() = default;
	bool update();
	static bool isHitPlayerShot(std::shared_ptr<abstractShot> shot,std::shared_ptr<abstractEnemy> object);
private:
	std::shared_ptr<player> _player;
	std::shared_ptr<enemyMgr> _enemyMgr;
	std::shared_ptr<pShotMgr> _pShotMgr;
	std::shared_ptr<effectMgr> _effectMgr;

	float _shotX, _shotY, _shotRad;
	float _objectX, _objectY, _objectRad;
	float _x, _y, _rad;
};