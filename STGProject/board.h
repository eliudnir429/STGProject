#pragma once
#include "task.h"

class board :public task {
public:
	board();
	virtual ~board() = default;
	bool update() override;
	void draw() const override;
	void drawFrame() const;

private:
	int _img;
};