//
// Created by tfian on 26/11/2019.
//

#include "ClientEcs.hpp"

bool ClientEcs::run(Events &_events)
{
    for (auto &system : this->_systems) {
        if (!system->run(this->_entities, _events)) {
            return false;
        }
    }
    return true;
}