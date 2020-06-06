#include "Bomb.h"
#include"../Utility/ResourceManager.h"

Bomb::Bomb(const Transform* transform)
{
	this->transform.position = transform->position;
	tag = "Bomb";
	this->transform.spriteSize = Vector2(96, 96);
	index = 0;
}

Bomb::~Bomb()
{
	
}

void Bomb::Initialize()
{
	handle = RESOURCE_MANAGER->LoadAminImageResource(
		"BOMB.png", 8, 8, 1, 96, 96);
	snd = RESOURCE_MANAGER->LoadSoundResource("bomb.mp3");

	PlaySoundMem(snd, DX_PLAYTYPE_BACK);
}

void Bomb::Update()
{
}

void Bomb::Draw(Renderer* renderer)
{
	renderer->DrawGraph_C(transform.position,
		transform.spriteSize, handle[index]);

	index++;
	if (index >= 8)
		Destroy();
}
