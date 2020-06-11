#include "Title.h"
#include"GameScene.h"

void Title::Initialize()
{
}

void Title::Update()
{
	if (InputManager::Instance()->GetKeyDown(KEY_INPUT_Z)) {
		SceneManager::Instance()->LoadScene(new GameScene());
	}
}

void Title::Draw(Renderer* renderer)
{
	renderer->DrawString(Vector2(280, 240), "ƒ^ƒCƒgƒ‹‰æ–Ê");
}

void Title::Release()
{

}
