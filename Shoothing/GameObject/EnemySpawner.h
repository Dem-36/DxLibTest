#ifndef _ENEMYSPAWNER_H_
#define _ENEMYSPAWNER_H_

#include"GameObject.h"
#include"../Subject.h"
#include<vector>
#include"../Utility/Random.h"
#include"../SpawnType.h"
#include"../Time.h"

using namespace std;

class Enemy;

class EnemySpawner :public GameObject
{
public:
	EnemySpawner();
	~EnemySpawner();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);

	Enemy* Spawn(GameObject* target, float diff);

	IObservable<char>* OnSpawn();

private:
	Subject<char> spawnSubject;
	float interval_From;
	float interval_To;
	Time time{ 1.0f };
	Time totalTimer{ 120.0f };
};

#endif