#pragma once
#include "baseObject.h"

typedef struct {
	int x, y;
	int width, height;
}shot_t;

class shot :public baseObject {
public:
	shot();
	~shot() = default;
	void update();
	void draw();

private:
	static shot_t _shot[];
	int _img;
};