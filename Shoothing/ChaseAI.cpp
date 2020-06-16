#include "ChaseAI.h"
#include"Utility\Algorithm.h"
#include"Math.h"

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
	//�ʒu�̍X�V
	position = object->transform.position;

	float x = target->transform.position.x - position.x;
	float y = target->transform.position.y - position.y;

	//�p�x�����߂�(�G�̌����Ă����������̂���)
	object->transform.angle = atan2(y, x) + (90.0f * Math::Deg2Rad());
	//float angle = Math::Atan2(y, x);

	//�摜�̌����Ă�������x�N�g��
	Vector2 moveVel = Vector2(0.0f, -2.5f);
	velocity = Algorithm::RotationMatrix_Z(moveVel, object->transform.angle);
	object->transform.position += velocity;
}
