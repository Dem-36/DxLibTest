#include "AudioManager.h"
#include"Math.h"

#define SND_PATH "Resource\\sound\\"

int AudioManager::LoadSound(std::string fileName, SOUND_TYPE type)
{
	if (soundContainer.find(fileName) == soundContainer.end()) {
		SoundInfo info;
		info.type = type;
		info.handle = LoadSoundMem((SND_PATH + fileName).c_str());
		int volume = (type == SOUND_TYPE::SE) ? seVolume : bgmVolume;
		ChangeVolumeSoundMem(volume, info.handle);
		soundContainer[fileName] = info;
	}
	return soundContainer[fileName].handle;
}

void AudioManager::PlayBGM(int handle, int playType)
{
	//�w�肵��BGM�������Ȃ�
	if (currentBGMHandle == handle)
		return;
	currentBGMHandle = handle;
	PlaySoundMem(currentBGMHandle, playType);
}

void AudioManager::PlaySE(int handle, int playType)
{
	PlaySoundMem(handle, playType);
}

void AudioManager::StopBGM()
{
	//BGM���Đ������ǂ���
	if (!CheckSoundMem(currentBGMHandle))
		return;
	StopSoundMem(currentBGMHandle);
	currentBGMHandle = 0;
}

void AudioManager::SetVolume(int volume, SOUND_TYPE type)
{
	if (type == SOUND_TYPE::SE)
		seVolume = volume;
	else if (type == SOUND_TYPE::BGM)
		bgmVolume = volume;

	std::map<std::string, SoundInfo>::iterator itr;
	for (itr = soundContainer.begin(); itr != soundContainer.end(); ++itr) {
		if (itr->second.type != type)
			continue;
		ChangeVolumeSoundMem(volume, itr->second.handle);
	}
}

void AudioManager::Release()
{
	std::map<std::string, SoundInfo>::iterator itr;
	for (itr = soundContainer.begin(); itr != soundContainer.end();)
	{
		DeleteSoundMem(itr->second.handle);
		itr = soundContainer.erase(itr);
	}
}