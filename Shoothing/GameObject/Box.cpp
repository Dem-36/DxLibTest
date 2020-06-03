#include "Box.h"
#include"../Utility/Rectangle.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
Box::Box()
{
	tag = "Box";
}

/// <summary>
/// �����t���R���X�g���N�^
/// </summary>
/// <param name="position"></param>
Box::Box(Vector2 position)
{
	transform.position = position;
	tag = "Box";
}

/// <summary>
/// �����t���R���X�g���N�^
/// </summary>
/// <param name="position"></param>
/// <param name="size"></param>
Box::Box(Vector2 position, Vector2 size)
{
	transform.position = position;
	transform.spriteSize = size;
	tag = "Box";
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Box::~Box()
{
}

/// <summary>
/// ������
/// </summary>
void Box::Initialize()
{

}

void Box::Update()
{
}

void Box::Draw(Renderer* renderer)
{
	struct Rectangle rect(transform.position, transform.spriteSize);
	renderer->DrawBox(rect);
}

void Box::OnHitBox(GameObject* other)
{
	if (other->tag == "Bullet") {
		Destroy();
	}
}
