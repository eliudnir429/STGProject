#include <DxLib.h>
#include "systemMain.h"
#include "define.h"
#include "sceneMgr.h"

bool systemMain::initialize() {
	SetAlwaysRunFlag(TRUE);			//ウィンドウがノンアクティブでも実行
	SetWindowText("nekochan");		//ウィンドウタイトルを付ける
	SetWindowSizeChangeEnableFlag(TRUE);	//ウィンドウサイズを自由に変更できるようにする
	ChangeWindowMode(TRUE);			//ウィンドウモードに変更
//	SetWindowSizeExtendRate(1.0);	//ウィンドウサイズを変更したい時はここに倍率を指定する
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init()) {				//DXライブラリ初期化処理
		return false;				//異常終了したら即座にやめる
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面処理を設定する

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