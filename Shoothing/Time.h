#ifndef _TIME_H_
#define _TIME_H_

//���ԃ��C�u����
#include<chrono>

//�^�C�}�[�N���X
class Time {
public:
	Time()noexcept;
	Time(float limitTime)noexcept;
	void SetLimitTime(float limitTime)noexcept;
	void Initialize()noexcept;
	void Update()noexcept;
	bool IsTime()noexcept;
	float GetNowTime()noexcept;
	float DeltaTime()noexcept;
	float Peek()const noexcept;
private:
	std::chrono::steady_clock::time_point last;
	float currentTime;
	float limitTime;
};

#endif