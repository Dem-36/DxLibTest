#include "Bullet.h"
#include"../Utility/Rectangle.h"
#include"../Utility/ResourceManager.h"
#include"../Screen.h"
#include"../Utility/Algorithm.h"

Bullet::Bullet(Transform* transform)
{
	this->transform.position = transform->position;
	this->transform.angle = transform->angle;
	tag = "Bullet";
}

Bullet::~Bullet()
{
	
}

void Bullet::Initialize()
{
	transform.spriteSize = Vector2(16, 16);
	handle = RESOURCE_MANAGER->LoadImageResource("Resource\\img\\bullet.png");
}

void Bullet::Update()
{
	Vector2 moveVelocity(10, 0);
	velocity = Algorithm::RotationMatrix_Z(moveVelocity, transform.angle);
	transform.position += velocity;

	if (transform.position.x < 0 ||
		transform.position.x>WINDOW_WIDTH ||
		transform.position.y < 0 ||
		transform.position.y>WINDOW_HEIGHT) {
		Destroy();
	}
}

void Bullet::Draw(Renderer* renderer)
{
	renderer->DrawGraph_C(transform.position, transform.spriteSize, handle);
}

void Bullet::OnHitBox(GameObject* other)
{
	if (other->tag == "Box"||
		other->tag=="Enemy") {
		Destroy();
	}
}
