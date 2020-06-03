#ifndef _ENEMYSPAWNER_H_
#define _ENEMYSPAWNER_H_

#include"GameObject.h"
#include"../Subject.h"
#include<vector>
#include"../Utility/Random.h"

using namespace std;
#define SPAWN_INTERVAL 60

class EnemySpawner:public GameObject
{
public:
	EnemySpawner();
	~EnemySpawner();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);

	void AddSpawnPoint(Vector2 spawnPoint);
	IObservable<Vector2>* OnSpawn();

private:
	Subject<Vector2> spawnSubject;
	vector<Vector2> spawnPoints;
	int waitFrame;
};

#endif