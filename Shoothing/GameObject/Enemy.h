#ifndef _ENEMY_H_
#define _ENEMY_H_

#include"DxLib.h"
#include"GameObject.h"
#include"../Subject.h"
#include"../AI.h"
#include"../SpawnType.h"
#include"../AudioAPI.h"

struct EnemyHitInfo {
	Transform t;
	int exp;
};

class Enemy :public GameObject
{
public:
	Enemy();
	Enemy(AI* ai, Vector2 position);
	Enemy(AI* ai,std::string resourceName, SPAWN_TYPE type,int exp,int hp);
	~Enemy();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void OnHitBox(GameObject* other);

	IObservable<Transform>* OnHit();
	IObservable<EnemyHitInfo>* OnDrop();

private:
	int handle;
	int soundHandle;
	int exp;
	int hp;
	SPAWN_TYPE type;
	Subject<Transform> hitSubject;
	Subject<EnemyHitInfo> dropSubject;
	AI* ai;
	AudioAPI api;
};
#endif

