#include "Time.h"

using namespace std::chrono;

Time::Time() noexcept
{
	//コンストラクタが呼ばれたときの時間を記録
	last = steady_clock::now();
	limitTime = 1.0f;
	currentTime = 0.0f;
}

Time::Time(float limitTime) noexcept
{
	//コンストラクタが呼ばれたときの時間を記録
	last = steady_clock::now();
	this->limitTime = limitTime;
	currentTime = 0;
}

void Time::SetLimitTime(float limitTime) noexcept
{
	this->limitTime = limitTime;
}

//初期化
void Time::Initialize() noexcept
{
	currentTime = 0.0f;
}

//タイマーの更新
void Time::Update() noexcept
{
	currentTime += DeltaTime();
}

bool Time::IsTime() noexcept
{
	return currentTime >= limitTime;
}

float Time::GetNowTime() noexcept
{
	return currentTime;
}

float Time::GetLimitTime() noexcept
{
	return limitTime;
}

//deltaTime
float Time::DeltaTime() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float Time::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}
