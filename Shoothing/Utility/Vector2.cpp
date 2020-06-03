#include"Vector2.h"
#include<cmath>
#include<assert.h>

/// <summary>
/// 引数なしコンストラクタ
/// </summary>
Vector2::Vector2()
	:x(0), y(0) {

}

/// <summary>
/// コンストラクタ(座標指定)
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
Vector2::Vector2(float x, float y)
	: x(x), y(y) {

}

/// <summary>
/// 長さを返す
/// </summary>
/// <returns></returns>
float Vector2::Length() const {
	return std::sqrt(x * x + y * y);
}

/// <summary>
/// 正規化
/// </summary>
/// <returns></returns>
Vector2& Vector2::Normalize() {
	float l = Length();
	if (l != 0) {
		x /= l;
		y /= l;
	}
	return *this;
}

/// <summary>
/// 内積
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
float Vector2::Dot(const Vector2& v) const {
	return x * v.x + y * v.y;
}

/// <summary>
/// 二点間の距離を求める
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
float Vector2::Distance(const Vector2& v1, const Vector2& v2)
{
	float x = v1.x - v2.x;
	float y = v1.y - v2.y;
	return sqrt((x * x) + (y * y));
}

/// <summary>
/// 単項演算子 +
/// </summary>
/// <returns></returns>
Vector2 Vector2::operator + () const {
	return *this;
}

Vector2 Vector2::operator - () const {
	return *this * -1;
}

Vector2& Vector2::operator += (const Vector2& v) {
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& v) {
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

Vector2& Vector2::operator*=(float s) {
	this->x *= s;
	this->x *= s;
	return *this;
}

Vector2& Vector2::operator/=(float s) {
	assert(s == 0);
	this->x /= s;
	this->y /= s;
	return *this;
}

const Vector2 operator+ (const Vector2& v1, const Vector2& v2) {
	return Vector2(v1.x + v2.x, v1.y + v2.y);
}

const Vector2 operator- (const Vector2& v1, const Vector2& v2) {
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

const Vector2 operator*(const Vector2& v, float s) {
	return Vector2(v.x * s, v.y * s);
}

const Vector2 operator*(float s, const Vector2& v) {
	return Vector2(v.x * s, v.y * s);
}

const Vector2 operator/(const Vector2& v, float s) {
	assert(s == 0);
	return Vector2(v.x / s, v.y / s);
}