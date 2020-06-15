#ifndef _MATH_H_
#define _MATH_H_

//円周率
#define PI 3.14159265359f

class Math
{
public:
	//DegreeからRadianに変換
	static float Deg2Rad();
	//RadianからDegreeに変換
	static float Rad2Deg();
	//無限大の表示
	static float Infinity();
	//負の無限大の表示
	static float NegativeInfinity();
public:
	//絶対値の取得
	static float Abs(float f);
	//アークコサイン(r = ラジアン)
	static float Acos(float r);
	//アークサイン(r = ラジアン)
	static float Asin(float r);
	//アークタンジェント(r = ラジアン)
	static float Atan(float r);
	//Tanがy/xになる角度をラジアンで返す
	static float Atan2(float y, float x);
	//f以上の最小の整数を返す(小数第一位切り上げ)
	static float Ceil(float f);
	//f以上の最小の整数を返す(小数第一位切り上げ)
	static int CeilToInt(float f);
	//nをminからmaxに制限する
	static float Clamp(float n, float min, float max);
	//nを0から1に制限する
	static float Clamp01(float n);
	//コサイン(r = ラジアン)
	static float Cos(float r);
	//f以上の最小の整数を返す(小数第一位切り捨て)
	static float Floor(float f);
	//f以上の最小の整数を返す(小数第一位切り捨て)
	static int FloorToInt(float f);
	//線形補完
	static float Lerp(float a, float b, float t);
	//a,bを比べ、大きい方を返す
	static float Max(float a, float b);
	//a,bを比べ、小さい方を返す
	static float Min(float a, float b);
	//currentからtargetまで、maxDeltaのスピードで移動する
	static float MoveTowards(float current, float target, float maxDelta);
	//fのp乗の値を返す
	static float Pow(float f, float p);
	//サイン(r = ラジアン)
	static float Sin(float r);
	//fromとtoの間で制限したスムージングで補完する
	static float SmoothStep(float from,float to,float t);
	//fの平方根を返す
	static float Sqrt(float f);
	//タンジェント(r = ラジアン)
	static float Tan(float r);
};
#endif

