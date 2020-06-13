#include"Random.h"

//float型の数値でmin以上max以下で乱数を出す
float Random::Range(float min, float max)
{
	std::random_device seed;
	std::mt19937 mt(seed());
	std::uniform_real_distribution<float> rnd(min, max);
	return rnd(mt);
}

//int型の数値でmin以上max以下で乱数を出す
int Random::Range(int min, int max)
{
	std::random_device seed;
	std::mt19937 mt(seed());
	std::uniform_int_distribution<int> rnd(min, max);
	return rnd(mt);
}
