#include "Math.h"
#include<cmath>
#include<limits>

float Math::Deg2Rad()
{
	return (PI * 2.0f) / 360.0f;
}

float Math::Rad2Deg()
{
	return 360.0f / (PI / 2.0f);
}

float Math::Infinity()
{
	return std::numeric_limits<float>::infinity();
}

float Math::NegativeInfinity()
{
	return Infinity() * -1.0f;
}

float Math::Abs(float f)
{
	return std::abs(f);
}

float Math::Acos(float r)
{
	return std::acos(r);
}

float Math::Asin(float r)
{
	return std::asin(r);
}

float Math::Atan(float r)
{
	return std::atan(r);
}

float Math::Atan2(float y, float x)
{
	return std::atan2(y, x);
}

float Math::Ceil(float f)
{
	return std::ceil(f);
}

int Math::CeilToInt(float f)
{
	return static_cast<int>(Ceil(f));
}

float Math::Clamp(float n, float min, float max)
{
	if (n < min)
		return min;
	else if (n > max)
		return max;
	else
		return n;
}

float Math::Clamp01(float n)
{
	if (n < 0.0f)
		return 0.0f;
	else if (n > 1.0f)
		return 1.0f;
	else
		return n;
}

float Math::Cos(float r)
{
	return std::cos(r);
}

float Math::Floor(float f)
{
	return std::floor(f);
}

int Math::FloorToInt(float f)
{
	return static_cast<int>(Floor(f));
}

float Math::Lerp(float a, float b, float t)
{
	return a + t * (b - a);
}

float Math::Max(float a, float b)
{
	if (b < a)
		return a;
	else if (a < b)
		return b;

	return a;
}

float Math::Min(float a, float b)
{
	if (a < b)
		return a;
	else if (b < a)
		return b;

	return a;
}

float Math::MoveTowards(float current, float target, float maxDelta)
{
	float n = current + maxDelta;
	if (target < n)
		return target;

	return n;
}

float Math::Pow(float f, float p)
{
	return std::pow(f, p);
}

float Math::Sin(float r)
{
	return std::sin(r);
}


float Math::SmoothStep(float from, float to, float t)
{
	t = Clamp01((t - from) / (to - from));
	return t * t * (3.0f - 2.0f * t);
}

float Math::Sqrt(float f)
{
	return std::sqrt(f);
}

float Math::Tan(float r)
{
	return std::tan(r);
}
