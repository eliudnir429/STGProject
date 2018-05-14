#include "collisionJud.h"

collisionJud::collisionJud(std::shared_ptr<shot> shot, std::shared_ptr<abstractEnemy> enemy) {
	shot->getCollisionArea(_shotX, _shotY, _shotRad);
	enemy->getCollisionArea(_enemyX, _enemyY, _enemyRad);
	_x = _shotX - _enemyX;
	_y = _shotY - _enemyY;
	_rad = _shotRad; +_enemyRad;
}

bool collisionJud::update() {
	if (_x *_x + _y * _y < _rad * _rad) {
		return true;
	}
	return false;
}

void collisionJud::draw() const {

}