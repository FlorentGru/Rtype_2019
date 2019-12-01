//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#include <ctime>
#include "Timer.hpp"

Timer::Timer()
{
    _clock.clear();
}

Timer::~Timer()
{
    _clock.clear();
}

std::type_index Timer::getId()
{
    return (std::type_index(typeid(Timer)));
}

void Timer::create_clock(const std::string &key)
{
    std::clock_t news = std::clock();
    _clock.emplace(key, news);
}

bool Timer::restart(const std::string &key, double timeInSecond)
{
    std::clock_t actualTime;
    double duration;

    actualTime = std::clock();
    duration = (actualTime - _clock[key]) / (double) CLOCKS_PER_SEC;
    if (duration > timeInSecond) {
        _clock[key] = std::clock();
        return true;
    }
    return false;
}