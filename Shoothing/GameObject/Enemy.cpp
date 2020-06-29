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

Enemy::Enemy(AI* ai, std::string resourceName, SPAWN_TYPE type, int exp, int hp)
	:ai(ai), type(type), exp(exp), hp(hp)
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
	if (IsDestroy())
		return;
	ai->Think(this);
	if (transform.position.x < -100.0f ||
		transform.position.x >= WINDOW_WIDTH + 100.0f ||
		transform.position.y < -100.0f ||
		transform.position.y >= WINDOW_HEIGHT + 100.0f)
		Destroy();
}

void Enemy::Draw(Renderer* renderer)
{
	renderer->DrawRotaGraph(transform.position, 1.0f, transform.angle, handle);
}

void Enemy::OnHitBox(GameObject* other)
{
	if (other->tag == "Bullet") {
		hp--;
		if (hp <= 0) {
			EnemyHitInfo info;
			info.t.position = transform.position;
			info.t.angle = transform.angle;
			info.exp = exp;
			dropSubject.OnNext(info);
			hitSubject.OnNext(transform);
			Destroy();
		}
	}
	else if (other->tag == "Player") {
		hp = 0;
		hitSubject.OnNext(transform);
		Destroy();
	}
}

IObservable<Transform>* Enemy::OnHit()
{
	return &hitSubject;
}

IObservable<EnemyHitInfo>* Enemy::OnDrop()
{
	return &dropSubject;
}
