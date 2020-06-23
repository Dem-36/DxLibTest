#include "SceneManager.h"
#include"../Utility/InputManager.h"
#include"../Utility/Random.h"
#include"../GameObject/GameObjectManager.h"
#include"../Utility/ResourceManager.h"
#include"../AudioManager.h"

#define SAFE_RELEASE(x) if(x!=NULL){delete x;x = NULL;}

void SceneManager::Initialize()
{
	AudioManager::Instance()->SetVolume(64);
	AudioManager::Instance()->SetVolume(128,SOUND_TYPE::BGM);
	fadeManager.OnFade()->Subscribe([this](FADE_TYPE type) {
		switch (type) {
			//フェードIN終了
		case FADE_TYPE::FADE_IN:
			state = SCENE_STATE::RELEASE;
			break;
			//フェードOUT終了
		case FADE_TYPE::FADE_OUT:
			break;
		}
		});
}

void SceneManager::CheckNextScene()
{
	if (nextScene == NULL)
		return;
	delete currentScene;
	currentScene = NULL;
	currentScene = nextScene;
	//nextsceneが見ているアドレスをNULL番地にする
	nextScene = NULL;
}

void SceneManager::Update()
{
	//メインループ
	while (ProcessMessage() == 0 &&
		CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();
		InputManager::Instance()->UpdateKey();
		switch (state)
		{
		case SceneManager::SCENE_STATE::INITIALIZE:
			currentScene->Initialize();
			state = SCENE_STATE::UPDATE;
			fadeManager.FadeOut();
			break;
		case SceneManager::SCENE_STATE::UPDATE:
			currentScene->Update();
			currentScene->Draw(renderer);
			break;
		case SceneManager::SCENE_STATE::RELEASE:
			currentScene->Release();
			CheckNextScene();
			state = SCENE_STATE::INITIALIZE;
			break;
		default:
			break;
		}

		fadeManager.UpdateFade(renderer);

		fps.Update();
		fps.Draw();
		ScreenFlip();
		fps.Wait();
	}

	Release();
}

void SceneManager::LoadScene(IScene* scene)
{
	//一番初めのシーン読み込み
	if (currentScene == NULL) {
		currentScene = scene;
		state = SCENE_STATE::INITIALIZE;
	}
	else {
		nextScene = scene;
		fadeManager.FadeIn();
	}
}

void SceneManager::Release()
{
	SAFE_RELEASE(currentScene);
	SAFE_RELEASE(nextScene);
	SAFE_RELEASE(renderer);
	InputManager::Instance()->DestroyInstance();
	ResourceManager::Instance()->Release();
	ResourceManager::Instance()->DestroyInstance();
	AudioManager::Instance()->Release();
	AudioManager::Instance()->DestroyInstance();
	GameObjectManager::Instance()->DestroyInstance();
	this->DestroyInstance();
}
