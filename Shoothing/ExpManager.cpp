#include "ExpManager.h"
#include"Utility\ResourceManager.h"
#include"Screen.h"
#include<string>

ExpManager::ExpManager()
{}

void ExpManager::Initialize(int level, int nextExpBase, int nextExpInterval)
{
	this->level = level;
	this->nextExpBase = nextExpBase;
	this->nextExpInterval = nextExpInterval;
	needExp = GetNeedExp(1);
	handle = ResourceManager::Instance()->LoadFontResource("Orbitron", 18, 3);
	soundHandle = api.LoadSound("power-up-1.wav");
}

void ExpManager::Draw(Renderer* renderer)
{
	std::string tex = "LEVEL " + std::to_string(level);
	renderer->DrawStringToHandle(Vector2(WINDOW_WIDTH / 2.0f - 50.0f, 10.0f), tex.c_str(), GetColor(255, 255, 255), handle);
}

void ExpManager::AddExp(int exp)
{
	this->exp += exp;
	if (this->exp < needExp)
		return;
	if (level >= MAX_LEVEL)
		return;

	level++;
	api.PlaySE(soundHandle);
	prevNeedExp = needExp;
	needExp = GetNeedExp(level);
	levelUpSubject.OnNext(' ');
}

float ExpManager::GetNeedExp(int level)
{
	return (float)(nextExpBase + nextExpInterval * ((level - 1) * (level - 1)));
}

IObservable<char>* ExpManager::OnLevelUp()
{
	return &levelUpSubject;
}

/// <summary>
/// 必要経験値の割合
/// </summary>
/// <returns></returns>
float ExpManager::ExpRatio()
{
	return (exp - prevNeedExp) / (needExp - prevNeedExp);
}

int ExpManager::GetLevel()
{
	return level;
}
