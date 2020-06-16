#ifndef _ENEMY_H_
#define _ENEMY_H_

#include"DxLib.h"
#include"GameObject.h"
#include"../Subject.h"
#include"../AI.h"
#include"../SpawnType.h"

enum class SPAWN_TYPE;

class Enemy :public GameObject
{
public:
	Enemy();
	Enemy(AI* ai, Vector2 position);
	Enemy(AI* ai,std::string resourceName, SPAWN_TYPE type);
	~Enemy();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void OnHitBox(GameObject* other);

	IObservable<Transform>* OnHit();

private:
	int handle;
	int soundHandle;
	SPAWN_TYPE type;
	Subject<Transform> hitSubject;
	AI* ai;
};
#endif

