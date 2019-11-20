//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#ifndef CPP_RTYPE_2019_TIMER_HPP
#define CPP_RTYPE_2019_TIMER_HPP

#include "IComponent.hpp"

class Timer : public IComponent
{
private:
    float _time;
    float _timeLeft;

public:
    float getTime();
    float getTimeLeft();

    void setTimeLeft(float);
    void setTime(float);

    type_index getId();
};

#endif //CPP_RTYPE_2019_TIMER_HPP
