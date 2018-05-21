#include "pShotMgr.h"
#include <DxLib.h>
#include "define.h"

pShotMgr::pShotMgr(const std::shared_ptr<player>& player, 
				const std::shared_ptr<enemyMgr>& enemyMgr,
				const std::shared_ptr<effectMgr>& effectMgr) {
	_effectMgr = effectMgr;
	_player = player;
	_enemyMgr = enemyMgr;
}

bool pShotMgr::update() {
	if (_player->isShoot()) {
		makeShot();
	}
	for (auto it = _list.begin(); it != _list.end();) {

		if ((*it)->update() == false) {
			it = _list.erase(it);
		}
		else if (isHit(*it)) {
			_effectMgr->makeEffect(*it);
			it = _list.erase(it);
		}
		else {
			it++;
		}
	}
	return true;
}

void pShotMgr::draw() const {
	DrawFormatString(define::OUT_W + 50, 200, GetColor(255, 255, 255), "shot : %d", _list.size());

	for (auto it : _list) {
		it->draw();
	}
}

bool pShotMgr::isHit(std::shared_ptr<playerShot> shot) {
	float _shotX, _shotY, _shotRad;
	float _enemyX, _enemyY, _enemyRad;
	float _hitX, _hitY, _hitRad;

	shot->getCollisionArea(_shotX, _shotY, _shotRad);

	for (auto it : _enemyMgr->_list) {
		it->getCollisionArea(_enemyX, _enemyY, _enemyRad);
		_hitX = _shotX - _enemyX;
		_hitY = _shotY - _enemyY;
		_hitRad = _shotRad + _enemyRad;

		if ((_hitX*_hitX) + (_hitY*_hitY) <= (_hitRad*_hitRad)) {
			return true;
		}
	}
	return false;
}

void pShotMgr::makeShot() {
	float playerX, playerY;

	_player->getPosition(playerX, playerY);
	_list.emplace_back(std::make_shared<playerShot>(playerX + 25, playerY - 10));
	_list.emplace_back(std::make_shared<playerShot>(playerX - 25, playerY - 10));
}