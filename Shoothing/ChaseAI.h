#ifndef _CHASEAI_H_
#define _CHASEAI_H_

#include"AI.h"

class ChaseAI:public AI
{
public:
	ChaseAI(GameObject* target);
	~ChaseAI();
	void Think(GameObject* object)override;
private:
	GameObject* target = nullptr;
};

#endif
