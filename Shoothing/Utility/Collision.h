#ifndef _COLLISION_H_
#define _COLLISION_H_

#include"../GameObject/GameObject.h"

class Collision {
public:
	static bool OnHitRect(GameObject* obj1, GameObject* obj2);
};

#endif
