//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#ifndef CPP_RTYPE_2019_TIMER_HPP
#define CPP_RTYPE_2019_TIMER_HPP

#include <map>
#include <ctime>
#include "IComponent.hpp"

class Timer : public IComponent
{
private:
    std::map<std::string, std::clock_t> _clock;

public:
    Timer();
    ~Timer();

    void create_clock(const std::string &);

    bool restart(const std::string &, float);

    std::type_index getId() override;
};

#endif //CPP_RTYPE_2019_TIMER_HPP
