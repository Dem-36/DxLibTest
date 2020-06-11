#include "Timer.h"

using namespace std::chrono;

Timer::Timer() noexcept
{
	//�R���X�g���N�^���Ă΂ꂽ�Ƃ��̎��Ԃ��L�^
	last = steady_clock::now();
	limitTime = 1.0f;
	currentTime = 0.0f;
}

Timer::Timer(float limitTime) noexcept
{
	//�R���X�g���N�^���Ă΂ꂽ�Ƃ��̎��Ԃ��L�^
	last = steady_clock::now();
	this->limitTime = limitTime;
	currentTime = 0;
}

//������
void Timer::Initialize() noexcept
{
	currentTime = 0.0f;
}

//�^�C�}�[�̍X�V
void Timer::Update() noexcept
{
	currentTime += Mark();
}

bool Timer::IsTime() noexcept
{
	return currentTime >= limitTime;
}

float Timer::GetCurrentTime() noexcept
{
	return currentTime;
}

//deltaTime
float Timer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float Timer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}
