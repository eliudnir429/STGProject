#include "DxLib.h"
#include "systemMain.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	systemMain system;
	if (system.initialize()) {
		system.main();
	}
	system.finalize();
}