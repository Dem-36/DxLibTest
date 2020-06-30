#include "PlayerAttack.h"
#include"Utility\InputManager.h"
#include"Math.h"

PlayerAttack::PlayerAttack(const GameObject* player)
	:player(player)
{
	soundHandle = api.LoadSound("Shot.wav");
}

void PlayerAttack::Shot(int shotCount, int shotRange)
{
	if (InputManager::Instance()->GetKey(KEY_INPUT_SPACE)) {
		shotTimer.Update();
		if (shotTimer.IsTime()) {
			NWayShot(shotCount, shotRange);
			shotTimer.Initialize();
			api.PlaySE(soundHandle);
		}
	}
	else
		shotTimer.Initialize();
}

void PlayerAttack::NWayShot(int shotCount, int shotRange)
{
	Vector2 pos = player->transform.position;
	float baseAngle = player->transform.angle;

	if (shotCount > 1) {
		for (int i = 0; i < shotCount; i++) {
			//NWay ’e‚Ì”­ŽËŠp“x‚ÌŒvŽZ
			float angle = baseAngle + (shotRange * Math::Deg2Rad()) * ((float)i / (shotCount - 1) - 0.5f);
			Transform t;
			t.position = pos;
			t.angle = angle;
			shotSubject.OnNext(t);
		}
	}
	else if (shotCount > 0) {
		shotSubject.OnNext(player->transform);
	}
}

IObservable<Transform>* PlayerAttack::OnShot()
{
	return &shotSubject;
}

void PlayerAttack::UpdateInterval(float interval)
{
	shotTimer.limitTime = interval;
}
