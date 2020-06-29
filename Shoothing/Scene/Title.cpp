#include "Title.h"
#include"GameScene.h"

void Title::Initialize()
{
	handle = api.LoadSound("Title.ogg", SOUND_TYPE::BGM);
	api.PlayBGM(handle);
}

void Title::Update()
{
	if (InputManager::Instance()->GetKeyDown(KEY_INPUT_Z)) {
		SceneManager::Instance()->LoadScene(new GameScene());
	}
}

void Title::Draw(Renderer* renderer)
{
	renderer->DrawString(Vector2(280, 240), "�^�C�g�����");
}

void Title::Release()
{

}
