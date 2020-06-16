#include"StraightAI.h"
#include"Utility\Random.h"

StraightAI::StraightAI(SPAWN_TYPE type)
{
	switch (type) {
	case SPAWN_TYPE::UP:
		velocity = Vector2::Down();
		break;
	case SPAWN_TYPE::DOWN:
		velocity = Vector2::Up();
		break;
	case SPAWN_TYPE::LEFT:
		velocity = Vector2::Right();
		break;
	case SPAWN_TYPE::RIGHT:
		velocity = Vector2::Left();
		break;
	}
}

StraightAI::~StraightAI()
{

}


void StraightAI::Think(GameObject* object)
{
	object->transform.position += velocity * 2.0f;
}
