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
private:
	int nextExpBase;
	int nextExpInterval;
	int level;
	int exp;
	int prevNeedExp;
	int needExp;
	Subject<char> levelUpSubject;
};

#endif

