#include "eShotMgr.h"
#include <DxLib.h>
#include "enemyShot.h"
#include "define.h"

bool eShotMgr::update() {
	for (auto it = _list.begin(); it != _list.end();) {

		if ((*it)->update() == false) {
			it = _list.erase(it);
		}
		else {
			it++;
		}
	}
	return true;
}

void eShotMgr::draw() const {
	DrawFormatString(define::OUT_W + 50, 300, GetColor(255, 255, 255), "enemy shot : %d", _list.size());

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