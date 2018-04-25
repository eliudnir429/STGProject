#pragma once
#include "baseScene.h"
#include "define.h"

#define MENU_NUM 3

typedef struct {
	int x, y;
	char name[NAME];

}titleElements_t;

class title :public baseScene {
public:
	title() = default;
	void update();
	void draw();

private:
	titleElements_t titleElements[MENU_NUM] = {
		{ 80,100,"NEW GAME" },
		{ 100,150,"CONFIG" },
		{ 100,200,"EXIT" },
	};
	static int selectNum;
};