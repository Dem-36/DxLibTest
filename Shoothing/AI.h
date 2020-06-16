#ifndef _AI_H_
#define _AI_H_

#include"Utility\Vector2.h"
#include"GameObject/GameObject.h"
#include"Screen.h"
#include"Utility\Random.h"

class AI {
public:
	AI() :position(Vector2::Zero()), velocity(Vector2::Zero()) {

	}
	//指定したオブジェクトのTransform情報を書き換える
	virtual void Think(GameObject* object) = 0;
protected:
	Vector2 position;
	Vector2 velocity;
};

#endif