#include "Animation.h"
#include"Utility\ResourceManager.h"

Animation::Animation(const std::string fileName, int allNum, int xNum, int yNum, int xSize, int ySize)
{
	//‘”•Û‘¶
	allAnimNum = allNum;
	handle = ResourceManager::Instance()->LoadAminImageResource(fileName, allNum, xNum, yNum, xSize, ySize);
}
