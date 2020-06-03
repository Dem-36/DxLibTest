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

	int index = RANDOM->Range(0, spawnPoints.size() - 1);
	spawnSubject.OnNext(spawnPoints[index]);

	waitFrame = 0;
}

void EnemySpawner::Draw(Renderer* renderer)
{
}

void EnemySpawner::AddSpawnPoint(Vector2 spawnPoint)
{
	spawnPoints.push_back(spawnPoint);
}

IObservable<Vector2>* EnemySpawner::OnSpawn()
{
	return &spawnSubject;
}
