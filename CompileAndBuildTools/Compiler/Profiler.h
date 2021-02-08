#ifndef TIMER_H
#define TIMER_H
#include <cstdint>
class Timer
{
public:
	Timer()
		: mPCFreq(0)
		, mCounterStart(0)
	{
	}

	void Start();
	double GetCounter();
	void Reset();
	void Show();
private:
	double	mPCFreq;
	int64_t mCounterStart;
};

#endif