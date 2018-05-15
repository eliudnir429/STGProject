#include "pShotMgr.h"
#include <DxLib.h>
#include "define.h"

pShotMgr::pShotMgr(const std::shared_ptr<player>& player,
				const std::shared_ptr<enemyMgr>& enemyMgr) {
	_effectMgr = std::make_shared<effectMgr>();
	_player = player;
	_enemyMgr = enemyMgr;
}

bool pShotMgr::update() {
	if (_player->isShoot()) {
		_player->getPosition(_playerX, _playerY);
		_list.emplace_back(std::make_shared<shot>(_playerX + 25, _playerY - 10));
		_list.emplace_back(std::make_shared<shot>(_playerX - 25, _playerY - 10));
	}

	for (auto it = _list.begin(); it != _list.end();) {	
		if ((*it)->update() == false ) {	//消去処理 衝突判定
			it = _list.erase(it);
		}
		else if (isHit() == true) {			//ヒットエフェクト
			_effectMgr->addList(_shotX, _shotY);
			it = _list.erase(it);
		}
		else {
			it++;
		}
	}
	_effectMgr->update();
	return true;
}

void pShotMgr::draw() const {
	DrawFormatString(define::OUT_W + 50, 200, GetColor(255, 255, 255), "shot : %d", _list.size());
	for (auto it : _list) {
		it->draw();
	}
	_effectMgr->draw();
}

bool pShotMgr::isHit() {
	for (auto it : _list) {
		it->getCollisionArea(_shotX, _shotY, _shotRad);
		for (auto it2 : _enemyMgr->_list) {
			it2->getCollisionArea(_enemyX, _enemyY, _enemyRad);
			_hitX = _shotX - _enemyX;
			_hitY = _shotY - _enemyY;
			_hitRad = _shotRad + _enemyRad;
			if ((_hitX*_hitX) + (_hitY*_hitY) < (_shotRad*_shotRad)) {
				return true;
			}
		}
	}
	return false;
}