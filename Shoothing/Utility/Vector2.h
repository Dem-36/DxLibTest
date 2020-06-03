#ifndef _VECTOR2_H_
#define _VECTOR2_H_

struct Vector2 {
public:
	//コンストラクタ
	Vector2();
	Vector2(float x, float y);

	//メンバ関数
	float Length() const; //長さを求める
	Vector2& Normalize();//正規化(自分をするのでアドレス)
	float Dot(const Vector2& v) const;//内積

	static float Distance(const Vector2& v1, const Vector2& v2);

	//単項演算子
	Vector2 operator +()const;
	Vector2 operator -()const;
	//代入演算子
	Vector2& operator +=(const Vector2& v);
	Vector2& operator -=(const Vector2& v);
	Vector2& operator *= (float s);
	Vector2& operator /= (float s);
public:
	float x, y;
};

//二項演算子(operatorで引数が二つあるため)
const Vector2 operator + (const Vector2& v1, const Vector2& v2);
const Vector2 operator - (const Vector2& v1, const Vector2& v2);
const Vector2 operator * (const Vector2& v, float s);
const Vector2 operator * (float s , const Vector2& v);
const Vector2 operator / (const Vector2& v, float s);

#endif