#pragma once
#include "task.h"
#include <list>
#include <memory>
#include "effect.h"

class effectMgr :public task {
public:
	effectMgr() = default;
	virtual ~effectMgr() = default;
	bool update();
	void draw() const;
	void addList(float x, float y);
private:
	std::list<std::shared_ptr<effect>> _list;
};