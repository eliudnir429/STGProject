#include "DxLib.h"
#include "keyboard.h"

static int key[256];

int keyboardUpdate() {
	char tmpKey[256];			// 現在のキーの入力状態を格納する

	GetHitKeyStateAll(tmpKey);	// 全てのキーの入力状態を得る
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {
			key[i]++;
		}
		else {
			key[i] = 0;
		}
	}
	return 0;
}

int keyboardGet(int keyCode) {
	return key[keyCode];
}