#include "EnemySpawner.h"
#include"../Math.h"
#include"Enemy.h"
#include"../ChaseAI.h"
#include"../StraightAI.h"

EnemySpawner::EnemySpawner()
	:interval_From(1.0f),interval_To(0.25f)
{
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Initialize()
{
}

void EnemySpawner::Update()
{
	totalTimer.Update();
	time.Update();
	float t = Math::Clamp01(totalTimer.GetNowTime() / totalTimer.limitTime);
	float interval = Math::Lerp(interval_From, interval_To,t);
	if (time.GetNowTime() < interval)
		return;
	
	spawnSubject.OnNext(' ');

	time.Initialize();
}

void EnemySpawner::Draw(Renderer* renderer)
{
}

Enemy* EnemySpawner::Spawn(GameObject* target, float diff)
{
	float r = Random::Range(0.0f, 100.0f);
	SPAWN_TYPE type = static_cast<SPAWN_TYPE>(Random::Range(0, 3));
	r *= diff;
	if (r <= 35.0f)
		return new Enemy(new StraightAI(type), "Enemy01.png", type, 1, 1);
	else if (r < 60.0f)
		return new Enemy(new ChaseAI(target), "Enemy02.png", type, 2, 2);
	else if (r <= 85.0f)
		return new Enemy(new ChaseAI(target), "Enemy03.png", type, 4, 4);
	else
		return new Enemy(new StraightAI(type), "Enemy04.png", type, 6, 6);
}

IObservable<char>* EnemySpawner::OnSpawn()
{
	return &spawnSubject;
}
