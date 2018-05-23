#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "playerShot.h"
#include "player.h"
#include "enemyMgr.h"
#include "effectMgr.h"

class pShotMgr :public task {
public:
	pShotMgr(const std::shared_ptr<player>& player,
			const std::shared_ptr<enemyMgr>& enemyMgr,
			const std::shared_ptr<effectMgr>& effectMgr);
	virtual ~pShotMgr() = default;
	bool update();
	void draw() const override;
	bool isHit(std::shared_ptr<playerShot> shot);
	void makeShot();
private:
	std::list<std::shared_ptr<playerShot>> _list;
	std::shared_ptr<player> _player;
	std::shared_ptr<enemyMgr> _enemyMgr;
	std::shared_ptr<effectMgr> _effectMgr;
	float _shotX, _shotY, _shotRad;

};