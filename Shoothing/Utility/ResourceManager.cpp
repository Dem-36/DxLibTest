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
	//�ǂݍ��ݎ��A������̃t�H���g�����邩�ǂ����𒲂ׂ�
	std::map<FontData, int>::iterator itr;
	for (itr = fontMap.begin(); itr != fontMap.end(); ++itr)
	{
		if (itr->first.fontName == fileName &&
			itr->first.fontSize == fontSize &&
			itr->first.thick == thick) {
			return itr->second;
		}
	}
	//�Ȃ��ꍇ�͐V�K�쐬
	int handle = CreateFontToHandle(fileName.c_str(), fontSize, thick);
	FontData data(fileName, fontSize, thick);
	fontMap.emplace(data,handle);
	return handle;
}
