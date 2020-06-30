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
#include"../Math.h"

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
	//è’ìÀéûÇÃÉCÉxÉìÉgÇìoò^
	IObservable<Transform>* OnHit();
	IObservable<Transform>* OnDead();
	IObservable<Transform>* OnLevelUp();
	float HPRatio();
	float DrawDist()const;
public:
	ExpManager expManager;
	PlayerAttack playerAttack;
private:
	Subject<Transform> hitSubject;
	Subject<Transform> deadSubject;
	Subject<Transform> levelUpSubject;
	PlayerMove playerMove;
	int handle;
	float hp;
	AudioAPI api;

	struct PlayerParameter {
		void Initialize(int scFrom,int scTo,float siFrom,float siTo,float dgFrom,float dgTo) {
			shotCount = scFrom;
			shotCountFrom = scFrom;
			shotCountTo = scTo;
			shotInterval = siFrom;
			shotIntervalFrom = siFrom;
			shotIntervalTo = siTo;
			drawGem = dgFrom;
			drawGemFrom = dgFrom;
			drawGemTo = dgTo;
		}
		void UpdateParameter(int level) {
			float t = (float)(level - 1) / (MAX_LEVEL - 1);

			shotCount =Math::RoundToInt(Math::Lerp(shotCountFrom, shotCountTo, t));
			shotInterval = Math::Lerp(shotIntervalFrom, shotIntervalTo, t);
			drawGem = Math::Lerp(drawGemFrom, drawGemTo, t);
		}
		int shotCount;
		int shotCountFrom;
		int shotCountTo;
		float shotInterval;
		float shotIntervalFrom;
		float shotIntervalTo;
		float drawGem;
		float drawGemFrom;
		float drawGemTo;
	}parameter;
};

#endif

