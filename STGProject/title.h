#pragma once
#include "baseScene.h"
#include "define.h"

#define MENU_NUM 4

typedef struct {
	int x, y;
	char name[16];

}titleElements_t;

class title :public baseScene {
public:
	title();
	~title() = default;
	void update();
	void draw();

private:
	titleElements_t titleElements[MENU_NUM];
	static int selectNum;
};