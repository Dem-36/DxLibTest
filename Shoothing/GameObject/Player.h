#ifndef _PLAYER_H_
#define _PLAYER_H_
#include"DxLib.h"
#include"GameObject.h"
#include"../Subject.h"
#include"../Time.h"
#include"../ExpManager.h"
#include"../AudioAPI.h"

#define SHOT_DELAYTIME 0.1f
#define MAX_HP 5.0f

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
	//Õ“Ë‚ÌƒCƒxƒ“ƒg‚ğ“o˜^
	IObservable<Transform>* OnHit();
	IObservable<Transform>* OnDead();
	IObservable<Transform>* OnLevelUp();
	void AddExp(int exp);
	float ExpRatio();
	float HPRatio();
private:
	void Move();
	void Shot();
	//NWay shotCount = Ëo‚·‚é’e‚Ì” shotRange = ”ÍˆÍ
	void NWayShot(int shotCount,float shotRange);
private:
	Subject<Transform> shotSubject;
	Subject<Transform> hitSubject;
	Subject<Transform> deadSubject;
	Subject<Transform> levelUpSubject;
	Vector2 velocity;
	int soundHandle;
	int handle;
	float hp;
	Time timer{ SHOT_DELAYTIME };
	ExpManager expManager;
	AudioAPI api;
};

#endif

