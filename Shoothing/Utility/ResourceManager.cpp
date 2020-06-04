#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = NULL;

ResourceManager* ResourceManager::Instance()
{
	if (instance == NULL)
		instance = new ResourceManager();

	return instance;
}

void ResourceManager::DestroyInstance()
{
	if (instance == NULL)
		return;

	delete instance;
	instance = NULL;
}

void ResourceManager::Release()
{
	for (auto itr = animMap.begin(); itr != animMap.end(); ++itr) {
		delete itr->second;
	}
}

int ResourceManager::LoadImageResource(string fileName)
{
	//指定したリソースが存在するならハンドルを返す
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadGraph(fileName.c_str());

	return resourceMap[fileName];
}

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
		LoadDivGraph(fileName.c_str(), allNum, xNum, yNum, xSize, ySize, handle);
		animMap[fileName] = handle;
	}
	return animMap[fileName];
}

int ResourceManager::LoadSoundResource(string fileName) {

	//指定したリソースが存在するならハンドルを返す
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadSoundMem(fileName.c_str());

	return resourceMap[fileName];
}
