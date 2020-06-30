#include "Title.h"
#include"GameScene.h"

void Title::Initialize()
{
	handle = api.LoadSound("Title.ogg", SOUND_TYPE::BGM);
	api.PlayBGM(handle);
	titleCanvas.Initialize();
}

void Title::Update()
{
	titleCanvas.Update();
	if (InputManager::Instance()->GetKeyDown(KEY_INPUT_Z)) {
		SceneManager::Instance()->LoadScene(new GameScene());
	}
}

void Title::Draw(Renderer* renderer)
{
	titleCanvas.Draw(renderer);
}

void Title::Release()
{
	titleCanvas.Release();
}
