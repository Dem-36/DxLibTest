#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include"DxLib.h"
#include"GameObject.h"
#include<math.h>

class BackGround:public GameObject
{
public:
	BackGround(std::string bgmName,GameObject* player);
	~BackGround();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);

	void StopBGM();

private:
	int handle;
	int soundHandle;
	GameObject* player;
};
#endif

