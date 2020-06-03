#ifndef _ENEMY_H_
#define _ENEMY_H_

#include"DxLib.h"
#include"GameObject.h"
#include"../Subject.h"

class Enemy:public GameObject
{
public:
	Enemy();
	Enemy(Vector2 position);
	~Enemy();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void OnHitBox(GameObject* other);

	void SetTarget(GameObject* target);

	IObservable<Transform>* OnHit();

private:
	int handle;
	int soundHandle;
	GameObject* target;
	Vector2 velocity;

	Subject<Transform> hitSubject;
};
#endif

