#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include<string>
#include<map>
#include"DxLib.h"

using namespace std;

#define RESOURCE_MANAGER ResourceManager::Instance()

//Flywrightパターンを利用したリソース管理クラス
class ResourceManager
{
private:
	ResourceManager(){}
	ResourceManager(const ResourceManager*){}
public:
	static ResourceManager* Instance();
	static void DestroyInstance();
	void Release();

	int LoadImageResource(string fileName);
	int* LoadAminImageResource(string fileName, int allNum, int xNum, int yNum, int xSize, int ySize);
	int LoadSoundResource(string fileName);
private:
	//リソースのハンドラを格納する
	map<string, int> resourceMap;
	map<string, int*> animMap;
	static ResourceManager* instance;
};
#endif

