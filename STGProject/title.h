#pragma once
#include "task.h"
#include "define.h"

#define MENU_NUM 4

typedef struct {
	int x, y;
	char name[16];

}titleElements_t;

class title :public task {
public:
	title();
	~title() = default;
	bool update() override;
	void draw() const override;

private:
	titleElements_t titleElements[MENU_NUM];
	static int selectNum;
};