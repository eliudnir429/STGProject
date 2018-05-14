#include "pShotMgr.h"
#include <DxLib.h>
#include "define.h"

pShotMgr::pShotMgr(const std::shared_ptr<player>& player,
				const std::shared_ptr<enemyMgr>& enemyMgr) {
	_player = player;
	_enemyMgr = enemyMgr;
}

bool pShotMgr::update() {
	if (_player->isShoot()) {
		_player->getPosition(_playerX, _playerY);
		_list.emplace_back(std::make_shared<shot>(_playerX, _playerY));
	}

	for (auto it = _list.begin(); it != _list.end();) {	
		if ((*it)->update() == false || isHit(*it) == true) {	//Á‹Žˆ— Õ“Ë”»’è
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

bool pShotMgr::isHit(std::shared_ptr<shot> shot) {
	return false;
}