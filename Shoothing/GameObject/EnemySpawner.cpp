#include "EnemySpawner.h"

EnemySpawner::EnemySpawner()
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
	time.Update();
	if (!time.IsTime())
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
