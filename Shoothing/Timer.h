#ifndef _TIMER_H_
#define _TIMER_H_

//時間ライブラリ
#include<chrono>

//タイマークラス
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