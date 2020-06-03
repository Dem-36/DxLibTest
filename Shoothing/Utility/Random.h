#ifndef _RANDOM_H_
#define _RANDOM_H_

#include<random>

#define RANDOM Random::Instance()

class Random {
private:
	Random() {	}
	Random(const Random&) {}
public:
	static Random* Instance();
	static void DestroyInstance();
	float Range(float min, float max);
	int Range(int min, int max);
private:
	static Random* instance;
	std::mt19937 mt{ std::random_device{}() };
};

#endif