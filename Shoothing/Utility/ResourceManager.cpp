#include "ResourceManager.h"
#include"../ErrorExceptionMacro.h"

#define IMG_PATH "Resource\\img\\"

//連番画像を開放する
void ResourceManager::Release()
{
	for (auto itr = animMap.begin(); itr != animMap.end(); ++itr) {
		delete itr->second;
	}
}

//画像を登録する
int ResourceManager::LoadImageResource(std::string fileName)
{
	//指定したリソースが存在するならハンドルを返す
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadGraph((IMG_PATH + fileName).c_str());
	if (resourceMap[fileName] == -1)
		DX_RESOURCE_EXCEPT(fileName);
	return resourceMap[fileName];
}

//連番画像を登録する
int* ResourceManager::LoadAminImageResource(std::string fileName, int allNum, int xNum, int yNum, int xSize, int ySize)
{
	if (animMap.find(fileName) == animMap.end()) {
		//指定した数分メモリを確保
		int* handle = new int[allNum];
		//確保に失敗したら
		if (handle == nullptr) {
			delete[] handle;
			return nullptr;
		}
		LoadDivGraph((IMG_PATH + fileName).c_str(), allNum, xNum, yNum, xSize, ySize, handle);
		animMap[fileName] = handle;
	}
	if (animMap[fileName][0] == -1)
		DX_RESOURCE_EXCEPT(fileName);
	return animMap[fileName];
}

//フォントデータの作成、登録
int ResourceManager::LoadFontResource(std::string fileName, int fontSize, int thick)
{
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = CreateFontToHandle(fileName.c_str(), fontSize,  thick);

	if (resourceMap[fileName] == -1)
		DX_RESOURCE_EXCEPT(fileName);

	return resourceMap[fileName];
}
