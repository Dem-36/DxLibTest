#ifndef _SCOREGEM_H_
#define _SCOREGEM_H_

#include"GameObject\GameObject.h"
#include"Time.h"
#include"Animation.h"
#include"Subject.h"
#include"GameObject\Player.h"

class ScoreGem :public GameObject
{
public:
	ScoreGem(Player* player, const Transform* transform, int exp);
	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void OnHitBox(GameObject* other);
	int GetExp()const noexcept;
	IObservable<int>* OnHit();
private:
	int m_exp;
	Time time{ 1.0f };
	Vector2 velocity;
	float speed;
	Animation anim;
	Subject<int> hitSubject;
	const Player* player;
};
#endif
