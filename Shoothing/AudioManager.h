#ifndef _AUDIOMANAGER_H_
#define _AUDIOMANAGER_H_

#include"Singleton.h"
#include"DxLib.h"
#include<map>
#include<string>

enum class SOUND_TYPE {
	BGM,
	SE,
};

class AudioManager :public Singleton<AudioManager>
{
public:
	int LoadSound(std::string fileName, SOUND_TYPE type = SOUND_TYPE::SE);
	void PlayBGM(int handle, int playType = DX_PLAYTYPE_LOOP);
	void PlaySE(int handle, int playType = DX_PLAYTYPE_BACK);
	void StopBGM();
	void SetVolume(int volume,SOUND_TYPE type = SOUND_TYPE::SE);
	void Release()override;
private:
	struct SoundInfo {
		SOUND_TYPE type;
		int handle;
	};
private:
	int currentBGMHandle;
	int bgmVolume = 255;
	int seVolume = 255;
	std::map<std::string, SoundInfo> soundContainer;
};
#endif

