#ifndef _ENEMYSPAWNER_H_
#define _ENEMYSPAWNER_H_

#include"GameObject.h"
#include"../Subject.h"
#include<vector>
#include"../Utility/Random.h"
#include"../SpawnType.h"
#include"../Time.h"

using namespace std;

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
	Time time{ 0.25f };
};

#endif