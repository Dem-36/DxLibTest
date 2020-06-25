#include "EnemySpawner.h"
#include"../Math.h"
EnemySpawner::EnemySpawner()
{
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Initialize()
{
	interval_From = 1.0f;
	interval_To = 0.25f;
}

void EnemySpawner::Update()
{
	totalTimer.Update();
	time.Update();
	float t = Math::Clamp01(totalTimer.GetNowTime() / totalTimer.GetLimitTime());
	float interval = Math::Lerp(interval_From, interval_To,t);
	if (time.GetNowTime() < interval)
		return;
	
	SPAWN_TYPE type = static_cast<SPAWN_TYPE>(Random::Range(0, 3));
	spawnSubject.OnNext(type);

	time.Initialize();
}

void EnemySpawner::Draw(Renderer* renderer)
{
}

IObservable<SPAWN_TYPE>* EnemySpawner::OnSpawn()
{
	return &spawnSubject;
}
