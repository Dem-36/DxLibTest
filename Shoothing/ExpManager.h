#ifndef _EXPMANAGER_H_
#define _EXPMANAGER_H_

#include"Subject.h"

class ExpManager
{
public:
	ExpManager();
	void Initialize(int level, int needExpBase, int nextExpInterval);
	void AddExp(int exp);
	int GetNeedExp(int level);
	IObservable<char>* OnLevelUp();
	float ExpRatio();
private:
	int nextExpBase;
	int nextExpInterval;
	int level;
	float exp;
	float prevNeedExp;
	float needExp;
	Subject<char> levelUpSubject;
};

#endif

