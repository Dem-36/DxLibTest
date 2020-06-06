#include "ChaseAI.h"
#include"Utility\Algorithm.h"

ChaseAI::ChaseAI(GameObject* target)
	:target(target)
{
}

ChaseAI::~ChaseAI()
{
	delete target;
}

void ChaseAI::Think(GameObject* object)
{
	//位置の更新
	position = object->transform.position;

	float x = target->transform.position.x - object->transform.position.x;
	float y = target->transform.position.y - object->transform.position.y;

	//角度を求める
	object->transform.angle = atan2(y, x);

	//画像の向いている方向ベクトル
	Vector2 moveVel = Vector2(1, 0);
	velocity = Algorithm::RotationMatrix_Z(moveVel, object->transform.angle);
	object->transform.position += velocity;
}
