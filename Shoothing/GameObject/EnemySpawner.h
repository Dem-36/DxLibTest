#ifndef _ENEMYSPAWNER_H_
#define _ENEMYSPAWNER_H_

#include"GameObject.h"
#include"../Subject.h"
#include<vector>
#include"../Utility/Random.h"
#include"../SpawnType.h"

using namespace std;
#define SPAWN_INTERVAL 5

class EnemySpawner :public GameObject
{
public:
	EnemySpawner();
	~EnemySpawner();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);

	IObservable<SPAWN_TYPE>* OnSpawn();

private:
	Subject<SPAWN_TYPE> spawnSubject;
	int waitFrame;
};

#endif