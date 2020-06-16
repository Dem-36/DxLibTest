#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include<string>
#include"Time.h"

class Animation {
public:
	Animation();
	void SetAnim(const std::string fileName, int allNum, int xNum, int yNum, int xSize, int ySize, float time);
	void Update();
	int GetAnimHandle();
	void SetLoopFlag(bool loopFlag);
	bool IsEnd();
private:
	int* handle;
	int allAnimNum;
	Time timer;
	bool loopFlag;
	int index;
};

#endif