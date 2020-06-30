#include "Bullet.h"
#include"../Utility/Rectangle.h"
#include"../Utility/ResourceManager.h"
#include"../Screen.h"
#include"../Utility/Algorithm.h"
#include"../DxLibExpansion.h"

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
	handle = ResourceManager::Instance()->LoadImageResource("Bullet.png");
	transform.spriteSize = DxLibExpansion::GetSpriteSize(handle);
}

void Bullet::Update()
{
	Vector2 moveVelocity(0, -10);
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
