#include "BackGround.h"
#include"../Utility/ResourceManager.h"

BackGround::BackGround(std::string bgmName,GameObject*player)
{
	transform.position = Vector2();
	transform.spriteSize = Vector2();
	soundHandle = ResourceManager::Instance()->LoadSoundResource(bgmName);
	this->player = player;
}

BackGround::~BackGround()
{
	StopSoundMem(soundHandle);
}

void BackGround::Initialize()
{
	handle = ResourceManager::Instance()->LoadImageResource("5.png");
	PlaySoundMem(soundHandle, DX_PLAYTYPE_LOOP);
}

void BackGround::Update()
{
	
}

void BackGround::Draw(Renderer* renderer)
{
	renderer->DrawGraph_TL(transform.position, handle);
}

void BackGround::StopBGM()
{
	StopSoundMem(soundHandle);
}
