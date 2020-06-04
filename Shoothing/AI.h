#ifndef _AI_H_
#define _AI_H_

#include"Utility\Vector2.h"
#include"GameObject/GameObject.h"

class AI {
public:
	AI():position(Vector2::Zero()),velocity(Vector2::Zero()) {

	}
	virtual void Think(GameObject* object) = 0;
protected:
	Vector2 position;
	Vector2 velocity;
};

#endif