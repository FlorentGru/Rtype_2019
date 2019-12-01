//
// Created by tfian on 25/11/2019.
//

#include "System/UpdateEntitySystem.hpp"
#include "CollideSystem.hpp"
#include "ServerEcs.hpp"

bool ServerEcs::run(Events &events)
{
    for (auto &system : this->_systems) {
        if (!system->run(this->_entities, events)) {
            return false;
        }
    }
    return true;
}
