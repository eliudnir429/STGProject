#pragma once

class define {
public:
	const static int WINDOW_W;
	const static int WINDOW_H;

	const static int OUT_W;
	const static int OUT_H;
	const static int IN_W;
	const static int IN_H;
	const static int IN_X;
	const static int IN_Y;

	const static float PI;

	enum eCharacterType {
		TYPE_NONE,
		TYPE_SHOT,
		TYPE_PLAYER,
		TYPE_ENEMY,
		TYPE_OBJECT,
		TYPE_NUM,
	};

	enum eTitleParam {
		NEW_GAME,
		CONTINUE,
		CONFIG,
		EXIT,
	};
};
