#ifndef _RANDOM_H_
#define _RANDOM_H_

#include<random>

class Random {
public:
	static float Range(float min, float max);
	static int Range(int min, int max);
};

#endif