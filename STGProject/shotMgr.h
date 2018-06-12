#pragma once
#include "task.h"
#include <DxLib.h>
#include <list>
#include <memory>
#include "define.h"
#include "player.h"
#include "enemyMgr.h"
#include "abstractShot.h"
#include "playerShot.h"
#include "enemyShot.h"

enum shotState {
	PLAYER,
	ENEMY,
};

class shotMgr :public task {
public:
	shotMgr() = default;
	virtual ~shotMgr() = default;
	bool update() override;
	void draw() const override;
	void initialize(std::shared_ptr<player> player, std::shared_ptr<enemyMgr> enemyMgr);
	void addShot(shotState state, float x, float y);
private:
	std::list<std::shared_ptr<abstractShot>> _playerShotList;
	std::list<std::shared_ptr<abstractShot>> _enemyShotList;
	std::shared_ptr<player> _player;
	std::shared_ptr<enemyMgr> _enemyMgr;
};