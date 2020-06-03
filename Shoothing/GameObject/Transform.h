#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include"../Utility/Vector2.h"

class Transform {
public:
	//コンストラクタ
	Transform():
		position(),angle(0),scale(),spriteSize(){}
public:
	Vector2 position;
	float angle;
	Vector2 scale;
	Vector2 spriteSize;
};

#endif