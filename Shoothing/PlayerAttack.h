#ifndef _PLAYERATTACK_H_
#define _PLAYERATTACK_H_

#include"Subject.h"
#include"GameObject\GameObject.h"
#include"Time.h"
#include"AudioAPI.h"

#define SHOT_DELAYTIME 0.1f

class PlayerAttack
{
public:
	PlayerAttack(const GameObject* player);
	~PlayerAttack() = default;

	//’e‚ğ”­Ë‚·‚é
	void Shot(int shotCount, int shotRange);
	//NWay shotCount = Ëo‚·‚é’e‚Ì” shotRange = ”ÍˆÍ
	void NWayShot(int shotCount, int shotRange);
	//UŒ‚‚µ‚½‚±‚Æ‚ğ’Ê’m‚·‚é
	IObservable<Transform>* OnShot();
	//UŒ‚ŠÔŠu‚ÌXV
	void UpdateInterval(float interval);
private:
	Subject<Transform> shotSubject;
	Time shotTimer = { SHOT_DELAYTIME };
	const GameObject* player;
	int soundHandle;
	AudioAPI api;
};

#endif