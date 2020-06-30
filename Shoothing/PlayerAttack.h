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

	//�e�𔭎˂���
	void Shot(int shotCount, int shotRange);
	//NWay shotCount = �ˏo����e�̐� shotRange = �͈�
	void NWayShot(int shotCount, int shotRange);
	//�U���������Ƃ�ʒm����
	IObservable<Transform>* OnShot();
	//�U���Ԋu�̍X�V
	void UpdateInterval(float interval);
private:
	Subject<Transform> shotSubject;
	Time shotTimer = { SHOT_DELAYTIME };
	const GameObject* player;
	int soundHandle;
	AudioAPI api;
};

#endif