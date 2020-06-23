#include"Easing.h"
#include"Math.h"

float Easing::LinerIn(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	return end * ct / et + start;
}

float Easing::QuadraticIn(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et;
	return end * Quadratic(ct) + start;
}

float Easing::QuadraticOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et;
	return -end * ct * (ct - 2.0f) + start;
}

float Easing::QuadraticInOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et / 2.0f;
	if (ct < 1.0f)
		return end / 2.0f * Quadratic(ct) + start;
	ct--;
	return -end / 2.0f * (ct * (ct - 2.0f) - 1.0f) + start;
}

float Easing::CubicIn(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et;
	return end * Cubic(ct) + start;
}

float Easing::CubicOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et;
	ct--;
	return end * (Cubic(ct) + 1.0f) + start;
}

float Easing::CubicInOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et / 2.0f;
	if (ct < 1.0f)
		return end / 2.0f * Cubic(ct) + start;
	ct -= 2.0f;
	return end / 2.0f * (Cubic(ct) + 2.0f) + start;
}

float Easing::QuarticIn(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et;
	return end * Quartic(ct) + start;
}

float Easing::QuarticOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et;
	ct--;
	return -end * (Quartic(ct) - 1.0f) + start;
}

float Easing::QuarticInOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et / 2.0f;
	if (ct < 1.0f)
		return end / 2.0f * Quartic(ct) + start;
	ct -= 2.0f;
	return -end / 2.0f * (Quartic(ct) - 2.0f) + start;
}

float Easing::SinusoidalIn(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	return -end * Math::Cos(ct / et * (PI / 2.0f)) + end + start;
}

float Easing::SinusoidalOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	return end * Math::Sin(ct / et * (PI / 2.0f)) + start;
}

float Easing::SinusoidalInOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	return -end / 2.0f * (Math::Cos(PI * ct / et) - 1.0f) + start;
}

float Easing::ExponentialIn(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	return end * Math::Pow(2.0f, 10.0f * (ct / et - 1.0f)) + start;
}

float Easing::ExponentialOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	return end * (-Math::Pow(2.0f, -10.0f * ct / et) + 1.0f) + start;
}

float Easing::ExponentialInOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et / 2.0f;
	if (ct < 1.0f)
		return end / 2.0f * Math::Pow(2.0f, 10.0f * (ct - 1.0f)) + start;
	ct--;
	return end / 2.0f * (-Math::Pow(2.0f, -10.0f * ct) + 2.0f) + start;
}

float Easing::CircularIn(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et;
	return -end * (Math::Sqrt(1.0f - ct * et) - 1.0f) + start;
}

float Easing::CircularOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et;
	ct--;
	return end * Math::Sqrt(1.0f - ct * ct) + start;
}

float Easing::CircularInOut(float ct, float et, float start, float end)
{
	if (ct >= et)
		return end;
	end -= start;
	ct /= et / 2.0f;
	if (ct < 1.0f)
		return -end / 2.0f * (Math::Sqrt(1.0f - ct * ct) - 1.0f) + start;
	ct -= 2.0f;
	return end / 2.0f * (Math::Sqrt(1 - ct * ct) + 1.0f) + start;
}
