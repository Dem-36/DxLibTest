#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include"DxLib.h"
#include"../DisplayFPS.h"
#include "IScene.h"
#include"../FadeManager.h"
#include"../Singleton.h"

//�V�[���Ǘ��N���X
class SceneManager:public Singleton<SceneManager>
{
private:
	//���̃V�[�����m�F����
	void CheckNextScene();
public:
	void Initialize();
	void Update();
	void LoadScene(IScene* scene);
	void Release()override;
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
};

#endif