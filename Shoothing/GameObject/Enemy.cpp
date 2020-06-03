#include "Enemy.h"
#include"../Utility/ResourceManager.h"
#include"../Utility/Random.h"
#include"../Utility/Algorithm.h"

Enemy::Enemy()
{
	transform.position = Vector2();
	tag = "Enemy";
}

Enemy::Enemy(Vector2 position)
{
	transform.position = position;
	tag = "Enemy";
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	transform.angle = 0;
	transform.spriteSize = Vector2(64, 64);
	velocity = Vector2();
	handle = RESOURCE_MANAGER->LoadImageResource("Resource\\img\\zombie.png");
	soundHandle = RESOURCE_MANAGER->LoadSoundResource("Resource\\sound\\damage1.mp3");
}

void Enemy::Update()
{
	if (target == NULL)
		return;

	float x = target->transform.position.x - transform.position.x;
	float y = target->transform.position.y - transform.position.y;

	transform.angle = atan2(y, x);

	Vector2 moveVelocity = Vector2(1, 0);
	velocity = Algorithm::RotationMatrix_Z(moveVelocity, transform.angle);

	transform.position += velocity;
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

void Enemy::SetTarget(GameObject* target)
{
	this->target = target;
}

IObservable<Transform>* Enemy::OnHit()
{
	return &hitSubject;
}
