#include "AudioManager.h"
#include"Math.h"
#include"ErrorExceptionMacro.h"

#define SND_PATH "Resource\\sound\\"

int AudioManager::LoadSound(const std::string& fileName, SOUND_TYPE type)
{
	if (soundContainer.find(fileName) == soundContainer.end()) {
		SoundInfo info;
		info.type = type;
		info.handle = LoadSoundMem((SND_PATH + fileName).c_str());
		int volume = (type == SOUND_TYPE::SE) ? seVolume : bgmVolume;
		ChangeVolumeSoundMem(volume, info.handle);
		soundContainer[fileName] = info;
	}
	if (soundContainer[fileName].handle == -1)
		DX_RESOURCE_EXCEPT(fileName);

	return soundContainer[fileName].handle;
}

void AudioManager::PlayBGM(int handle, int playType)
{
	//éwíËÇµÇΩBGMÇ™ìØÇ∂Ç»ÇÁ
	if (currentBGMHandle == handle)
		return;
	StopBGM();
	currentBGMHandle = handle;
	PlaySoundMem(currentBGMHandle, playType);
}

void AudioManager::PlaySE(int handle, int playType)
{
	PlaySoundMem(handle, playType);
}

void AudioManager::StopBGM()
{
	//BGMÇ™çƒê∂íÜÇ©Ç«Ç§Ç©
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

void AudioManager::AllAudioResources()
{
	LoadSound("bomb.mp3");
	LoadSound("gold-3.wav");
	LoadSound("laser.wav");
	LoadSound("power-up-1.wav");
	LoadSound("Shot.wav");
	LoadSound("Title.ogg", SOUND_TYPE::BGM);
	//LoadSound("GameOver.ogg", SOUND_TYPE::BGM);
	LoadSound("GamePlay.ogg", SOUND_TYPE::BGM);
}
