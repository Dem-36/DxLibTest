#include "Rectangle.h"

/// <summary>
/// コンストラクタ
/// </summary>
Rectangle::Rectangle()
	:x(0), y(0), width(0), height(0)
{
}

/// <summary>
/// 引数付きコンストラクタ
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
Rectangle::Rectangle(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

/// <summary>
/// 引数付きコンストラクタ
/// </summary>
/// <param name="position"></param>
/// <param name="size"></param>
Rectangle::Rectangle(Vector2 position, Vector2 size)
{
	this->x = position.x;
	this->y = position.y;
	this->width = size.x;
	this->height = size.y;
}

void Rectangle::Set(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Rectangle::Set(Vector2 position, Vector2 size)
{
	this->x = position.x;
	this->y = position.y;
	this->width = size.x;
	this->height = size.y;
}

/// <summary>
/// 四角形の上辺のYを取得する
/// </summary>
/// <returns></returns>
float Rectangle::Top() const
{
	return y - (height / 2);
}

/// <summary>
/// 四角形の底辺のYを取得する
/// </summary>
/// <returns></returns>
float Rectangle::Bottom() const
{
	return y + (height / 2);
}

/// <summary>
/// 四角形の右辺のXを取得する
/// </summary>
/// <returns></returns>
float Rectangle::Right() const
{
	return x + (width / 2);
}

/// <summary>
/// 四角形の左辺のXを取得する
/// </summary>
/// <returns></returns>
float Rectangle::Left() const
{
	return x - (width / 2);
}

/// <summary>
/// 四角形の右上隅の位置を取得
/// </summary>
/// <returns></returns>
Vector2 Rectangle::TopRight()
{
	return Vector2(Right(), Top());
}

/// <summary>
/// 四角形の左上隅の位置を取得
/// </summary>
/// <returns></returns>
Vector2 Rectangle::TopLeft()
{
	return Vector2(Left(), Top());
}

/// <summary>
/// 四角形の右下隅の位置を取得
/// </summary>
/// <returns></returns>
Vector2 Rectangle::BottomRight()
{
	return Vector2(Right(), Bottom());
}

/// <summary>
/// 四角形の左下隅の位置を取得
/// </summary>
/// <returns></returns>
Vector2 Rectangle::BottomLeft()
{
	return Vector2(Left(), Bottom());
}
