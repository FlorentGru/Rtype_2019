//
// Created by tfian on 26/11/2019.
//

#include "ClientEcs.hpp"

bool ClientEcs::run(Events _events)
{
    this->events = _events;

    for (auto &system : this->systems) {
        if (!system->run(this->entities, events)) {
            return false;
        }
    }
    return true;
}

const Events& ClientEcs::getEvents() const
{
    return events;
}