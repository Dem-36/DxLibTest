#include"Collision.h"
#include"Rectangle.h"

/// <summary>
/// ‹éŒ`‚Ì“–‚½‚è”»’è
/// </summary>
/// <param name="obj1"></param>
/// <param name="obj2"></param>
/// <returns></returns>
bool Collision::OnHitRect(const Transform* obj1, const Transform* obj2)
{
	struct Rectangle rect1(obj1->position, obj1->spriteSize);
	struct Rectangle rect2(obj2->position, obj2->spriteSize);

	if (rect1.Left() < rect2.Right() &&
		rect1.Top() < rect2.Bottom() &&
		rect2.Left() < rect1.Right() &&
		rect2.Top() < rect1.Bottom()) {
		return true;
	}

	return false;
}
