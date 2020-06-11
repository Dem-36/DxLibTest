#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include"../Singleton.h"

class InputManager :public Singleton<InputManager>
{
public:
	void UpdateKey();
	bool GetKey(int);
	bool GetKeyDown(int);
	bool GetKeyUp(int);
	void Release()override;
private:
	char key[256];//ƒL[î•ñ•Û‘¶
};

#endif