#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include<string>

class Animation {
public:
	Animation(const std::string fileName);
private:
	int* handle;
};

#endif