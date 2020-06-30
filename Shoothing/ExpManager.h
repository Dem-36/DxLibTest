#ifndef _EXPMANAGER_H_
#define _EXPMANAGER_H_

#include"Subject.h"
#include"Utility\Renderer.h"
#include"AudioAPI.h"

#define MAX_LEVEL 10

class ExpManager
{
public:
	ExpManager();
	void Initialize(int level, int needExpBase, int nextExpInterval);
	void Draw(Renderer* renderer);
	void AddExp(int exp);
	float GetNeedExp(int level);
	//レベルアップを通知する
	IObservable<char>* OnLevelUp();
	float ExpRatio();
	int GetLevel();
private:
	int nextExpBase = 0;
	int nextExpInterval = 0;
	int level = 0;
	int handle = 0;
	int soundHandle = 0;
	float exp = 0.0f;
	float prevNeedExp = 0.0f;
	float needExp = 0.0f;
	Subject<char> levelUpSubject;
	AudioAPI api;
};

#endif

