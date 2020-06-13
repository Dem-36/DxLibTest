#ifndef _PLAYER_H_
#define _PLAYER_H_
#include"DxLib.h"
#include"GameObject.h"
#include"../Subject.h"
#include"../Time.h"

#define SHOT_DELAYTIME 0.1f

class Player:public GameObject
{
public:
	Player();
	 ~Player();
	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	IObservable <Transform>* OnShotButton();
	void OnHitBox(GameObject* other);
	//�Փˎ��̃C�x���g��o�^
	IObservable<Transform>* OnHit();
private:
	void Move();
	void Shot();
private:
	Subject<Transform> shotSubject;
	Subject<Transform> hitSubject;
	Vector2 velocity;
	int soundHandle;
	Time timer{ SHOT_DELAYTIME };
	int handle;
};

#endif

