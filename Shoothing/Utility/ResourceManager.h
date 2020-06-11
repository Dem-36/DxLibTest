#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include<string>
#include<map>
#include"DxLib.h"
#include"../Singleton.h"

using namespace std;

//Flywright�p�^�[���𗘗p�������\�[�X�Ǘ��N���X
class ResourceManager:public Singleton<ResourceManager>
{
public:
	void Release()override;
	int LoadImageResource(string fileName);
	int* LoadAminImageResource(string fileName, int allNum, int xNum, int yNum, int xSize, int ySize);
	int LoadSoundResource(string fileName);
private:
	//���\�[�X�̃n���h�����i�[����
	map<string, int> resourceMap;
	map<string, int*> animMap;
};
#endif

