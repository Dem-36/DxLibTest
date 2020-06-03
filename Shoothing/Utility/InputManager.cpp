#include"InputManager.h"
#include"DxLib.h"

InputManager* InputManager::instance = NULL;

InputManager* InputManager::Instance() {
	if (instance == NULL)
		instance = new InputManager();

	return instance;
}

void InputManager::DestroyInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}

void InputManager::UpdateKey() {
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);//すべてのキーの入力状態を保存
	int i;
	for (i = 0; i < ARRAYSIZE(tmpKey); i++) {
		if (tmpKey[i] != 0){
			key[i]++;//長押し判定をするためにインクリメントしている
			if (key[i] >= 40)
				key[i] = 2;
		}
		else if (tmpKey[i] == 0 && key[i] > 0)
			key[i] = -1;
		else
			key[i] = 0;
	}
}

/// <summary>
/// キーが押されているかどうか(長押し対応)
/// </summary>
/// <param name="keyCode"></param>
/// <returns></returns>
bool InputManager::GetKey(int keyCode)
{
	//1の場合はGetKeyDown(押された直後)
	if (key[keyCode] > 1)
		return true;

	return false;
}

/// <summary>
/// キーが押されたかどうか(押された直後)
/// </summary>
/// <param name="keyCode"></param>
/// <returns></returns>
bool InputManager::GetKeyDown(int keyCode)
{
	if (key[keyCode] == 1)
		return true;

	return false;
}

/// <summary>
/// キーが離されたかどうか(離された直後)
/// </summary>
/// <param name="keyCode"></param>
/// <returns></returns>
bool InputManager::GetKeyUp(int keyCode)
{
	if (key[keyCode] == -1)
		return true;

	return false;
}
