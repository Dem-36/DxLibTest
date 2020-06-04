#ifndef _ENEMY_H_
#define _ENEMY_H_

#include"DxLib.h"
#include"GameObject.h"
#include"../Subject.h"
#include"../ChaseAI.h"

class Enemy:public GameObject
{
public:
	Enemy();
	Enemy(AI* ai,Vector2 position);
	~Enemy();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void OnHitBox(GameObject* other);

	IObservable<Transform>* OnHit();

private:
	int handle;
	int soundHandle;

	Subject<Transform> hitSubject;
	AI* ai;
};
#endif

