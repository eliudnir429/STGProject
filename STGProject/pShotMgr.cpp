#include "pShotMgr.h"
#include <DxLib.h>
#include "define.h"

pShotMgr::pShotMgr(const std::shared_ptr<player>& player,
				const std::shared_ptr<enemyMgr>& enemyMgr) {
	_player = player;
	_enemyMgr = enemyMgr;
}

bool pShotMgr::update() {
	makeShot();
	
	for (auto it = _list.begin(); it != _list.end();) {
		
		if (_collisionDetect->isHitPlayerShot(*it) || (*it)->update()) {
			it = _list.erase(it);
		}
		else {
			it++;
		}
	}

	/*
	for (auto it = _list.begin(); it != _list.end();) {	
		if ((*it)->update() == false ) {	//消去処理 衝突判定
			it = _list.erase(it);
		}
		else if (collisionDetect::isHitPlayerShot(it,)) {			//ヒットエフェクト
			_effectMgr->addList(_shotX, _shotY);
			it = _list.erase(it);
		}
		else {
			it++;
		}
	}
	_effectMgr->update();*/
	return true;
}

void pShotMgr::draw() const {
	DrawFormatString(define::OUT_W + 50, 200, GetColor(255, 255, 255), "shot : %d", _list.size());
	for (auto it : _list) {
		it->draw();
	}
}

void pShotMgr::makeShot() {
	if (_player->isShoot()) {
		_player->getPosition(_playerX, _playerY);
		_list.emplace_back(std::make_shared<playerShot>(_playerX + 25, _playerY - 10));
		_list.emplace_back(std::make_shared<playerShot>(_playerX - 25, _playerY - 10));
	}
}