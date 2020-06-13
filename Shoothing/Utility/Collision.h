#ifndef _COLLISION_H_
#define _COLLISION_H_

#include"../GameObject/GameObject.h"

class Collision {
public:
	static bool OnHitRect(const Transform* obj1, const Transform* obj2);
};

#endif
