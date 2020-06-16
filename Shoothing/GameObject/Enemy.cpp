#include "Enemy.h"
#include"../Utility/ResourceManager.h"
#include"../Utility/Random.h"
#include"../Utility/Algorithm.h"
#include"../DxLibExpansion.h"

Enemy::Enemy()
{
	transform.position = Vector2();
	tag = "Enemy";
}

Enemy::Enemy(AI* ai, Vector2 position)
	:ai(ai)
{
	transform.position = position;
	tag = "Enemy";
}

Enemy::Enemy(AI* ai,std::string resourceName, SPAWN_TYPE type)
	:ai(ai), type(type)
{
	handle = ResourceManager::Instance()->LoadImageResource(resourceName);
	tag = "Enemy";
}

Enemy::~Enemy()
{
	delete ai;
}

void Enemy::Initialize()
{
	transform.angle = 0;
	transform.spriteSize = DxLibExpansion::GetSpriteSize(handle);
	soundHandle = ResourceManager::Instance()->LoadSoundResource("damage1.mp3");

	float c = 40.0f;
	float r = 10.0f;
	switch (type) {
	case SPAWN_TYPE::UP:
		transform.position = Vector2(Random::Range(r, WINDOW_WIDTH - r), -c);
		break;
	case SPAWN_TYPE::DOWN:
		transform.position = Vector2(Random::Range(r, WINDOW_WIDTH - r), WINDOW_HEIGHT + c);
		break;
	case SPAWN_TYPE::LEFT:
		transform.position = Vector2(-c, Random::Range(r, WINDOW_HEIGHT - r));
		break;
	case SPAWN_TYPE::RIGHT:
		transform.position = Vector2(WINDOW_WIDTH + c, Random::Range(r, WINDOW_HEIGHT - r));
		break;
	}
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
