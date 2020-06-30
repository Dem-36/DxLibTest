#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include<string>
#include<map>
#include"DxLib.h"
#include"../Singleton.h"
#include"../FontData.h"

//Flywrightパターンを利用したリソース管理クラス
class ResourceManager:public Singleton<ResourceManager>
{
public:
	void Release()override;
	int LoadImageResource(const std::string& fileName);
	int* LoadAminImageResource(const std::string& fileName, int allNum, int xNum, int yNum, int xSize, int ySize);
	int LoadFontResource(const std::string& fileName,int fontSize,int thick);
private:
	//リソースのハンドラを格納する
	std::map<std::string, int> resourceMap;
	std::map<FontData, int> fontMap;
	std::map<std::string, int*> animMap;
};
#endif

