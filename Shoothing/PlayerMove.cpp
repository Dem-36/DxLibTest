#include "PlayerMove.h"
#include"Utility\InputManager.h"
#include"Utility\Algorithm.h"
#include"Math.h"

void PlayerMove::Move(Transform& transform,const Vector2 velocity)
{
	if (InputManager::Instance()->GetKey(KEY_INPUT_UP))
		transform.position += this->velocity;
	if (InputManager::Instance()->GetKey(KEY_INPUT_DOWN))
		transform.position -= this->velocity;
	if (InputManager::Instance()->GetKey(KEY_INPUT_LEFT))
		transform.angle -= 5.0f * Math::Deg2Rad();
	if (InputManager::Instance()->GetKey(KEY_INPUT_RIGHT))
		transform.angle += 5.0f * Math::Deg2Rad();

	this->velocity = velocity;
	this->velocity = Algorithm::RotationMatrix_Z(this->velocity, transform.angle);
}
