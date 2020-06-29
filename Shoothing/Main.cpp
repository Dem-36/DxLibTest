#include<DxLib.h>
#include"Screen.h"
#include"Scene/SceneManager.h"
#include"Scene/Title.h"
#include"ErrorException.h"

//プログラムの開始
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	try {
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
	}
	catch (const ErrorException& e) {
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e) {
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...) {
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	SceneManager::Instance()->Release();
	//終了
	DxLib_End();

	return 0;
}