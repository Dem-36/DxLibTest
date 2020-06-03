#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include"DxLib.h"
#include"../DisplayFPS.h"
#include "IScene.h"
#include"../FadeManager.h"

//シーン管理クラス
class SceneManager
{
private:
	SceneManager(){}
	SceneManager(const SceneManager&){}

	//次のシーンを確認する
	void CheckNextScene();

public:
	static SceneManager* Instance();
	static void DestroyInstance();
	void Initialize();
	void Update();
	void LoadScene(IScene* scene);
private:
	void Release();

private:
	enum class SCENE_STATE {
		INITIALIZE,UPDATE,RELEASE
	};

	IScene* currentScene;//現在実行しているシーン
	IScene* nextScene;   //次に実行するシーン
	Renderer* renderer;
	FadeManager fadeManager;
	DisplayFPS fps;
	SCENE_STATE state;
	static SceneManager* instance;
};

#endif