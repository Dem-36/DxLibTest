#ifndef _STRAIGHT_H_
#define _STRAIGHT_H_

#include"AI.h"
#include"SpawnType.h"

class StraightAI :public AI
{
public:
	StraightAI(SPAWN_TYPE type);
	~StraightAI();
	void Think(GameObject* object)override;
private:
	Vector2 direction;
};

#endif
