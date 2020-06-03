#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include"DxLib.h"
#include"../DisplayFPS.h"
#include "IScene.h"
#include"../FadeManager.h"

//�V�[���Ǘ��N���X
class SceneManager
{
private:
	SceneManager(){}
	SceneManager(const SceneManager&){}

	//���̃V�[�����m�F����
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

	IScene* currentScene;//���ݎ��s���Ă���V�[��
	IScene* nextScene;   //���Ɏ��s����V�[��
	Renderer* renderer;
	FadeManager fadeManager;
	DisplayFPS fps;
	SCENE_STATE state;
	static SceneManager* instance;
};

#endif