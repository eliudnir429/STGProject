#include "effectMgr.h"
#include <DxLib.h>
#include "define.h"

bool effectMgr::update() {
	for (auto it = _list.begin(); it != _list.end();) {
		if ((*it)->update() == false) {	//Á‹Žˆ— Õ“Ë”»’è
			it = _list.erase(it);
		}
		else {
			it++;
		}
	}
	return true;
}

void effectMgr::draw() const {
	DrawFormatString(define::OUT_W + 50, 250, GetColor(255, 255, 255), "effect : %d", _list.size());
	for (auto it : _list) {
		it->draw();
	}
}

void effectMgr::makeEffect(std::shared_ptr<abstractShot> shot) {
	float shotX, shotY;

	shot->getPosition(shotX, shotY);
	_list.emplace_back(std::make_shared<effect>(shotX, shotY, 1.0));
}

void effectMgr::makeDestroyEffect(std::shared_ptr<abstractEnemy> enemy) {
	float enemyX, enemyY;

	enemy->getPosition(enemyX, enemyY);
	_list.emplace_back(std::make_shared<effect>(enemyX, enemyY, 5.0));
}