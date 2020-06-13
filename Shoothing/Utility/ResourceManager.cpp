#include "ResourceManager.h"

#define IMG_PATH "Resource\\img\\"
#define SND_PATH "Resource\\sound\\"

//�A�ԉ摜���J������
void ResourceManager::Release()
{
	for (auto itr = animMap.begin(); itr != animMap.end(); ++itr) {
		delete itr->second;
	}
}

//�摜��o�^����
int ResourceManager::LoadImageResource(string fileName)
{
	//�w�肵�����\�[�X�����݂���Ȃ�n���h����Ԃ�
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadGraph((IMG_PATH + fileName).c_str());

	return resourceMap[fileName];
}

//�A�ԉ摜��o�^����
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
		LoadDivGraph((IMG_PATH + fileName).c_str(), allNum, xNum, yNum, xSize, ySize, handle);
		animMap[fileName] = handle;
	}
	return animMap[fileName];
}

//������o�^����
int ResourceManager::LoadSoundResource(string fileName) {

	//�w�肵�����\�[�X�����݂���Ȃ�n���h����Ԃ�
	if (resourceMap.find(fileName) == resourceMap.end())
		resourceMap[fileName] = LoadSoundMem((SND_PATH + fileName).c_str());

	return resourceMap[fileName];
}
