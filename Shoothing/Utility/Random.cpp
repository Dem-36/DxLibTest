#include"Random.h"

//float�^�̐��l��min�ȏ�max�ȉ��ŗ������o��
float Random::Range(float min, float max)
{
	std::random_device seed;
	std::mt19937 mt(seed());
	std::uniform_real_distribution<float> rnd(min, max);
	return rnd(mt);
}

//int�^�̐��l��min�ȏ�max�ȉ��ŗ������o��
int Random::Range(int min, int max)
{
	std::random_device seed;
	std::mt19937 mt(seed());
	std::uniform_int_distribution<int> rnd(min, max);
	return rnd(mt);
}
