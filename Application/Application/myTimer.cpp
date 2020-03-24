#include "myTimer.h"

void myTimer::start()
{
    startTime = std::chrono::steady_clock::now();
}

void myTimer::stop()
{
    stopTime = std::chrono::steady_clock::now();
}

long long myTimer::getTime(TimeType type)
{
    switch (type) {
    case TimeType::MICROSECONDS:
        return std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();
        break;
    case TimeType::MILLISECONDS:
        return std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime).count();
        break;
    case TimeType::SECONDS:
        return std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime).count();
        break;
    default:
        return std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime).count();
    }
    
}
