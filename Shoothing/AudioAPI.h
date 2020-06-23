#ifndef _AUDIOAPI_H_
#define _AUDIOAPI_H_

#include"AudioManager.h"

class AudioAPI
{
public:
	int LoadSound(std::string fileName, SOUND_TYPE type = SOUND_TYPE::SE) {
		return AudioManager::Instance()->LoadSound(fileName, type);
	}

	void PlayBGM(int handle,int playType = DX_PLAYTYPE_LOOP) {
		AudioManager::Instance()->PlayBGM(handle,playType);
	}

	void PlaySE(int handle,int playType = DX_PLAYTYPE_BACK) {
		AudioManager::Instance()->PlaySE(handle, playType);
	}

	void StopBGM() {
		AudioManager::Instance()->StopBGM();
	}

	void SetVolume(int volume, SOUND_TYPE type = SOUND_TYPE::SE) {
		AudioManager::Instance()->SetVolume(volume, type);
	}
};

#endif