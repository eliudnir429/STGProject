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

void effectMgr::addList(float x, float y) {
	_list.emplace_back(std::make_shared<effect>(x, y));
}