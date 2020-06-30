#ifndef _TITLE_H_
#define _TITLE_H_

#include"IScene.h"
#include"SceneManager.h"
#include"../AudioAPI.h"
#include"../TitleCanvas.h"

class Title:public IScene
{
public:
	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void Release();
private:
	int handle;
	AudioAPI api;
	TitleCanvas titleCanvas;
};

#endif