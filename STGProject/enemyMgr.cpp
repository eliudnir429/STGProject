#include "enemyMgr.h"
#include <DxLib.h>
#include "define.h"
#include "bossEnemy.h"
#include "enemy.h"

enemyMgr::enemyMgr(std::shared_ptr<effectMgr> effectMgr) {
	_effectMgr = effectMgr;
	_list.emplace_back(std::make_shared<enemy>		(define::IN_W / 4.f, 300.f));
	_list.emplace_back(std::make_shared<enemy>		(define::IN_W / 4.f * 3.f, 300.f));
	_list.emplace_back(std::make_shared<bossEnemy>(define::IN_W / 2.f, 0.f));
}

bool enemyMgr::update() {
	for (auto it = _list.begin(); it != _list.end();) {
		if ((*it)->update() == false) {
			it = _list.erase(it);
		}
		else if ((*it)->isAlive() == false) {
			_effectMgr->makeDestroyEffect(*it);
			it = _list.erase(it);

		}
		else {
			it++;
		}
	}
	return true;
}

void enemyMgr::draw() const {
	DrawFormatString(define::OUT_W + 50, 150, GetColor(255, 255, 255), "enemy : %d", _list.size());
	for (auto it : _list) {
		it->draw();
	}
}