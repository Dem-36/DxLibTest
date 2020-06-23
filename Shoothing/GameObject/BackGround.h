#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include"DxLib.h"
#include"GameObject.h"
#include<math.h>
#include"../AudioAPI.h"

class BackGround:public GameObject
{
public:
	BackGround(std::string bgmName,Transform* t_Player);
	~BackGround();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);

	void StopBGM();

private:
	int handle;
	int bgmHandle;
	AudioAPI api;
	const Transform* t_Player;
};
#endif

