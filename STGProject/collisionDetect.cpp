#include "collisionDetect.h"

collisionDetect::collisionDetect(const std::shared_ptr<player>& player, const std::shared_ptr<enemyMgr>& enemyMgr, const std::shared_ptr<pShotMgr>& pShotMgr, const std::shared_ptr<effectMgr>& effectMgr) {
	_player = player;
	_enemyMgr = enemyMgr;
	_pShotMgr = pShotMgr;
	_effectMgr = effectMgr;
}

bool collisionDetect::update() {

	return true;
}

void collisionDetect::draw() const {

}

bool collisionDetect::isHitPlayerShot(std::shared_ptr<abstractShot> shot) {
	shot->getCollisionArea(_shotX, _shotY, _shotRad);

	for (auto it : _enemyMgr->_list) {
		it->getCollisionArea(_objectX, _objectY, _objectRad);
		_x = _shotX - _objectX;
		_y = _shotY - _objectY;
		_rad = _shotRad + _objectRad;
		
		if ((_x*_x) + (_y*_y) <= (_rad*_rad)) {
			return true;
		}
	}
	return false;
}