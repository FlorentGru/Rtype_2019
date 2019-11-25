//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#include "Timer.hpp"

std::type_index Timer::getId()
{
    return (std::type_index(typeid(Timer)));
}

float Timer::getTime()
{
    return  _time;
}

float Timer::getTimeLeft()
{
    return _timeLeft;
}

void Timer::setTime(float time)
{
    _time = time;
}

void Timer::setTimeLeft(float timeLeft)
{
    _timeLeft = timeLeft;
}