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
	//�w�肵�����\�[�X�����݂���Ȃ�n���h����Ԃ�
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadGraph(fileName.c_str());

	return resourceMap[fileName];
}

int* ResourceManager::LoadAminImageResource(string fileName, int allNum, int xNum, int yNum, int xSize, int ySize)
{
	if (animMap.find(fileName) == animMap.end()) {
		//�w�肵���������������m��
		int* handle = new int[allNum];
		//�m�ۂɎ��s������
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

	//�w�肵�����\�[�X�����݂���Ȃ�n���h����Ԃ�
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadSoundMem(fileName.c_str());

	return resourceMap[fileName];
}
