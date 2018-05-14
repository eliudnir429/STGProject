#include "pShotMgr.h"
#include <DxLib.h>
#include "define.h"

bool pShotMgr::update() {
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

void pShotMgr::draw() const {
	DrawFormatString(define::OUT_W + 50, 200, GetColor(255, 255, 255), "shot : %d", _list.size());
	for (auto it : _list) {
		it->draw();
	}
}

void pShotMgr::makeShot(float x, float y) {
	_list.emplace_back(std::make_shared<shot>(x, y));
}