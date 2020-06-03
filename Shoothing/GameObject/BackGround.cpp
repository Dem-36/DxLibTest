#include "BackGround.h"
#include"../Utility/ResourceManager.h"

BackGround::BackGround()
{
	transform.position = Vector2();
	transform.spriteSize = Vector2();
}

BackGround::~BackGround()
{
	StopSoundMem(soundHandle);
}

void BackGround::Initialize()
{
	handle = RESOURCE_MANAGER->LoadImageResource("Resource\\img\\bg.png");
	soundHandle = RESOURCE_MANAGER->LoadSoundResource ("Resource\\sound\\nv_01.mp3");
	PlaySoundMem(soundHandle, DX_PLAYTYPE_LOOP);
}

void BackGround::Update()
{
}

void BackGround::Draw(Renderer* renderer)
{
	renderer->DrawGraph_TL(transform.position, handle);
}
