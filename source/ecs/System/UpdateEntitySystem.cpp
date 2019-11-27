//
// Created by $0QU000-PL44DU4VI3C9 on 27/11/2019.
//

#include "UpdateEntitySystem.hpp"


bool UpdateEntitySystem::run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events)
{
    for (size_t i = 0; i < entities.size(); ++i) {
        if (entities[i]->getType() != std::type_index(typeid(Player)))
            moveLeft(entities[i]);
        else
            manageShip(entities[i]);
    }
    return _isSucceed;
}

void UpdateEntitySystem::createFire()
{
    Fire();
}

void UpdateEntitySystem::moveLeft(std::shared_ptr<IEntity>)
{

}

void UpdateEntitySystem::manageShip(std::shared_ptr<IEntity> player)
{

}