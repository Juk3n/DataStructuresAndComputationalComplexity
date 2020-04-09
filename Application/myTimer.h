#ifndef myTimer_H
#define myTimer_H

#include <chrono>

enum class TimeType {
	MICROSECONDS,
	MILLISECONDS,
	SECONDS
};

class myTimer
{
	std::chrono::steady_clock::time_point startTime{};
	std::chrono::steady_clock::time_point stopTime;

public:
	void start();
	void stop();
	long long getTime(TimeType type);
};

#endif myTimer_H