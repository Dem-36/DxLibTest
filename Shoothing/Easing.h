#ifndef _EASING_H_
#define _EASING_H_


class Easing {
public:
	static float LinerIn(float ct, float et, float start, float end);

	static float QuadraticIn(float ct, float et, float start, float end);

	static float QuadraticOut(float ct, float et, float start, float end);

	static float QuadraticInOut(float ct, float et, float start, float end);

	static float CubicIn(float ct, float et, float start, float end);

	static float CubicOut(float ct, float et, float start, float end);

	static float CubicInOut(float ct, float et, float start, float end);

	static float QuarticIn(float ct, float et, float start, float end);

	static float QuarticOut(float ct, float et, float start, float end);

	static float QuarticInOut(float ct, float et, float start, float end);

	static float SinusoidalIn(float ct, float et, float start, float end);

	static float SinusoidalOut(float ct, float et, float start, float end);

	static float SinusoidalInOut(float ct, float et, float start, float end);

	static float ExponentialIn(float ct, float et, float start, float end);

	static float ExponentialOut(float ct, float et, float start, float end);

	static float ExponentialInOut(float ct, float et, float start, float end);

	static float CircularIn(float ct, float et, float start, float end);
	
	static float CircularOut(float ct, float et, float start, float end);

	static float CircularInOut(float ct, float et, float start, float end);

private:
	static float Quadratic(float t) { return t * t; }
	static float Cubic(float t) { return t * t * t; }
	static float Quartic(float t) { return t * t * t * t; }
	static float Quintic(float t) { return t * t * t * t * t; }
};

#endif