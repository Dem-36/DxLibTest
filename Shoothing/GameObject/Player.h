#ifndef _PLAYER_H_
#define _PLAYER_H_
#include"DxLib.h"
#include"GameObject.h"
#include"../Subject.h"
#include"../Time.h"
#include"../ExpManager.h"
#include"../AudioAPI.h"
#include"../PlayerMove.h"
#include"../PlayerAttack.h"

#define MAX_HP 5.0f

class Player:public GameObject
{
public:
	Player();
	 ~Player();
	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void OnHitBox(GameObject* other);
	//Õ“Ë‚ÌƒCƒxƒ“ƒg‚ğ“o˜^
	IObservable<Transform>* OnHit();
	IObservable<Transform>* OnDead();
	IObservable<Transform>* OnLevelUp();
	void AddExp(int exp);
	float ExpRatio();
	float HPRatio();
public:
	PlayerAttack playerAttack;
private:
	Subject<Transform> hitSubject;
	Subject<Transform> deadSubject;
	Subject<Transform> levelUpSubject;
	PlayerMove playerMove;
	int soundHandle;
	int handle;
	float hp;
	ExpManager expManager;
	AudioAPI api;
};

#endif

