#include "Bomb.h"
#include"../Utility/ResourceManager.h"
#include"../DxLibExpansion.h"

Bomb::Bomb(const Transform* transform)
{
	this->transform.position = transform->position;
	tag = "Bomb";
}

Bomb::~Bomb()
{
	
}

void Bomb::Initialize()
{
	anim.SetAnim("Bomb.png", 8, 8, 1, 82, 72, 0.05f);
	snd = ResourceManager::Instance()->LoadSoundResource("bomb.mp3");
	this->transform.spriteSize = DxLibExpansion::GetSpriteSize(anim.GetAnimHandle());
	PlaySoundMem(snd, DX_PLAYTYPE_BACK);
}

void Bomb::Update()
{
}

void Bomb::Draw(Renderer* renderer)
{
	renderer->DrawGraph_C(transform.position,
		transform.spriteSize, anim.GetAnimHandle());

	anim.Update();
	if (anim.IsEnd())
		Destroy();
}
