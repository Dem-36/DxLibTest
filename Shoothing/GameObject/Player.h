#ifndef _PLAYER_H_
#define _PLAYER_H_
#include"DxLib.h"
#include"GameObject.h"
#include"../Subject.h"

#define SHOT_DELAYFRAME 10

class Player:public GameObject
{
public:
	Player();
	 ~Player();
	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	IObservable <Transform>* OnShotButton();
private:
	void Move();
	void Shot();
private:
	Subject<Transform> shotSubject;
	Vector2 velocity;
	int soundHandle;
	int waitFrame;
	int* h;
};

#endif

