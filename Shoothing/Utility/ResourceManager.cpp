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

int ResourceManager::LoadImageResource(string fileName)
{
	//�w�肵�����\�[�X�����݂���Ȃ�n���h����Ԃ�
	if (resourceMap.find(fileName) == resourceMap.end())
		 resourceMap[fileName] = LoadGraph(fileName.c_str());

	return resourceMap[fileName];
}

void ResourceManager::LoadAminImageResource(string fileName, int allNum, int xNum, int yNum, int xSize, int ySize,int* handle)
{
	if (resourceMap.find(fileName) == resourceMap.end()) {
		LoadDivGraph(fileName.c_str(), allNum, xNum, yNum, xSize, ySize, handle);
		animMap[fileName] = handle;
	}
	else {
		handle = animMap[fileName];
	}
}

int ResourceManager::LoadSoundResource(string fileName) {
	
	//�w�肵�����\�[�X�����݂���Ȃ�n���h����Ԃ�
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadSoundMem(fileName.c_str());

	return resourceMap[fileName];
}
