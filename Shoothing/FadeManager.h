#ifndef _FADEMANAGER_H_
#define _FADEMANAGER_H_

#include"DxLib.h"
#include"Utility/ResourceManager.h"
#include"Utility/Renderer.h"
#include"Subject.h"

enum class FADE_TYPE {
	NONE, FADE_IN, FADE_OUT
};

class FadeManager {
public:
	FadeManager();

	void FadeIn();
	void FadeOut();

	void UpdateFade(Renderer* renderer);

	IObservable<FADE_TYPE>* OnFade();
private:
	int handle;
	int alpha;
	FADE_TYPE type;
	Subject<FADE_TYPE> fadeSubject;
};

#endif