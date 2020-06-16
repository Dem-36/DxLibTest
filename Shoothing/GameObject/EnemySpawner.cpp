#include "EnemySpawner.h"

EnemySpawner::EnemySpawner()
{
	waitFrame = 0;
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Initialize()
{
	waitFrame = 0;
}

void EnemySpawner::Update()
{
	waitFrame++;
	if (waitFrame < SPAWN_INTERVAL)
		return;

	SPAWN_TYPE type = static_cast<SPAWN_TYPE>(Random::Range(0, 3));
	spawnSubject.OnNext(type);

	waitFrame = 0;
}

void EnemySpawner::Draw(Renderer* renderer)
{
}

IObservable<SPAWN_TYPE>* EnemySpawner::OnSpawn()
{
	return &spawnSubject;
}
