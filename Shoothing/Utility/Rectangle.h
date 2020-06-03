#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include"Vector2.h"

struct Rectangle {
public:
	Rectangle();
	Rectangle(float x, float y, float width, float height);
	Rectangle(Vector2 position, Vector2 size);

	void Set(float x, float y, float width, float height);
	void Set(Vector2 position, Vector2 size);

	float Top() const;
	float Bottom() const;
	float Right() const;
	float Left() const;

	Vector2 TopRight();
	Vector2 TopLeft();
	Vector2 BottomRight();
	Vector2 BottomLeft();

public:
	float x, y, width, height;
};

#endif