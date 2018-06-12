#include "shotMgr.h"

void shotMgr::initialize(std::shared_ptr<player> player, std::shared_ptr<enemyMgr> enemyMgr) {
	_player = player;
	_enemyMgr = enemyMgr;
}

bool shotMgr::update() {
	float _x, _y;
	//追加処理
	if (_player->isShoot()) { //自機弾追加
		_player->getPosition(_x, _y);
		addShot(PLAYER, _x, _y);
	}
	for (auto it : _enemyMgr->_list) { //敵弾追加
		if (it->isShoot()) {
			it->getPosition(_x, _y);
			addShot(ENEMY, _x, _y);
		}
	}
	//画面外処理
	for (auto it = _playerShotList.begin(); it != _playerShotList.end();) { //自機弾画面外処理
		if (!(*it)->update()) {
			it = _playerShotList.erase(it);
		}
		else {
			it++;
		}
	}
	for (auto it = _enemyShotList.begin(); it != _enemyShotList.end();) { //敵弾画面外処理
		if (!(*it)->update()) {
			it = _enemyShotList.erase(it);
		}
		else {
			it++;
		}
	}
	return true;
}

void shotMgr::draw() const {
	DrawFormatString(define::OUT_W + 50, 200, GetColor(255, 255, 255), "player shot : %d", _playerShotList.size());
	DrawFormatString(define::OUT_W + 50, 250, GetColor(255, 255, 255), "enemy shot : %d", _enemyShotList.size());
	for (auto it : _playerShotList) {
		it->draw();
	}
	for (auto it : _enemyShotList) {
		it->draw();
	}
}

void shotMgr::addShot(shotState state, float x, float y) {
	if (state == PLAYER) {
		_playerShotList.emplace_back(std::make_shared<playerShot>(x + 25.f, y - 10.f));
		_playerShotList.emplace_back(std::make_shared<playerShot>(x - 25.f, y - 10.f));
	}
	else if (state == ENEMY) {
		_enemyShotList.emplace_back(std::make_shared<enemyShot>(x, y, 15.f, define::PI * 2 / 4));
	}
}