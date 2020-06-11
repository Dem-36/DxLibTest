#ifndef _TIMER_H_
#define _TIMER_H_

//���ԃ��C�u����
#include<chrono>

//�^�C�}�[�N���X
class Timer {
public:
	Timer()noexcept;
	Timer(float limitTime)noexcept;
	void Initialize()noexcept;
	void Update()noexcept;
	bool IsTime()noexcept;
	float GetCurrentTime()noexcept;
	float Mark()noexcept;
	float Peek()const noexcept;
private:
	std::chrono::steady_clock::time_point last;
	float currentTime;
	float limitTime;
};

#endif