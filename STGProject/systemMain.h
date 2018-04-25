#pragma once
#include "define.h"

class systemMain {
public:
	systemMain() = default;
	~systemMain() = default;
	bool initialize();
	void main();
	void finalize();
};