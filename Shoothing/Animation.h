#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include<string>

class Animation {
public:
	Animation(const std::string fileName,int allNum,int xNum,int yNum,int xSize,int ySize);
private:
	int* handle;
	int allAnimNum;
};

#endif