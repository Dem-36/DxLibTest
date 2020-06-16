#include "Animation.h"
#include"Utility\ResourceManager.h"

Animation::Animation()
{
	loopFlag = false;
	index = 0;
}

void Animation::SetAnim(const std::string fileName, int allNum, int xNum, int yNum, int xSize, int ySize, float time)
{
	//‘”•Û‘¶
	allAnimNum = allNum;
	handle = ResourceManager::Instance()->LoadAminImageResource(fileName, allNum, xNum, yNum, xSize, ySize);
	timer.SetLimitTime(time);
}

void Animation::Update()
{
	if (index >= allAnimNum  && !loopFlag)
		return;
	timer.Update();
	if (timer.IsTime()) {
		timer.Initialize();
		index++;
		if (index >= allAnimNum && loopFlag)
			index = 0;
	}
}

int Animation::GetAnimHandle()
{
	return handle[index];
}

void Animation::SetLoopFlag(bool loopFlag)
{
	this->loopFlag = loopFlag;
}

bool Animation::IsEnd()
{
	if (loopFlag)
		return false;

	return index >= allAnimNum;
}
