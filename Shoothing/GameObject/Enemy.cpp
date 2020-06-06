#include "Enemy.h"
#include"../Utility/ResourceManager.h"
#include"../Utility/Random.h"
#include"../Utility/Algorithm.h"

Enemy::Enemy()
{
	transform.position = Vector2();
	tag = "Enemy";
}

Enemy::Enemy(AI* ai,Vector2 position)
	:ai(ai)
{
	transform.position = position;
	tag = "Enemy";
}


Enemy::~Enemy()
{
	delete ai;
}

void Enemy::Initialize()
{
	transform.angle = 0;
	transform.spriteSize = Vector2(64, 64);
	handle = RESOURCE_MANAGER->LoadImageResource("zombie.png");
	soundHandle = RESOURCE_MANAGER->LoadSoundResource("damage1.mp3");
}

void Enemy::Update()
{
	ai->Think(this);
}

void Enemy::Draw(Renderer* renderer)
{
	renderer->DrawRotaGraph(transform.position, 1.0f, transform.angle, handle);
}

void Enemy::OnHitBox(GameObject* other)
{
	if (other->tag == "Bullet") {
		hitSubject.OnNext(transform);
		PlaySoundMem(soundHandle, DX_PLAYTYPE_BACK);
		Destroy();
	}
}

IObservable<Transform>* Enemy::OnHit()
{
	return &hitSubject;
}
