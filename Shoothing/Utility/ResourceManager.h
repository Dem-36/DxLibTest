#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include<string>
#include<map>
#include"DxLib.h"
#include"../Singleton.h"

using namespace std;

//Flywrightパターンを利用したリソース管理クラス
class ResourceManager:public Singleton<ResourceManager>
{
public:
	void Release()override;
	int LoadImageResource(string fileName);
	int* LoadAminImageResource(string fileName, int allNum, int xNum, int yNum, int xSize, int ySize);
	int LoadSoundResource(string fileName);
private:
	//リソースのハンドラを格納する
	map<string, int> resourceMap;
	map<string, int*> animMap;
};
#endif

