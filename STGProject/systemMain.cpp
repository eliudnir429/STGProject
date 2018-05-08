#include <DxLib.h>
#include "systemMain.h"
#include "define.h"
#include "sceneMgr.h"

bool systemMain::initialize() {
	SetAlwaysRunFlag(TRUE);			//�E�B���h�E���m���A�N�e�B�u�ł����s
	SetWindowText("nekochan");		//�E�B���h�E�^�C�g����t����
	SetWindowSizeChangeEnableFlag(TRUE);	//�E�B���h�E�T�C�Y�����R�ɕύX�ł���悤�ɂ���
	ChangeWindowMode(TRUE);			//�E�B���h�E���[�h�ɕύX
//	SetWindowSizeExtendRate(1.0);	//�E�B���h�E�T�C�Y��ύX���������͂����ɔ{�����w�肷��
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init()) {				//DX���C�u��������������
		return false;				//�ُ�I�������瑦���ɂ�߂�
	}
	SetDrawScreen(DX_SCREEN_BACK);	//����ʏ�����ݒ肷��

	return true;
}

void systemMain::main() {
	sceneMgr scene;

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		scene.update();
		scene.draw();
	}
}

void systemMain::finalize() {
	DxLib_End();
}