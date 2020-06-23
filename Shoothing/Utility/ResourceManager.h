#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include<string>
#include<map>
#include"DxLib.h"
#include"../Singleton.h"

//Flywrightパターンを利用したリソース管理クラス
class ResourceManager:public Singleton<ResourceManager>
{
public:
	void Release()override;
	int LoadImageResource(std::string fileName);
	int* LoadAminImageResource(std::string fileName, int allNum, int xNum, int yNum, int xSize, int ySize);
	int LoadFontResource(std::string fileName,int fontSize,int thick);
private:
	//リソースのハンドラを格納する
	std::map<std::string, int> resourceMap;
	std::map<std::string, int*> animMap;
};
#endif

