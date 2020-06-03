#include<DxLib.h>
#include"Screen.h"
#include"Scene/SceneManager.h"
#include"Scene/Title.h"

//プログラムの開始
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//ウィンドウモードで表示
	ChangeWindowMode(true);
	//解像度
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16);

	//DxLibの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}
	//描画先をバックバッファにセット
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager::Instance()->Initialize();
	SceneManager::Instance()->LoadScene(new Title());
	SceneManager::Instance()->Update();
	//終了
	DxLib_End();

	return 0;
}