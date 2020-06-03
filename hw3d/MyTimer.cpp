#include "MyTimer.h"

MyTimer::MyTimer()
{
	last = std::chrono::steady_clock::now();
}

float MyTimer::Mark()
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - old;
	return frameTime.count();
}

float MyTimer::Peek() const
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}
