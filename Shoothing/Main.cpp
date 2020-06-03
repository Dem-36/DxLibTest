#include<DxLib.h>
#include"Screen.h"
#include"Scene/SceneManager.h"
#include"Scene/Title.h"

//�v���O�����̊J�n
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
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
	//�I��
	DxLib_End();

	return 0;
}