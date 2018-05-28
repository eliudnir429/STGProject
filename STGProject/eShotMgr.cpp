#include "eShotMgr.h"
#include "enemyShot.h"

eShotMgr::eShotMgr() {
}

bool eShotMgr::update() {
	for (auto it : _list) {
		it->update();
	}
	return true;
}

void eShotMgr::draw() const {
	for (auto it : _list) {
		it->draw();
	}
}

void eShotMgr::makeShot(float x, float y, float speed, float angle) {
	_list.emplace_back(std::make_shared<enemyShot>(x, y, speed, angle));
}

bool eShotMgr::isHit() {
	return true;
}