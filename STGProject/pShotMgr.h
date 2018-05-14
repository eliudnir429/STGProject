#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "shot.h"
#include "player.h"
#include "enemyMgr.h"

class pShotMgr :public task {
public:
	pShotMgr(const std::shared_ptr<player>& player,
			const std::shared_ptr<enemyMgr>& enemyMgr);
	virtual ~pShotMgr() = default;
	bool update();
	void draw() const override;
	bool isHit(std::shared_ptr<shot> shot);
private:
	std::list<std::shared_ptr<shot>> _list;
	std::shared_ptr<player> _player;
	std::shared_ptr<enemyMgr> _enemyMgr;
	float _playerX, _playerY;
	float _shotX, _shotY, _shotRad;
	float _enemyX, _enemyY, _enemyRad;
};