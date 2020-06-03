#include"Random.h"

Random* Random::instance = NULL;

Random* Random::Instance()
{
	if (instance == NULL)
		instance = new Random();
	return instance;
}

void Random::DestroyInstance()
{
	if (instance == NULL)
		return;
	delete instance;
	instance = NULL;
}

//float�^�̐��l��min�ȏ�max�ȉ��ŗ������o��
float Random::Range(float min, float max)
{
	std::uniform_real_distribution<float> rnd(min, max);
	return rnd(mt);
}

//int�^�̐��l��min�ȏ�max�ȉ��ŗ������o��
int Random::Range(int min, int max)
{
	std::uniform_int_distribution<int> rnd(min, max);
	return rnd(mt);
}
