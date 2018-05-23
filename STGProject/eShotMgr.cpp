#include "eShotMgr.h"
#include "enemyShot.h"

eShotMgr::eShotMgr(std::shared_ptr<enemyMgr> enemyMgr) {
	_enemyMgr = enemyMgr;
}

bool eShotMgr::update() {
	for (auto it : _list) {
		it->update();
	}
}

void eShotMgr::draw() const {
	for (auto it : _list) {
		it->draw();
	}
}

void eShotMgr::makeShot() {
	float _enemyX, _enemyY;

}

bool eShotMgr::isHit() {

}