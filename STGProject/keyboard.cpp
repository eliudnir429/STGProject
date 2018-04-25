#include "DxLib.h"
#include "keyboard.h"

static int key[256];

int keyboardUpdate() {
	char tmpKey[256];			// ���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(tmpKey);	// �S�ẴL�[�̓��͏�Ԃ𓾂�
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