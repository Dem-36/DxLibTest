#include "Time.h"

using namespace std::chrono;

Time::Time() noexcept
{
	//�R���X�g���N�^���Ă΂ꂽ�Ƃ��̎��Ԃ��L�^
	last = steady_clock::now();
	limitTime = 1.0f;
	currentTime = 0.0f;
}

Time::Time(float limitTime) noexcept
{
	//�R���X�g���N�^���Ă΂ꂽ�Ƃ��̎��Ԃ��L�^
	last = steady_clock::now();
	this->limitTime = limitTime;
	currentTime = 0;
}

void Time::SetLimitTime(float limitTime) noexcept
{
	this->limitTime = limitTime;
}

//������
void Time::Initialize() noexcept
{
	currentTime = 0.0f;
}

//�^�C�}�[�̍X�V
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
