#include<DxLib.h>
#include"Screen.h"
#include"Scene/SceneManager.h"
#include"Scene/Title.h"
#include"ErrorException.h"

//�v���O�����̊J�n
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	try {
		//�E�B���h�E���[�h�ŕ\��
		ChangeWindowMode(true);
		//�𑜓x
		SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16);

		//DxLib�̏�����
		if (DxLib_Init() == -1) {
			return -1;
		}
		//�`�����o�b�N�o�b�t�@�ɃZ�b�g
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
	//�I��
	DxLib_End();

	return 0;
}