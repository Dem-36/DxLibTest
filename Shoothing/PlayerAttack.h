#ifndef _PLAYERATTACK_H_
#define _PLAYERATTACK_H_

#include"Subject.h"
#include"GameObject\GameObject.h"
#include"Time.h"

#define SHOT_DELAYTIME 0.1f

class PlayerAttack
{
public:
	PlayerAttack(const GameObject* player);
	~PlayerAttack() = default;

	void Shot(int shotCount, int shotRange);
	//NWay shotCount = Ëo‚·‚é’e‚Ì” shotRange = ”ÍˆÍ
	void NWayShot(int shotCount, int shotRange);
	IObservable<Transform>* OnShot();
private:
	Subject<Transform> shotSubject;
	Time shotTimer = { SHOT_DELAYTIME };
	const GameObject* player;
};

#endif