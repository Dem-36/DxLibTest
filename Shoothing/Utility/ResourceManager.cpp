#include "ResourceManager.h"
#include"../ErrorExceptionMacro.h"

#define IMG_PATH "Resource\\img\\"

//�A�ԉ摜���J������
void ResourceManager::Release()
{
	for (auto itr = animMap.begin(); itr != animMap.end(); ++itr) {
		delete itr->second;
	}
}

//�摜��o�^����
int ResourceManager::LoadImageResource(std::string fileName)
{
	//�w�肵�����\�[�X�����݂���Ȃ�n���h����Ԃ�
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadGraph((IMG_PATH + fileName).c_str());
	if (resourceMap[fileName] == -1)
		DX_RESOURCE_EXCEPT(fileName);
	return resourceMap[fileName];
}

//�A�ԉ摜��o�^����
int* ResourceManager::LoadAminImageResource(std::string fileName, int allNum, int xNum, int yNum, int xSize, int ySize)
{
	if (animMap.find(fileName) == animMap.end()) {
		//�w�肵���������������m��
		int* handle = new int[allNum];
		//�m�ۂɎ��s������
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

//�t�H���g�f�[�^�̍쐬�A�o�^
int ResourceManager::LoadFontResource(std::string fileName, int fontSize, int thick)
{
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = CreateFontToHandle(fileName.c_str(), fontSize,  thick);

	if (resourceMap[fileName] == -1)
		DX_RESOURCE_EXCEPT(fileName);

	return resourceMap[fileName];
}
