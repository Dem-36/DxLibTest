#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#define INPUT_MANAGER InputManager::Instance()

class InputManager {
private:
	//コンストラクタをprivateにし、
	//外部からインスタンスが生成されないようにする
	InputManager(){}
	InputManager(const InputManager&){}
public:
	static InputManager* Instance();
	static void DestroyInstance();
public:
	void UpdateKey();
	bool GetKey(int);
	bool GetKeyDown(int);
	bool GetKeyUp(int);
private:
	char key[256];//キー情報保存
	static InputManager* instance;
};

#endif