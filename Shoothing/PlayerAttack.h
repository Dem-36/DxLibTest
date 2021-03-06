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

	//弾を発射する
	void Shot(int shotCount, int shotRange);
	//NWay shotCount = 射出する弾の数 shotRange = 範囲
	void NWayShot(int shotCount, int shotRange);
	//攻撃したことを通知する
	IObservable<Transform>* OnShot();
	//攻撃間隔の更新
	void UpdateInterval(float interval);
private:
	Subject<Transform> shotSubject;
	Time shotTimer = { SHOT_DELAYTIME };
	const GameObject* player;
	int soundHandle;
	AudioAPI api;
};

#endif