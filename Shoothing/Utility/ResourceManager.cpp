#include "ResourceManager.h"

#define IMG_PATH "Resource\\img\\"
#define SND_PATH "Resource\\sound\\"

//連番画像を開放する
void ResourceManager::Release()
{
	for (auto itr = animMap.begin(); itr != animMap.end(); ++itr) {
		delete itr->second;
	}
}

//画像を登録する
int ResourceManager::LoadImageResource(string fileName)
{
	//指定したリソースが存在するならハンドルを返す
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadGraph((IMG_PATH + fileName).c_str());

	return resourceMap[fileName];
}

//連番画像を登録する
int* ResourceManager::LoadAminImageResource(string fileName, int allNum, int xNum, int yNum, int xSize, int ySize)
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
	return animMap[fileName];
}

//音源を登録する
int ResourceManager::LoadSoundResource(string fileName) {

	//指定したリソースが存在するならハンドルを返す
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadSoundMem((SND_PATH + fileName).c_str());

	return resourceMap[fileName];
}
