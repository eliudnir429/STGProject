#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "effect.h"
#include "abstractShot.h"

class effectMgr :public task {
public:
	effectMgr() = default;
	virtual ~effectMgr() = default;
	bool update();
	void draw() const;
	void makeEffect(std::shared_ptr<abstractShot> playerShot);
private:
	std::list<std::shared_ptr<effect>> _list;
};