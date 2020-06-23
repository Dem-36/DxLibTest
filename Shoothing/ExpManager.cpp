#include "ExpManager.h"

ExpManager::ExpManager(){}

void ExpManager::Initialize(int level,int nextExpBase, int nextExpInterval)
{
	this->level = level;
	this->nextExpBase = nextExpBase;
	this->nextExpInterval = nextExpInterval;
	needExp = GetNeedExp(1);
}

void ExpManager::AddExp(int exp)
{
	this->exp += exp;
	if (this->exp < needExp)
		return;

	level++;
	prevNeedExp = needExp;
	needExp = GetNeedExp(level);
	levelUpSubject.OnNext(' ');
}

int ExpManager::GetNeedExp(int level)
{
	return nextExpBase + nextExpInterval * ((level - 1) * (level - 1));
}

IObservable<char>* ExpManager::OnLevelUp()
{
	return &levelUpSubject;
}
