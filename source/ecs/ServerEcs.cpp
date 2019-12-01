//
// Created by tfian on 25/11/2019.
//

#include "ServerEcs.hpp"

bool ServerEcs::run(Events &events)
{
    for (auto &system : this->systems) {
        if (!system->run(this->entities, events)) {
            return false;
        }
    }
    return true;
}
